
/**
  ********************************************************************************
  * @file    stm8s_tim3_ICInit.c
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
  * @addtogroup TIM3_Public_Functions
  * @{
  */

/**
  * @brief  Initializes the TIM3 peripheral according to the specified parameters.
  * @param    TIM3_Channel specifies the Input Capture Channel from @ref TIM3_Channel_TypeDef.
  * @param   TIM3_ICPolarity specifies the Input Capture Polarity from @ref TIM3_ICPolarity_TypeDef.
  * @param   TIM3_ICSelection specifies the Input Capture Selection from @ref TIM3_ICSelection_TypeDef.
  * @param   TIM3_ICPrescaler specifies the Input Capture Prescaler from @ref TIM3_ICPSC_TypeDef.
  * @param   TIM3_ICFilter specifies the Input Capture Filter value (value can be an integer from 0x00 to 0x0F).
  * @retval None
  */
void TIM3_ICInit(TIM3_Channel_TypeDef TIM3_Channel,
                 TIM3_ICPolarity_TypeDef TIM3_ICPolarity,
                 TIM3_ICSelection_TypeDef TIM3_ICSelection,
                 TIM3_ICPSC_TypeDef TIM3_ICPrescaler,
                 uint8_t TIM3_ICFilter)
{
  /* Check the parameters */
  assert_param(IS_TIM3_CHANNEL_OK(TIM3_Channel));
  assert_param(IS_TIM3_IC_POLARITY_OK(TIM3_ICPolarity));
  assert_param(IS_TIM3_IC_SELECTION_OK(TIM3_ICSelection));
  assert_param(IS_TIM3_IC_PRESCALER_OK(TIM3_ICPrescaler));
  assert_param(IS_TIM3_IC_FILTER_OK(TIM3_ICFilter));
  
  if (TIM3_Channel != TIM3_CHANNEL_2)
  {
    /* TI1 Configuration */
    TIM3_TI1_Config((uint8_t)TIM3_ICPolarity,
               (uint8_t)TIM3_ICSelection,
               (uint8_t)TIM3_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM3_SetIC1Prescaler(TIM3_ICPrescaler);
  }
  else
  {
    /* TI2 Configuration */
    TIM3_TI2_Config((uint8_t)TIM3_ICPolarity,
               (uint8_t)TIM3_ICSelection,
               (uint8_t)TIM3_ICFilter);
    
    /* Set the Input Capture Prescaler value */
    TIM3_SetIC2Prescaler(TIM3_ICPrescaler);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
