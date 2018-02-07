
/**
  ********************************************************************************
  * @file    stm8s_tim1_EncoderInterfaceConfig.c
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
  * @brief  Configures the TIM1 Encoder Interface.
  * @param   TIM1_EncoderMode specifies the TIM1 Encoder Mode.
  * This parameter can be one of the following values
  * - TIM1_ENCODERMODE_TI1: Counter counts on TI1FP1 edge
	* depending on TI2FP2 level.
  * - TIM1_ENCODERMODE_TI2: Counter counts on TI2FP2 edge
  *	depending on TI1FP1 level.
  * - TIM1_ENCODERMODE_TI12: Counter counts on both TI1FP1 and
  * TI2FP2 edges depending on the level of the other input.
  * @param   TIM1_IC1Polarity specifies the IC1 Polarity.
  * This parameter can be one of the following values
  *                       - TIM1_ICPOLARITY_FALLING
  *                       - TIM1_ICPOLARITY_RISING
  * @param   TIM1_IC2Polarity specifies the IC2 Polarity.
  * This parameter can be one of the following values
  *                       - TIM1_ICPOLARITY_FALLING
  *                       - TIM1_ICPOLARITY_RISING
  * @retval None
  */
void TIM1_EncoderInterfaceConfig(TIM1_EncoderMode_TypeDef TIM1_EncoderMode,
                                 TIM1_ICPolarity_TypeDef TIM1_IC1Polarity,
                                 TIM1_ICPolarity_TypeDef TIM1_IC2Polarity)
{
  /* Check the parameters */
  assert_param(IS_TIM1_ENCODER_MODE_OK(TIM1_EncoderMode));
  assert_param(IS_TIM1_IC_POLARITY_OK(TIM1_IC1Polarity));
  assert_param(IS_TIM1_IC_POLARITY_OK(TIM1_IC2Polarity));
  
  /* Set the TI1 and the TI2 Polarities */
  if (TIM1_IC1Polarity != TIM1_ICPOLARITY_RISING)
  {
    TIM1->CCER1 |= TIM1_CCER1_CC1P;
  }
  else
  {
    TIM1->CCER1 &= (uint8_t)(~TIM1_CCER1_CC1P);
  }
  
  if (TIM1_IC2Polarity != TIM1_ICPOLARITY_RISING)
  {
    TIM1->CCER1 |= TIM1_CCER1_CC2P;
  }
  else
  {
    TIM1->CCER1 &= (uint8_t)(~TIM1_CCER1_CC2P);
  }
  /* Set the encoder Mode */
  TIM1->SMCR = (uint8_t)((uint8_t)(TIM1->SMCR & (uint8_t)(TIM1_SMCR_MSM | TIM1_SMCR_TS))
                         | (uint8_t) TIM1_EncoderMode);
  
  /* Select the Capture Compare 1 and the Capture Compare 2 as input */
  TIM1->CCMR1 = (uint8_t)((uint8_t)(TIM1->CCMR1 & (uint8_t)(~TIM1_CCMR_CCxS)) 
                          | (uint8_t) CCMR_TIxDirect_Set);
  TIM1->CCMR2 = (uint8_t)((uint8_t)(TIM1->CCMR2 & (uint8_t)(~TIM1_CCMR_CCxS))
                          | (uint8_t) CCMR_TIxDirect_Set);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
