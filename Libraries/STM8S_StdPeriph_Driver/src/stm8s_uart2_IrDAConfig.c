
/**
  ********************************************************************************
  * @file    stm8s_uart2_IrDAConfig.c
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
#include "stm8s_uart2.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup UART2_Public_Functions
  * @{
  */

/**
  * @brief  Configures the UART2’s IrDA interface.
  * @param  UART2_IrDAMode specifies the IrDA mode.
  *         This parameter can be any of the @ref UART2_IrDAMode_TypeDef values.
  * @retval None
  */
void UART2_IrDAConfig(UART2_IrDAMode_TypeDef UART2_IrDAMode)
{
  assert_param(IS_UART2_IRDAMODE_OK(UART2_IrDAMode));
  
  if (UART2_IrDAMode != UART2_IRDAMODE_NORMAL)
  {
    UART2->CR5 |= UART2_CR5_IRLP;
  }
  else
  {
    UART2->CR5 &= ((uint8_t)~UART2_CR5_IRLP);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
