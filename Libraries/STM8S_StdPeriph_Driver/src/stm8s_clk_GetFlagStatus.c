
/**
  ********************************************************************************
  * @file    stm8s_clk_GetFlagStatus.c
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
#include "stm8s_clk.h"
#include "private/stm8s_clk_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup CLK_Public_Functions
  * @{
  */

/**
  * @brief  Checks whether the specified CLK flag is set or not.
  * @par Full description:
  * @param   CLK_FLAG Flag to check.
  * can be one of the values of @ref CLK_Flag_TypeDef
  * @retval FlagStatus, status of the checked flag
  */
FlagStatus CLK_GetFlagStatus(CLK_Flag_TypeDef CLK_FLAG)
{
  uint16_t statusreg = 0;
  uint8_t tmpreg = 0;
  FlagStatus bitstatus = RESET;
  
  /* check the parameters */
  assert_param(IS_CLK_FLAG_OK(CLK_FLAG));
  
  /* Get the CLK register index */
  statusreg = (uint16_t)((uint16_t)CLK_FLAG & (uint16_t)0xFF00);
  
  
  if (statusreg == 0x0100) /* The flag to check is in ICKRregister */
  {
    tmpreg = CLK->ICKR;
  }
  else if (statusreg == 0x0200) /* The flag to check is in ECKRregister */
  {
    tmpreg = CLK->ECKR;
  }
  else if (statusreg == 0x0300) /* The flag to check is in SWIC register */
  {
    tmpreg = CLK->SWCR;
  }
  else if (statusreg == 0x0400) /* The flag to check is in CSS register */
  {
    tmpreg = CLK->CSSR;
  }
  else /* The flag to check is in CCO register */
  {
    tmpreg = CLK->CCOR;
  }
  
  if ((tmpreg & (uint8_t)CLK_FLAG) != (uint8_t)RESET)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  
  /* Return the flag status */
  return((FlagStatus)bitstatus);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
