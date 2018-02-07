
/**
  ********************************************************************************
  * @file    stm8s_tim5_PWMIConfig.c
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
  * @brief  Configures the TIM5 peripheral in PWM Input Mode according to the specified parameters.
    * @param    TIM5_Channel specifies the Input Capture Channel from @ref TIM5_Channel_TypeDef.
  * @param   TIM5_ICPolarity specifies the Input Capture Polarity from @ref TIM5_ICPolarity_TypeDef.
  * @param   TIM5_ICSelection specifies theInput Capture Selection from @ref TIM5_ICSelection_TypeDef.
  * @param   TIM5_ICPrescaler specifies the Input Capture Prescaler from @ref TIM5_ICPSC_TypeDef.
  * @param   TIM5_ICFilter specifies the Input Capture Filter value (value can be an integer from 0x00 to 0x0F).
  * @retval None
  */
void TIM5_PWMIConfig(TIM5_Channel_TypeDef TIM5_Channel,
                     TIM5_ICPolarity_TypeDef TIM5_ICPolarity,
                     TIM5_ICSelection_TypeDef TIM5_ICSelection,
                     TIM5_ICPSC_TypeDef TIM5_ICPrescaler,
                     uint8_t TIM5_ICFilter)
{
  uint8_t icpolarity = (uint8_t)TIM5_ICPOLARITY_RISING;
  uint8_t icselection = (uint8_t)TIM5_ICSELECTION_DIRECTTI;
  
  /* Check the parameters */
  assert_param(IS_TIM5_PWMI_CHANNEL_OK(TIM5_Channel));
  assert_param(IS_TIM5_IC_POLARITY_OK(TIM5_ICPolarity));
  assert_param(IS_TIM5_IC_SELECTION_OK(TIM5_ICSelection));
  assert_param(IS_TIM5_IC_PRESCALER_OK(TIM5_ICPrescaler));
  
  /* Select the Opposite Input Polarity */
  if (TIM5_ICPolarity != TIM5_ICPOLARITY_FALLING)
  {
    icpolarity = (uint8_t)TIM5_ICPOLARITY_FALLING;
  }
  else
  {
    icpolarity = (uint8_t)TIM5_ICPOLARITY_RISING;
  }
  
  /* Select the Opposite Input */
  if (TIM5_ICSelection == TIM5_ICSELECTION_DIRECTTI)
  {
    icselection = (uint8_t)TIM5_ICSELECTION_INDIRECTTI;
  }
  else
  {
    icselection = (uint8_t)TIM5_ICSELECTION_DIRECTTI;
  }
  
  if (TIM5_Channel == TIM5_CHANNEL_1)
  {
    /* TI1 Configuration */
    TI1_Config((uint8_t)TIM5_ICPolarity, (uint8_t)TIM5_ICSelection,
               (uint8_t)TIM5_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM5_SetIC1Prescaler(TIM5_ICPrescaler);
    
    /* TI2 Configuration */
    TI2_Config((uint8_t)icpolarity, (uint8_t)icselection, (uint8_t)TIM5_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM5_SetIC2Prescaler(TIM5_ICPrescaler);
  }
  else
  {
    /* TI2 Configuration */
    TI2_Config((uint8_t)TIM5_ICPolarity, (uint8_t)TIM5_ICSelection,
               (uint8_t)TIM5_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM5_SetIC2Prescaler(TIM5_ICPrescaler);
    
    /* TI1 Configuration */
    TI1_Config((uint8_t)icpolarity, (uint8_t)icselection, (uint8_t)TIM5_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM5_SetIC1Prescaler(TIM5_ICPrescaler);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
