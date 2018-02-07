
/**
  ********************************************************************************
  * @file    stm8s_tim3_private.c
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
  * @addtogroup TIM3_Private_Functions
  * @{
  */

/**
  * @brief  Configure the TI1 as Input.
  * @param   TIM3_ICPolarity  The Input Polarity.
  * This parameter can be one of the following values:
  *                       - TIM3_ICPOLARITY_FALLING
  *                       - TIM3_ICPOLARITY_RISING
  * @param   TIM3_ICSelection specifies the input to be used.
  * This parameter can be one of the following values:
  *                       - TIM3_ICSELECTION_DIRECTTI: TIM3 Input 1 is selected to
  *                         be connected to IC1.
  *                       - TIM3_ICSELECTION_INDIRECTTI: TIM3 Input 1 is selected to
  *                         be connected to IC2.
  * @param   TIM3_ICFilter Specifies the Input Capture Filter.
  * This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
void TIM3_TI1_Config(uint8_t TIM3_ICPolarity,
                     uint8_t TIM3_ICSelection,
                     uint8_t TIM3_ICFilter)
{
  /* Disable the Channel 1: Reset the CCE Bit */
  TIM3->CCER1 &= (uint8_t)(~TIM3_CCER1_CC1E);
  
  /* Select the Input and set the filter */
  TIM3->CCMR1 = (uint8_t)((uint8_t)(TIM3->CCMR1 & (uint8_t)(~( TIM3_CCMR_CCxS | TIM3_CCMR_ICxF))) | (uint8_t)(( (TIM3_ICSelection)) | ((uint8_t)( TIM3_ICFilter << 4))));
  
  /* Select the Polarity */
  if (TIM3_ICPolarity != TIM3_ICPOLARITY_RISING)
  {
    TIM3->CCER1 |= TIM3_CCER1_CC1P;
  }
  else
  {
    TIM3->CCER1 &= (uint8_t)(~TIM3_CCER1_CC1P);
  }
  /* Set the CCE Bit */
  TIM3->CCER1 |= TIM3_CCER1_CC1E;
}

/**
  * @brief  Configure the TI2 as Input.
  * @param   TIM3_ICPolarity  The Input Polarity.
  * This parameter can be one of the following values:
  *                       - TIM3_ICPOLARITY_FALLING
  *                       - TIM3_ICPOLARITY_RISING
  * @param   TIM3_ICSelection specifies the input to be used.
  * This parameter can be one of the following values:
  *                       - TIM3_ICSELECTION_DIRECTTI: TIM3 Input 2 is selected to
  *                         be connected to IC2.
  *                       - TIM3_ICSELECTION_INDIRECTTI: TIM3 Input 2 is selected to
  *                         be connected to IC1.
  * @param   TIM3_ICFilter Specifies the Input Capture Filter.
  * This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
void TIM3_TI2_Config(uint8_t TIM3_ICPolarity,
                     uint8_t TIM3_ICSelection,
                     uint8_t TIM3_ICFilter)
{
  /* Disable the Channel 2: Reset the CCE Bit */
  TIM3->CCER1 &=  (uint8_t)(~TIM3_CCER1_CC2E);
  
  /* Select the Input and set the filter */
  TIM3->CCMR2 = (uint8_t)((uint8_t)(TIM3->CCMR2 & (uint8_t)(~( TIM3_CCMR_CCxS |
                                                              TIM3_CCMR_ICxF    ))) | (uint8_t)(( (TIM3_ICSelection)) | 
                                                                                                ((uint8_t)( TIM3_ICFilter << 4))));
  
  /* Select the Polarity */
  if (TIM3_ICPolarity != TIM3_ICPOLARITY_RISING)
  {
    TIM3->CCER1 |= TIM3_CCER1_CC2P;
  }
  else
  {
    TIM3->CCER1 &= (uint8_t)(~TIM3_CCER1_CC2P);
  }
  
  /* Set the CCE Bit */
  TIM3->CCER1 |= TIM3_CCER1_CC2E;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
