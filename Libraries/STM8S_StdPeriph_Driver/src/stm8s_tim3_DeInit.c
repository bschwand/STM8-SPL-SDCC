
/**
  ********************************************************************************
  * @file    stm8s_tim3_DeInit.c
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
  * @brief  Deinitializes the TIM3 peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void TIM3_DeInit(void)
{
  TIM3->CR1 = (uint8_t)TIM3_CR1_RESET_VALUE;
  TIM3->IER = (uint8_t)TIM3_IER_RESET_VALUE;
  TIM3->SR2 = (uint8_t)TIM3_SR2_RESET_VALUE;
  
  /* Disable channels */
  TIM3->CCER1 = (uint8_t)TIM3_CCER1_RESET_VALUE;
  
  /* Then reset channel registers: it also works if lock level is equal to 2 or 3 */
  TIM3->CCER1 = (uint8_t)TIM3_CCER1_RESET_VALUE;
  TIM3->CCMR1 = (uint8_t)TIM3_CCMR1_RESET_VALUE;
  TIM3->CCMR2 = (uint8_t)TIM3_CCMR2_RESET_VALUE;
  TIM3->CNTRH = (uint8_t)TIM3_CNTRH_RESET_VALUE;
  TIM3->CNTRL = (uint8_t)TIM3_CNTRL_RESET_VALUE;
  TIM3->PSCR = (uint8_t)TIM3_PSCR_RESET_VALUE;
  TIM3->ARRH  = (uint8_t)TIM3_ARRH_RESET_VALUE;
  TIM3->ARRL  = (uint8_t)TIM3_ARRL_RESET_VALUE;
  TIM3->CCR1H = (uint8_t)TIM3_CCR1H_RESET_VALUE;
  TIM3->CCR1L = (uint8_t)TIM3_CCR1L_RESET_VALUE;
  TIM3->CCR2H = (uint8_t)TIM3_CCR2H_RESET_VALUE;
  TIM3->CCR2L = (uint8_t)TIM3_CCR2L_RESET_VALUE;
  TIM3->SR1 = (uint8_t)TIM3_SR1_RESET_VALUE;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
