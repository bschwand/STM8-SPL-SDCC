
/**
  ********************************************************************************
  * @file    stm8s_tim6_DeInit.c
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
#include "stm8s_tim6.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup TIM6_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the TIM6 peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void TIM6_DeInit(void)
{
  TIM6->CR1 	= TIM6_CR1_RESET_VALUE;
  TIM6->CR2 	= TIM6_CR2_RESET_VALUE;
  TIM6->SMCR 	= TIM6_SMCR_RESET_VALUE;
  TIM6->IER 	= TIM6_IER_RESET_VALUE;
  TIM6->CNTR 	= TIM6_CNTR_RESET_VALUE;
  TIM6->PSCR	= TIM6_PSCR_RESET_VALUE;
  TIM6->ARR 	= TIM6_ARR_RESET_VALUE;
  TIM6->SR1 	= TIM6_SR1_RESET_VALUE;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
