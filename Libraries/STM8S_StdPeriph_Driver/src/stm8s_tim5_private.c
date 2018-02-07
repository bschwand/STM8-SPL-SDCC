
/**
  ********************************************************************************
  * @file    stm8s_tim5_private.c
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

/**
  * @brief  Configure the TI1 as Input.
  * @param   TIM5_ICPolarity  The Input Polarity.
  * This parameter can be one of the following values:
  *                       - TIM5_ICPOLARITY_FALLING
  *                       - TIM5_ICPOLARITY_RISING
  * @param   TIM5_ICSelection specifies the input to be used.
  * This parameter can be one of the following values:
  *                       - TIM5_ICSELECTION_DIRECTTI: TIM5 Input 1 is selected to
  *                         be connected to IC1.
  *                       - TIM5_ICSELECTION_INDIRECTTI: TIM5 Input 1 is selected to
  *                         be connected to IC2.
  * @param   TIM5_ICFilter Specifies the Input Capture Filter.
  * This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
void TI1_Config(uint8_t TIM5_ICPolarity,
                uint8_t TIM5_ICSelection,
                uint8_t TIM5_ICFilter)
{
  /* Disable the Channel 1: Reset the CCE Bit */
  TIM5->CCER1 &= (uint8_t)(~TIM5_CCER1_CC1E);
  
  /* Select the Input and set the filter */
  TIM5->CCMR1  = (uint8_t)((uint8_t)(TIM5->CCMR1 & (uint8_t)(~( TIM5_CCMR_CCxS | TIM5_CCMR_ICxF )))
                           | (uint8_t)(( (TIM5_ICSelection)) | ((uint8_t)( TIM5_ICFilter << 4))));
  
  /* Select the Polarity */
  if (TIM5_ICPolarity != TIM5_ICPOLARITY_RISING)
  {
    TIM5->CCER1 |= TIM5_CCER1_CC1P ;
  }
  else
  {
    TIM5->CCER1 &= (uint8_t)(~TIM5_CCER1_CC1P) ;
  }
  /* Set the CCE Bit */
  TIM5->CCER1 |=  TIM5_CCER1_CC1E;
}

/**
  * @brief  Configure the TI2 as Input.
  * @param   TIM5_ICPolarity  The Input Polarity.
  * This parameter can be one of the following values:
  *                       - TIM5_ICPOLARITY_FALLING
  *                       - TIM5_ICPOLARITY_RISING
  * @param   TIM5_ICSelection specifies the input to be used.
  * This parameter can be one of the following values:
  *                       - TIM5_ICSELECTION_DIRECTTI: TIM5 Input 2 is selected to
  *                         be connected to IC2.
  *                       - TIM5_ICSELECTION_INDIRECTTI: TIM5 Input 2 is selected to
  *                         be connected to IC1.
  * @param   TIM5_ICFilter Specifies the Input Capture Filter.
  * This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
void TI2_Config(uint8_t TIM5_ICPolarity,
                uint8_t TIM5_ICSelection,
                uint8_t TIM5_ICFilter)
{
  /* Disable the Channel 2: Reset the CCE Bit */
  TIM5->CCER1 &=  (uint8_t)(~TIM5_CCER1_CC2E);
  
  /* Select the Input and set the filter */
  TIM5->CCMR2  = (uint8_t)((uint8_t)(TIM5->CCMR2 & (uint8_t)(~( TIM5_CCMR_CCxS | TIM5_CCMR_ICxF)))
                           | (uint8_t)(( (TIM5_ICSelection)) | ((uint8_t)( TIM5_ICFilter << 4))));
  
  
  /* Select the Polarity */
  if (TIM5_ICPolarity != TIM5_ICPOLARITY_RISING)
  {
    TIM5->CCER1 |= TIM5_CCER1_CC2P ;
  }
  else
  {
    TIM5->CCER1 &= (uint8_t)(~TIM5_CCER1_CC2P) ;
  }
  
  /* Set the CCE Bit */
  TIM5->CCER1 |=  TIM5_CCER1_CC2E;
}

/**
  * @brief  Configure the TI3 as Input.
  * @param   TIM5_ICPolarity  The Input Polarity.
  * This parameter can be one of the following values:
  *                       - TIM5_ICPOLARITY_FALLING
  *                       - TIM5_ICPOLARITY_RISING
  * @param   TIM5_ICSelection specifies the input to be used.
  * This parameter can be one of the following values:
  *                       - TIM5_ICSELECTION_DIRECTTI: TIM5 Input 3 is selected to
  *                         be connected to IC3.
  * @param   TIM5_ICFilter Specifies the Input Capture Filter.
  * This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
void TI3_Config(uint8_t TIM5_ICPolarity, uint8_t TIM5_ICSelection,
                uint8_t TIM5_ICFilter)
{
  /* Disable the Channel 3: Reset the CCE Bit */
  TIM5->CCER2 &=  (uint8_t)(~TIM5_CCER2_CC3E);
  
  /* Select the Input and set the filter */
  TIM5->CCMR3 = (uint8_t)((uint8_t)(TIM5->CCMR3 & (uint8_t)(~( TIM5_CCMR_CCxS | TIM5_CCMR_ICxF))) 
                          | (uint8_t)(( (TIM5_ICSelection)) | ((uint8_t)( TIM5_ICFilter << 4))));
  
  
  /* Select the Polarity */
  if (TIM5_ICPolarity != TIM5_ICPOLARITY_RISING)
  {
    TIM5->CCER2 |= TIM5_CCER2_CC3P ;
  }
  else
  {
    TIM5->CCER2 &= (uint8_t)(~TIM5_CCER2_CC3P) ;
  }
  /* Set the CCE Bit */
  TIM5->CCER2 |=  TIM5_CCER2_CC3E;
}

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
