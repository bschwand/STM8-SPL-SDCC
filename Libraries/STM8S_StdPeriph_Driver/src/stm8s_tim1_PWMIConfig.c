
/**
  ********************************************************************************
  * @file    stm8s_tim1_PWMIConfig.c
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
  * @brief  Configures the TIM1 peripheral in PWM Input Mode according to the 
  *         specified parameters.
  * @param  TIM1_Channel specifies the input capture channel from 
  *         @ref TIM1_Channel_TypeDef.
  * @param  TIM1_ICPolarity specifies the Input capture polarity from  
  *         @ref TIM1_ICPolarity_TypeDef .
  * @param  TIM1_ICSelection specifies the Input capture source selection  from
  *         @ref TIM1_ICSelection_TypeDef.
  * @param  TIM1_ICPrescaler specifies the Input capture Prescaler from  
  *         @ref TIM1_ICPSC_TypeDef.
  * @param  TIM1_ICFilter specifies the Input capture filter value.
  * @retval None
  */
void TIM1_PWMIConfig(TIM1_Channel_TypeDef TIM1_Channel,
                     TIM1_ICPolarity_TypeDef TIM1_ICPolarity,
                     TIM1_ICSelection_TypeDef TIM1_ICSelection,
                     TIM1_ICPSC_TypeDef TIM1_ICPrescaler,
                     uint8_t TIM1_ICFilter)
{
  uint8_t icpolarity = TIM1_ICPOLARITY_RISING;
  uint8_t icselection = TIM1_ICSELECTION_DIRECTTI;
  
  /* Check the parameters */
  assert_param(IS_TIM1_PWMI_CHANNEL_OK(TIM1_Channel));
  assert_param(IS_TIM1_IC_POLARITY_OK(TIM1_ICPolarity));
  assert_param(IS_TIM1_IC_SELECTION_OK(TIM1_ICSelection));
  assert_param(IS_TIM1_IC_PRESCALER_OK(TIM1_ICPrescaler));
  
  /* Select the Opposite Input Polarity */
  if (TIM1_ICPolarity != TIM1_ICPOLARITY_FALLING)
  {
    icpolarity = TIM1_ICPOLARITY_FALLING;
  }
  else
  {
    icpolarity = TIM1_ICPOLARITY_RISING;
  }
  
  /* Select the Opposite Input */
  if (TIM1_ICSelection == TIM1_ICSELECTION_DIRECTTI)
  {
    icselection = TIM1_ICSELECTION_INDIRECTTI;
  }
  else
  {
    icselection = TIM1_ICSELECTION_DIRECTTI;
  }
  
  if (TIM1_Channel == TIM1_CHANNEL_1)
  {
    /* TI1 Configuration */
    TIM1_TI1_Config((uint8_t)TIM1_ICPolarity, (uint8_t)TIM1_ICSelection,
               (uint8_t)TIM1_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM1_SetIC1Prescaler(TIM1_ICPrescaler);
    
    /* TI2 Configuration */
    TIM1_TI2_Config(icpolarity, icselection, TIM1_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM1_SetIC2Prescaler(TIM1_ICPrescaler);
  }
  else
  {
    /* TI2 Configuration */
    TIM1_TI2_Config((uint8_t)TIM1_ICPolarity, (uint8_t)TIM1_ICSelection,
               (uint8_t)TIM1_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM1_SetIC2Prescaler(TIM1_ICPrescaler);
    
    /* TI1 Configuration */
    TIM1_TI1_Config(icpolarity, icselection, TIM1_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM1_SetIC1Prescaler(TIM1_ICPrescaler);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
