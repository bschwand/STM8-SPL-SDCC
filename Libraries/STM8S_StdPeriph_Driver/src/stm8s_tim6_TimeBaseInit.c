
/**
  ********************************************************************************
  * @file    stm8s_tim6_TimeBaseInit.c
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
  * @brief  Initializes the TIM6 Time Base Unit according to the specified
  * parameters.
  * @param   TIM6_Prescaler : This parameter can be any of the @Ref TIM5_Prescaler_TypeDef enumeration.
  * @param   TIM6_Period : This parameter must be a value between 0x00 and 0xFF.
  * @retval None
  */
void TIM6_TimeBaseInit(TIM6_Prescaler_TypeDef TIM6_Prescaler,
                       uint8_t TIM6_Period)
{
  /* Check TIM6 prescaler value */
  assert_param(IS_TIM6_PRESCALER_OK(TIM6_Prescaler));
  /* Set the Autoreload value */
  TIM6->ARR = (uint8_t)(TIM6_Period);
  /* Set the Prescaler value */
  TIM6->PSCR = (uint8_t)(TIM6_Prescaler);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
