
/**
  ********************************************************************************
  * @file    stm8s_flash_ReadOptionByte.c
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
#include "stm8s_flash.h"
#include "private/stm8s_flash_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup FLASH_Public_Functions
  * @{
  */

/**
  * @brief  Reads one option byte
  * @param  Address  option byte address to read.
  * @retval Option byte read value + its complement
  */
uint16_t FLASH_ReadOptionByte(uint16_t Address)
{
  uint8_t value_optbyte, value_optbyte_complement = 0;
  uint16_t res_value = 0;
  
  /* Check parameter */
  assert_param(IS_OPTION_BYTE_ADDRESS_OK(Address));
    
  value_optbyte = *((NEAR uint8_t*)Address); /* Read option byte */
  value_optbyte_complement = *(((NEAR uint8_t*)Address) + 1); /* Read option byte complement */
  
  /* Read-out protection option byte */
  if(Address == 0x4800)	 
  {
    res_value =	 value_optbyte;
  }
  else
  {
    if(value_optbyte == (uint8_t)(~value_optbyte_complement))
    {
      res_value = (uint16_t)((uint16_t)value_optbyte << 8);
      res_value = res_value | (uint16_t)value_optbyte_complement;
    }
    else
    {
      res_value = FLASH_OPTIONBYTE_ERROR;
    }
  }
  return(res_value);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
