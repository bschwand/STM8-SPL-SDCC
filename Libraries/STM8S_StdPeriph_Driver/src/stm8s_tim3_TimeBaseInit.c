
/**
  ********************************************************************************
  * @file    stm8s_tim3_TimeBaseInit.c
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
  * @brief  Initializes the TIM3 Time Base Unit according to the specified parameters.
  * @param    TIM3_Prescaler specifies the Prescaler from TIM3_Prescaler_TypeDef.
  * @param    TIM3_Period specifies the Period value.
  * @retval None
  */
void TIM3_TimeBaseInit( TIM3_Prescaler_TypeDef TIM3_Prescaler,
                        uint16_t TIM3_Period)
{
  /* Set the Prescaler value */
  TIM3->PSCR = (uint8_t)(TIM3_Prescaler);
  /* Set the Autoreload value */
  TIM3->ARRH = (uint8_t)(TIM3_Period >> 8);
  TIM3->ARRL = (uint8_t)(TIM3_Period);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
