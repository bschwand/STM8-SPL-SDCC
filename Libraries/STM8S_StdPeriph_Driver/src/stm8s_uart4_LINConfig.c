
/**
  ********************************************************************************
  * @file    stm8s_uart4_LINConfig.c
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
  * @brief  Configure the UART4 peripheral.
  * @param  UART4_Mode specifies the LIN mode.
  *         This parameter can be any of the @ref UART4_LinMode_TypeDef values.
  * @param  UART4_Autosync specifies the LIN automatic resynchronization mode.
  *         This parameter can be any of the @ref UART4_LinAutosync_TypeDef values.
  * @param  UART4_DivUp specifies the LIN divider update method.
  *         This parameter can be any of the @ref UART4_LinDivUp_TypeDef values.
  * @retval None
  */
void UART4_LINConfig(UART4_LinMode_TypeDef UART4_Mode, 
                     UART4_LinAutosync_TypeDef UART4_Autosync, 
                     UART4_LinDivUp_TypeDef UART4_DivUp)
{
  /* Check parameters */
  assert_param(IS_UART4_SLAVE_OK(UART4_Mode));
  assert_param(IS_UART4_AUTOSYNC_OK(UART4_Autosync));
  assert_param(IS_UART4_DIVUP_OK(UART4_DivUp));
  
  if(UART4_Mode != UART4_LIN_MODE_MASTER)
  {
    UART4->CR6 |=  UART4_CR6_LSLV;
  }
  else
  {
    UART4->CR6 &= ((uint8_t)~UART4_CR6_LSLV);
  }
  
  if(UART4_Autosync != UART4_LIN_AUTOSYNC_DISABLE)
  {
    UART4->CR6 |=  UART4_CR6_LASE ;
  }
  else
  {
    UART4->CR6 &= ((uint8_t)~ UART4_CR6_LASE );
  }
  
  if(UART4_DivUp != UART4_LIN_DIVUP_LBRR1)
  {
    UART4->CR6 |=  UART4_CR6_LDUM;
  }
  else
  {
    UART4->CR6 &= ((uint8_t)~ UART4_CR6_LDUM);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
