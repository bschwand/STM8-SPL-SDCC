
/**
  ********************************************************************************
  * @file    stm8s_tim1_private.c
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
  * @addtogroup TIM1_Private_Functions
  * @{
  */

/**
  * @brief  Configure the TI1 as Input.
  * @param  TIM1_ICPolarity  The Input Polarity.
  *         This parameter can be one of the following values:
  *                       - TIM1_ICPOLARITY_FALLING
  *                       - TIM1_ICPOLARITY_RISING
  * @param  TIM1_ICSelection specifies the input to be used.
  *         This parameter can be one of the following values:
  *                       - TIM1_ICSELECTION_DIRECTTI: TIM1 Input 1 is selected to
  *                         be connected to IC1.
  *                       - TIM1_ICSELECTION_INDIRECTTI: TIM1 Input 1 is selected to
  *                         be connected to IC2.
  * @param  TIM1_ICFilter Specifies the Input Capture Filter.
  *         This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
void TIM1_TI1_Config(uint8_t TIM1_ICPolarity,
                     uint8_t TIM1_ICSelection,
                     uint8_t TIM1_ICFilter)
{
  /* Disable the Channel 1: Reset the CCE Bit */
  TIM1->CCER1 &= (uint8_t)(~TIM1_CCER1_CC1E);
  
  /* Select the Input and set the filter */
  TIM1->CCMR1 = (uint8_t)((uint8_t)(TIM1->CCMR1 & (uint8_t)(~(uint8_t)( TIM1_CCMR_CCxS | TIM1_CCMR_ICxF ))) | 
                          (uint8_t)(( (TIM1_ICSelection)) | ((uint8_t)( TIM1_ICFilter << 4))));
  
  /* Select the Polarity */
  if (TIM1_ICPolarity != TIM1_ICPOLARITY_RISING)
  {
    TIM1->CCER1 |= TIM1_CCER1_CC1P;
  }
  else
  {
    TIM1->CCER1 &= (uint8_t)(~TIM1_CCER1_CC1P);
  }
  
  /* Set the CCE Bit */
  TIM1->CCER1 |=  TIM1_CCER1_CC1E;
}

/**
  * @brief  Configure the TI2 as Input.
  * @param  TIM1_ICPolarity  The Input Polarity.
  *         This parameter can be one of the following values:
  *                       - TIM1_ICPOLARITY_FALLING
  *                       - TIM1_ICPOLARITY_RISING
  * @param  TIM1_ICSelection specifies the input to be used.
  *         This parameter can be one of the following values:
  *                       - TIM1_ICSELECTION_DIRECTTI: TIM1 Input 2 is selected to
  *                         be connected to IC2.
  *                       - TIM1_ICSELECTION_INDIRECTTI: TIM1 Input 2 is selected to
  *                         be connected to IC1.
  * @param  TIM1_ICFilter Specifies the Input Capture Filter.
  *         This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
void TIM1_TI2_Config(uint8_t TIM1_ICPolarity,
                     uint8_t TIM1_ICSelection,
                     uint8_t TIM1_ICFilter)
{
  /* Disable the Channel 2: Reset the CCE Bit */
  TIM1->CCER1 &=  (uint8_t)(~TIM1_CCER1_CC2E);
  
  /* Select the Input and set the filter */
  TIM1->CCMR2  = (uint8_t)((uint8_t)(TIM1->CCMR2 & (uint8_t)(~(uint8_t)( TIM1_CCMR_CCxS | TIM1_CCMR_ICxF ))) 
                           | (uint8_t)(( (TIM1_ICSelection)) | ((uint8_t)( TIM1_ICFilter << 4))));
  /* Select the Polarity */
  if (TIM1_ICPolarity != TIM1_ICPOLARITY_RISING)
  {
    TIM1->CCER1 |= TIM1_CCER1_CC2P;
  }
  else
  {
    TIM1->CCER1 &= (uint8_t)(~TIM1_CCER1_CC2P);
  }
  /* Set the CCE Bit */
  TIM1->CCER1 |=  TIM1_CCER1_CC2E;
}

/**
  * @brief  Configure the TI3 as Input.
  * @param  TIM1_ICPolarity  The Input Polarity.
  *         This parameter can be one of the following values:
  *                       - TIM1_ICPOLARITY_FALLING
  *                       - TIM1_ICPOLARITY_RISING
  * @param  TIM1_ICSelection specifies the input to be used.
  *         This parameter can be one of the following values:
  *                       - TIM1_ICSELECTION_DIRECTTI: TIM1 Input 3 is selected to
  *                         be connected to IC3.
  *                       - TIM1_ICSELECTION_INDIRECTTI: TIM1 Input 3 is selected to
  *                         be connected to IC4.
  * @param  TIM1_ICFilter Specifies the Input Capture Filter.
  *         This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
void TIM1_TI3_Config(uint8_t TIM1_ICPolarity,
                     uint8_t TIM1_ICSelection,
                     uint8_t TIM1_ICFilter)
{
  /* Disable the Channel 3: Reset the CCE Bit */
  TIM1->CCER2 &=  (uint8_t)(~TIM1_CCER2_CC3E);
  
  /* Select the Input and set the filter */
  TIM1->CCMR3 = (uint8_t)((uint8_t)(TIM1->CCMR3 & (uint8_t)(~(uint8_t)( TIM1_CCMR_CCxS | TIM1_CCMR_ICxF))) 
                          | (uint8_t)(( (TIM1_ICSelection)) | ((uint8_t)( TIM1_ICFilter << 4))));
  
  /* Select the Polarity */
  if (TIM1_ICPolarity != TIM1_ICPOLARITY_RISING)
  {
    TIM1->CCER2 |= TIM1_CCER2_CC3P;
  }
  else
  {
    TIM1->CCER2 &= (uint8_t)(~TIM1_CCER2_CC3P);
  }
  /* Set the CCE Bit */
  TIM1->CCER2 |=  TIM1_CCER2_CC3E;
}

/**
  * @brief  Configure the TI4 as Input.
  * @param  TIM1_ICPolarity  The Input Polarity.
  *         This parameter can be one of the following values:
  *                       - TIM1_ICPOLARITY_FALLING
  *                       - TIM1_ICPOLARITY_RISING
  * @param  TIM1_ICSelection specifies the input to be used.
  *         This parameter can be one of the following values:
  *                       - TIM1_ICSELECTION_DIRECTTI: TIM1 Input 4 is selected to
  *                         be connected to IC4.
  *                       - TIM1_ICSELECTION_INDIRECTTI: TIM1 Input 4 is selected to
  *                         be connected to IC3.
  * @param  TIM1_ICFilter Specifies the Input Capture Filter.
  *         This parameter must be a value between 0x00 and 0x0F.
  * @retval None
  */
void TIM1_TI4_Config(uint8_t TIM1_ICPolarity,
                     uint8_t TIM1_ICSelection,
                     uint8_t TIM1_ICFilter)
{
  /* Disable the Channel 4: Reset the CCE Bit */
  TIM1->CCER2 &=  (uint8_t)(~TIM1_CCER2_CC4E);
  
  /* Select the Input and set the filter */
  TIM1->CCMR4 = (uint8_t)((uint8_t)(TIM1->CCMR4 & (uint8_t)(~(uint8_t)( TIM1_CCMR_CCxS | TIM1_CCMR_ICxF )))
                          | (uint8_t)(( (TIM1_ICSelection)) | ((uint8_t)( TIM1_ICFilter << 4))));
  
  /* Select the Polarity */
  if (TIM1_ICPolarity != TIM1_ICPOLARITY_RISING)
  {
    TIM1->CCER2 |= TIM1_CCER2_CC4P;
  }
  else
  {
    TIM1->CCER2 &= (uint8_t)(~TIM1_CCER2_CC4P);
  }
  
  /* Set the CCE Bit */
  TIM1->CCER2 |=  TIM1_CCER2_CC4E;
}


/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
