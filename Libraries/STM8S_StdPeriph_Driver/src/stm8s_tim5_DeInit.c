
/**
  ********************************************************************************
  * @file    stm8s_tim5_DeInit.c
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
#include "stm8s_tim5.h"
#include "private/stm8s_tim5_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup TIM5_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the TIM5 peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void TIM5_DeInit(void)
{
  TIM5->CR1 = (uint8_t)TIM5_CR1_RESET_VALUE;
  TIM5->CR2 = TIM5_CR2_RESET_VALUE;
  TIM5->SMCR = TIM5_SMCR_RESET_VALUE;
  TIM5->IER = (uint8_t)TIM5_IER_RESET_VALUE;
  TIM5->SR2 = (uint8_t)TIM5_SR2_RESET_VALUE;
  
  /* Disable channels */
  TIM5->CCER1 = (uint8_t)TIM5_CCER1_RESET_VALUE;
  TIM5->CCER2 = (uint8_t)TIM5_CCER2_RESET_VALUE;
  
  /* Then reset channel registers: it also works if lock level is equal to 2 or 3 */
  TIM5->CCER1 = (uint8_t)TIM5_CCER1_RESET_VALUE;
  TIM5->CCER2 = (uint8_t)TIM5_CCER2_RESET_VALUE;
  TIM5->CCMR1 = (uint8_t)TIM5_CCMR1_RESET_VALUE;
  TIM5->CCMR2 = (uint8_t)TIM5_CCMR2_RESET_VALUE;
  TIM5->CCMR3 = (uint8_t)TIM5_CCMR3_RESET_VALUE;
  TIM5->CNTRH = (uint8_t)TIM5_CNTRH_RESET_VALUE;
  TIM5->CNTRL = (uint8_t)TIM5_CNTRL_RESET_VALUE;
  TIM5->PSCR	= (uint8_t)TIM5_PSCR_RESET_VALUE;
  TIM5->ARRH 	= (uint8_t)TIM5_ARRH_RESET_VALUE;
  TIM5->ARRL 	= (uint8_t)TIM5_ARRL_RESET_VALUE;
  TIM5->CCR1H = (uint8_t)TIM5_CCR1H_RESET_VALUE;
  TIM5->CCR1L = (uint8_t)TIM5_CCR1L_RESET_VALUE;
  TIM5->CCR2H = (uint8_t)TIM5_CCR2H_RESET_VALUE;
  TIM5->CCR2L = (uint8_t)TIM5_CCR2L_RESET_VALUE;
  TIM5->CCR3H = (uint8_t)TIM5_CCR3H_RESET_VALUE;
  TIM5->CCR3L = (uint8_t)TIM5_CCR3L_RESET_VALUE;
  TIM5->SR1 = (uint8_t)TIM5_SR1_RESET_VALUE;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
