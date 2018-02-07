
/**
  ********************************************************************************
  * @file    stm8s_tim3_ClearITPendingBit.c
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
#include "stm8s_tim3.h"
#include "private/stm8s_tim3_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup TIM3_Public_Functions
  * @{
  */

/**
  * @brief  Clears the TIM3's interrupt pending bits.
  * @param   TIM3_IT specifies the pending bit to clear.
  * This parameter can be one of the following values:
  *                       - TIM3_IT_UPDATE: TIM3 update Interrupt source
  *                       - TIM3_IT_CC1: TIM3 Capture Compare 1 Interrupt source
  *                       - TIM3_IT_CC2: TIM3 Capture Compare 2 Interrupt source
  * @retval None.
  */
void TIM3_ClearITPendingBit(TIM3_IT_TypeDef TIM3_IT)
{
  /* Check the parameters */
  assert_param(IS_TIM3_IT_OK(TIM3_IT));
  
  /* Clear the IT pending Bit */
  TIM3->SR1 = (uint8_t)(~TIM3_IT);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
