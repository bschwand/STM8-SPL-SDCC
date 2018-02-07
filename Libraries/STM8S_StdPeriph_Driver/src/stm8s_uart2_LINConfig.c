
/**
  ********************************************************************************
  * @file    stm8s_uart2_LINConfig.c
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
  * @brief  Configure the UART2 peripheral.
  * @param  UART2_Mode specifies the LIN mode.
  *         This parameter can be any of the @ref UART2_LinMode_TypeDef values.
  * @param  UART2_Autosync specifies the LIN automatic resynchronization mode.
  *         This parameter can be any of the @ref UART2_LinAutosync_TypeDef values.
  * @param  UART2_DivUp specifies the LIN divider update method.
  *         This parameter can be any of the @ref UART2_LinDivUp_TypeDef values.
  * @retval None
  */
void UART2_LINConfig(UART2_LinMode_TypeDef UART2_Mode, 
                     UART2_LinAutosync_TypeDef UART2_Autosync, 
                     UART2_LinDivUp_TypeDef UART2_DivUp)
{
  /* Check parameters */
  assert_param(IS_UART2_SLAVE_OK(UART2_Mode));
  assert_param(IS_UART2_AUTOSYNC_OK(UART2_Autosync));
  assert_param(IS_UART2_DIVUP_OK(UART2_DivUp));
  
  if (UART2_Mode != UART2_LIN_MODE_MASTER)
  {
    UART2->CR6 |=  UART2_CR6_LSLV;
  }
  else
  {
    UART2->CR6 &= ((uint8_t)~UART2_CR6_LSLV);
  }
  
  if (UART2_Autosync != UART2_LIN_AUTOSYNC_DISABLE)
  {
    UART2->CR6 |=  UART2_CR6_LASE ;
  }
  else
  {
    UART2->CR6 &= ((uint8_t)~ UART2_CR6_LASE );
  }
  
  if (UART2_DivUp != UART2_LIN_DIVUP_LBRR1)
  {
    UART2->CR6 |=  UART2_CR6_LDUM;
  }
  else
  {
    UART2->CR6 &= ((uint8_t)~ UART2_CR6_LDUM);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
