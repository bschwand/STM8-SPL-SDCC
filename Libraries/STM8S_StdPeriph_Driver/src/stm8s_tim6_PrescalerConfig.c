
/**
  ********************************************************************************
  * @file    stm8s_tim6_PrescalerConfig.c
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
#include "stm8s_tim6.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup TIM6_Public_Functions
  * @{
  */

/**
  * @brief  Configures the TIM6 Prescaler.
  * @param   Prescaler : Specifies the Prescaler Register value
  * This parameter can be one of the @ref TIM6_Prescaler_TypeDef enumeration.
  * @param   TIM6_PSCReloadMode : Specifies the TIM6 Prescaler Reload mode.
  * This parameter can be one of the @ref TIM6_PSCReloadMode_TypeDef enumeration.
  * @retval None
  */
void TIM6_PrescalerConfig(TIM6_Prescaler_TypeDef Prescaler,
                          TIM6_PSCReloadMode_TypeDef TIM6_PSCReloadMode)
{
  /* Check the parameters */
  assert_param(IS_TIM6_PRESCALER_RELOAD_OK(TIM6_PSCReloadMode));
  assert_param(IS_TIM6_PRESCALER_OK(Prescaler));
  
  /* Set the Prescaler value */
  TIM6->PSCR = (uint8_t)Prescaler;
  
  /* Set or reset the UG Bit */
  if (TIM6_PSCReloadMode == TIM6_PSCRELOADMODE_IMMEDIATE)
  {
    TIM6->EGR |= TIM6_EGR_UG ;
  }
  else
  {
    TIM6->EGR &= (uint8_t)(~TIM6_EGR_UG) ;
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
