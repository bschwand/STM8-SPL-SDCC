
/**
  ********************************************************************************
  * @file    stm8s_uart3_LINConfig.c
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
#include "stm8s_uart3.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup UART3_Public_Functions
  * @{
  */

/**
  * @brief  Configure the UART3 peripheral.
  * @param  UART3_Mode specifies the LIN mode.
  *         This parameter can be any of the @ref UART3_LinMode_TypeDef values.
  * @param  UART3_Autosync specifies the LIN automatic resynchronization mode.
  *         This parameter can be any of the @ref UART3_LinAutosync_TypeDef values.
  * @param  UART3_DivUp specifies the LIN divider update method.
  *         This parameter can be any of the @ref UART3_LinDivUp_TypeDef values.
  * @retval None
  */
void UART3_LINConfig(UART3_LinMode_TypeDef UART3_Mode,
                     UART3_LinAutosync_TypeDef UART3_Autosync, 
                     UART3_LinDivUp_TypeDef UART3_DivUp)
{
  /* Check the parameters */
  assert_param(IS_UART3_SLAVE_OK(UART3_Mode));
  assert_param(IS_UART3_AUTOSYNC_OK(UART3_Autosync));
  assert_param(IS_UART3_DIVUP_OK(UART3_DivUp));
  
  if (UART3_Mode != UART3_LIN_MODE_MASTER)
  {
    UART3->CR6 |=  UART3_CR6_LSLV;
  }
  else
  {
    UART3->CR6 &= ((uint8_t)~UART3_CR6_LSLV);
  }
  
  if (UART3_Autosync != UART3_LIN_AUTOSYNC_DISABLE)
  {
    UART3->CR6 |=  UART3_CR6_LASE ;
  }
  else
  {
    UART3->CR6 &= ((uint8_t)~ UART3_CR6_LASE );
  }
  
  if (UART3_DivUp != UART3_LIN_DIVUP_LBRR1)
  {
    UART3->CR6 |=  UART3_CR6_LDUM;
  }
  else
  {
    UART3->CR6 &= ((uint8_t)~ UART3_CR6_LDUM);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
