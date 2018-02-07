
/**
  ********************************************************************************
  * @file    stm8s_tim5_TimeBaseInit.c
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
  * @brief  Initializes the TIM5 Time Base Unit according to the specified parameters.
  * @param    TIM5_Prescaler specifies the Prescaler from TIM5_Prescaler_TypeDef.
  * @param    TIM5_Period specifies the Period value.
  * @retval None
  */
void TIM5_TimeBaseInit( TIM5_Prescaler_TypeDef TIM5_Prescaler,
                        uint16_t TIM5_Period)
{
  /* Set the Prescaler value */
  TIM5->PSCR = (uint8_t)(TIM5_Prescaler);
  /* Set the Autoreload value */
  TIM5->ARRH = (uint8_t)(TIM5_Period >> 8) ;
  TIM5->ARRL = (uint8_t)(TIM5_Period);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
