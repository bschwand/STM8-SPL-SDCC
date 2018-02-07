
/**
  ********************************************************************************
  * @file    stm8s_tim2_PWMIConfig.c
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
#include "stm8s_tim2.h"
#include "private/stm8s_tim2_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup TIM2_Public_Functions
  * @{
  */

/**
  * @brief  Configures the TIM2 peripheral in PWM Input Mode according to the specified parameters.
    * @param    TIM2_Channel specifies the Input Capture Channel from @ref TIM2_Channel_TypeDef.
  * @param   TIM2_ICPolarity specifies the Input Capture Polarity from @ref TIM2_ICPolarity_TypeDef.
  * @param   TIM2_ICSelection specifies the Input Capture Selection from @ref TIM2_ICSelection_TypeDef.
  * @param   TIM2_ICPrescaler specifies the Input Capture Prescaler from @ref TIM2_ICPSC_TypeDef.
  * @param   TIM2_ICFilter specifies the Input Capture Filter value (value can be an integer from 0x00 to 0x0F).
  * @retval None
  */
void TIM2_PWMIConfig(TIM2_Channel_TypeDef TIM2_Channel,
                     TIM2_ICPolarity_TypeDef TIM2_ICPolarity,
                     TIM2_ICSelection_TypeDef TIM2_ICSelection,
                     TIM2_ICPSC_TypeDef TIM2_ICPrescaler,
                     uint8_t TIM2_ICFilter)
{
  uint8_t icpolarity = (uint8_t)TIM2_ICPOLARITY_RISING;
  uint8_t icselection = (uint8_t)TIM2_ICSELECTION_DIRECTTI;
  
  /* Check the parameters */
  assert_param(IS_TIM2_PWMI_CHANNEL_OK(TIM2_Channel));
  assert_param(IS_TIM2_IC_POLARITY_OK(TIM2_ICPolarity));
  assert_param(IS_TIM2_IC_SELECTION_OK(TIM2_ICSelection));
  assert_param(IS_TIM2_IC_PRESCALER_OK(TIM2_ICPrescaler));
  
  /* Select the Opposite Input Polarity */
  if (TIM2_ICPolarity != TIM2_ICPOLARITY_FALLING)
  {
    icpolarity = (uint8_t)TIM2_ICPOLARITY_FALLING;
  }
  else
  {
    icpolarity = (uint8_t)TIM2_ICPOLARITY_RISING;
  }
  
  /* Select the Opposite Input */
  if (TIM2_ICSelection == TIM2_ICSELECTION_DIRECTTI)
  {
    icselection = (uint8_t)TIM2_ICSELECTION_INDIRECTTI;
  }
  else
  {
    icselection = (uint8_t)TIM2_ICSELECTION_DIRECTTI;
  }
  
  if (TIM2_Channel == TIM2_CHANNEL_1)
  {
    /* TI1 Configuration */
    TIM2_TI1_Config((uint8_t)TIM2_ICPolarity, (uint8_t)TIM2_ICSelection,
               (uint8_t)TIM2_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM2_SetIC1Prescaler(TIM2_ICPrescaler);
    
    /* TI2 Configuration */
    TIM2_TI2_Config(icpolarity, icselection, TIM2_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM2_SetIC2Prescaler(TIM2_ICPrescaler);
  }
  else
  {
    /* TI2 Configuration */
    TIM2_TI2_Config((uint8_t)TIM2_ICPolarity, (uint8_t)TIM2_ICSelection,
               (uint8_t)TIM2_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM2_SetIC2Prescaler(TIM2_ICPrescaler);
    
    /* TI1 Configuration */
    TIM2_TI1_Config((uint8_t)icpolarity, icselection, (uint8_t)TIM2_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM2_SetIC1Prescaler(TIM2_ICPrescaler);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
