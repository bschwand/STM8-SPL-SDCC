
/**
  ********************************************************************************
  * @file    stm8s_uart1_WakeUpConfig.c
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
#include "stm8s_uart1.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup UART1_Public_Functions
  * @{
  */

/**
  * @brief  Selects the UART1 WakeUp method.
  * @param  UART1_WakeUp: specifies the UART1 wakeup method.
  *         This parameter can be any of the @ref UART1_WakeUp_TypeDef values.
  * @retval None
  */
void UART1_WakeUpConfig(UART1_WakeUp_TypeDef UART1_WakeUp)
{
  assert_param(IS_UART1_WAKEUP_OK(UART1_WakeUp));
  
  UART1->CR1 &= ((uint8_t)~UART1_CR1_WAKE);
  UART1->CR1 |= (uint8_t)UART1_WakeUp;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
