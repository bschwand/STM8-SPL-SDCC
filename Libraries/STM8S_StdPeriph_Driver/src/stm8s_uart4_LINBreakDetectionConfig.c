
/**
  ********************************************************************************
  * @file    stm8s_uart4_LINBreakDetectionConfig.c
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
#include "stm8s_uart4.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup UART4_Public_Functions
  * @{
  */

/**
  * @brief  Sets the UART4 LIN Break detection length.
  * @param  UART4_LINBreakDetectionLength specifies the LIN break detection length.
  *         This parameter can be any of the 
  *         @ref UART4_LINBreakDetectionLength_TypeDef values.
  * @retval None
  */
void UART4_LINBreakDetectionConfig(UART4_LINBreakDetectionLength_TypeDef UART4_LINBreakDetectionLength)
{
  /* Check parameters */    
  assert_param(IS_UART4_LINBREAKDETECTIONLENGTH_OK(UART4_LINBreakDetectionLength));
  
  if(UART4_LINBreakDetectionLength != UART4_LINBREAKDETECTIONLENGTH_10BITS)
  {
    UART4->CR4 |= UART4_CR4_LBDL;
  }
  else
  {
    UART4->CR4 &= ((uint8_t)~UART4_CR4_LBDL);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
