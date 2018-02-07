
/**
  ********************************************************************************
  * @file    stm8s_tim5_EncoderInterfaceConfig.c
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
  * @brief  Configures the TIM5 Encoder Interface.
  * @param   TIM5_EncoderMode : Specifies the TIM5 Encoder Mode.
  * This parameter can be one of the @ref TIM5_EncoderMode_TypeDef enumeration.
  * @param   TIM5_IC1Polarity : Specifies the IC1 Polarity.
  * This parameter can be one of the @ref TIM5_ICPolarity_TypeDef enumeration.
  * @param   TIM5_IC2Polarity : Specifies the IC2 Polarity.
  * This parameter can be one of the @ref TIM5_ICPolarity_TypeDef enumeration.
  * @retval None
  */
void TIM5_EncoderInterfaceConfig(TIM5_EncoderMode_TypeDef TIM5_EncoderMode,
                                 TIM5_ICPolarity_TypeDef TIM5_IC1Polarity,
                                 TIM5_ICPolarity_TypeDef TIM5_IC2Polarity)
{
  uint8_t tmpsmcr = 0;
  uint8_t tmpccmr1 = 0;
  uint8_t tmpccmr2 = 0;
  
  /* Check the parameters */
  assert_param(IS_TIM5_ENCODER_MODE_OK(TIM5_EncoderMode));
  assert_param(IS_TIM5_IC_POLARITY_OK(TIM5_IC1Polarity));
  assert_param(IS_TIM5_IC_POLARITY_OK(TIM5_IC2Polarity));
  
  tmpsmcr = TIM5->SMCR;
  tmpccmr1 = TIM5->CCMR1;
  tmpccmr2 = TIM5->CCMR2;
  
  /* Set the encoder Mode */
  tmpsmcr &= (uint8_t)(TIM5_SMCR_MSM | TIM5_SMCR_TS)  ;
  tmpsmcr |= (uint8_t)TIM5_EncoderMode;
  
  /* Select the Capture Compare 1 and the Capture Compare 2 as input */
  tmpccmr1 &= (uint8_t)(~TIM5_CCMR_CCxS);
  tmpccmr2 &= (uint8_t)(~TIM5_CCMR_CCxS);
  tmpccmr1 |= TIM5_CCMR_TIxDirect_Set;
  tmpccmr2 |= TIM5_CCMR_TIxDirect_Set;
  
  /* Set the TI1 and the TI2 Polarities */
  if (TIM5_IC1Polarity == TIM5_ICPOLARITY_FALLING)
  {
    TIM5->CCER1 |= TIM5_CCER1_CC1P ;
  }
  else
  {
    TIM5->CCER1 &= (uint8_t)(~TIM5_CCER1_CC1P) ;
  }
  
  if (TIM5_IC2Polarity == TIM5_ICPOLARITY_FALLING)
  {
    TIM5->CCER1 |= TIM5_CCER1_CC2P ;
  }
  else
  {
    TIM5->CCER1 &= (uint8_t)(~TIM5_CCER1_CC2P) ;
  }
  
  TIM5->SMCR = tmpsmcr;
  TIM5->CCMR1 = tmpccmr1;
  TIM5->CCMR2 = tmpccmr2;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
