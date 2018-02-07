
/**
  ********************************************************************************
  * @file    stm8s_tim1_SetIC2Prescaler.c
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
#include "stm8s_tim1.h"
#include "private/stm8s_tim1_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup TIM1_Public_Functions
  * @{
  */

/**
  * @brief  Sets the TIM1 Input Capture 2 prescaler.
  * @param   TIM1_IC2Prescaler specifies the Input Capture prescaler new value
  * This parameter can be one of the following values:
  *                       - TIM1_ICPSC_DIV1: no prescaler
  *                       - TIM1_ICPSC_DIV2: capture is done once every 2 events
  *                       - TIM1_ICPSC_DIV4: capture is done once every 4 events
  *                       - TIM1_ICPSC_DIV8: capture is done once every 8 events
  * @retval None
  */
void TIM1_SetIC2Prescaler(TIM1_ICPSC_TypeDef TIM1_IC2Prescaler)
{
  
  /* Check the parameters */
  assert_param(IS_TIM1_IC_PRESCALER_OK(TIM1_IC2Prescaler));
  
  /* Reset the IC1PSC Bits */ /* Set the IC1PSC value */
  TIM1->CCMR2 = (uint8_t)((uint8_t)(TIM1->CCMR2 & (uint8_t)(~TIM1_CCMR_ICxPSC))
                          | (uint8_t)TIM1_IC2Prescaler);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
