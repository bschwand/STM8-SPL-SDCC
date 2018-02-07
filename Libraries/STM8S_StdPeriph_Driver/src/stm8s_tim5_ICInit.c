
/**
  ********************************************************************************
  * @file    stm8s_tim5_ICInit.c
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
  * @brief  Initializes the TIM5 peripheral according to the specified parameters.
  * @param    TIM5_Channel specifies the Input Capture Channel from @ref TIM5_Channel_TypeDef.
  * @param   TIM5_ICPolarity specifies the Input Capture Polarity from @ref TIM5_ICPolarity_TypeDef.
  * @param   TIM5_ICSelection specifies theInput Capture Selection from @ref TIM5_ICSelection_TypeDef.
  * @param   TIM5_ICPrescaler specifies the Input Capture Prescaler from @ref TIM5_ICPSC_TypeDef.
  * @param   TIM5_ICFilter specifies the Input Capture Filter value (value can be an integer from 0x00 to 0x0F).
  * @retval None
  */
void TIM5_ICInit(TIM5_Channel_TypeDef TIM5_Channel,
                 TIM5_ICPolarity_TypeDef TIM5_ICPolarity,
                 TIM5_ICSelection_TypeDef TIM5_ICSelection,
                 TIM5_ICPSC_TypeDef TIM5_ICPrescaler,
                 uint8_t TIM5_ICFilter)
{
  /* Check the parameters */
  assert_param(IS_TIM5_CHANNEL_OK(TIM5_Channel));
  assert_param(IS_TIM5_IC_POLARITY_OK(TIM5_ICPolarity));
  assert_param(IS_TIM5_IC_SELECTION_OK(TIM5_ICSelection));
  assert_param(IS_TIM5_IC_PRESCALER_OK(TIM5_ICPrescaler));
  assert_param(IS_TIM5_IC_FILTER_OK(TIM5_ICFilter));
  
  if (TIM5_Channel == TIM5_CHANNEL_1)
  {
    /* TI1 Configuration */
    TI1_Config((uint8_t)TIM5_ICPolarity,
               (uint8_t)TIM5_ICSelection,
               (uint8_t)TIM5_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM5_SetIC1Prescaler(TIM5_ICPrescaler);
  }
  else if (TIM5_Channel == TIM5_CHANNEL_2)
  {
    /* TI2 Configuration */
    TI2_Config((uint8_t)TIM5_ICPolarity,
               (uint8_t)TIM5_ICSelection,
               (uint8_t)TIM5_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM5_SetIC2Prescaler(TIM5_ICPrescaler);
  }
  else
  {
    /* TI3 Configuration */
    TI3_Config((uint8_t)TIM5_ICPolarity,
               (uint8_t)TIM5_ICSelection,
               (uint8_t)TIM5_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM5_SetIC3Prescaler(TIM5_ICPrescaler);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
