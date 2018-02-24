#!/usr/bin/perl
# Author: B.Schwander, Feb. 2018
#
# Helper script to split SPL c files into one file per function.
# This script will break if the format is not exactly the format followed in the
# original STM8S SPL, as we match the doxygen tag and positions and expect them
# to be exactly within the same place, spaces, etc.
# header and footer are copies of the original headers and footer
#
# just using this file is not enough !
# - the generated files can have some issues, like multiple functions
# - the types and variable definitions private to each C file should be moved to
#   a stm8X_XXX_private.h , resp. stm8_X_XXX_private.c
# - every file shall be reviewed and checked that no function is missing
{
    my $footer = <<'FOOTER';
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
FOOTER

    my $header = <<'HEADER';

/**
  ********************************************************************************
  * @file    C_FILENAME
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains all the functions for the UART1 peripheral.
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "HEADER_FILENAME"
#include "PRIVATE_HEADER"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup TEMPLATE_Public_Functions
  * @{
  */

HEADER

    local $/ = undef;
    @chunks = split(/^(?=\/\*\*\n  \* \@brief)/m, <>);


    # find which peripheral this file is about
    @peripheral = $chunks[0] =~ /(^  \* \@file *stm8s_(.*)\.c)/m;

    $lperiph = $peripheral[1];
    $periph = uc $lperiph . '_';
    $perip = uc $lperiph;

    $qperiph = quotemeta $periph;
    #print "--------------------8<-------------------------------------\n";
    #print $chunks[1];
    #print "--------------------8<-------------------------------------\n";

    $filename_private = "stm8s_" . $lperiph . '_private.c';
    #print $filename_private . "\n";

    $do_header = 1;
    $done_private = 1;
    for($i = 1; $i <= $#chunks; $i++){
        #print "--------------------8<-------------------------------------\n";
        @functionname = $chunks[$i] =~ /^(\w+) ($periph)([A-Za-z0-9_]+)\(/m;
        #print $functionname[2] ."\n";
        #print @functionname ;
        if($functionname[2]){
          $do_header = 1;
          $do_footer = 1;
          $filename = "stm8s_" . $lperiph . "_$functionname[2].c";
        } else {
          if($done_private){
            $do_header = 1;
          } else {
            $do_header = 0;
          }
          $done_private--;
          $do_footer = 0;
          $filename = $filename_private;
        }
        print $filename . "\n";
        $header_filename = "stm8s_" . $lperiph . '.h';
        #print $header_filename . "\n";;
        $private_header = "private/stm8s_" . $lperiph . '_private.h';
        #print $private_header . "\n";

        ($header_ = $header ) =~ s/C_FILENAME/$filename/gm;
        ($header_ = $header_ ) =~ s/HEADER_FILENAME/$header_filename/gm;
        ($header_ = $header_ ) =~ s/PRIVATE_HEADER/$private_header/gm;
        ($header_ = $header_ ) =~ s/TEMPLATE/$perip/gm;

        open(FILE, ">> $filename");
        #print $header_;
        #print $chunks[$i];
        #print $footer;
        if($do_header){
            print FILE $header_;
        }
        print FILE $chunks[$i];
        if($do_footer){
          print FILE $footer;
        }
        #print "-------------------->8-------------------------------------\n";
    }
    if($done_private <= 0){
      open(FILE, ">> $filename_private");
      print FILE $footer;
    }
}
