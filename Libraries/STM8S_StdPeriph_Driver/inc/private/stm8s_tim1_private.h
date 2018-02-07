/**
  ******************************************************************************
  * @file    stm8s_tim1_private.h
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains all the functions for the TIM1 peripheral.
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

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void TIM1_TI1_Config(uint8_t TIM1_ICPolarity, uint8_t TIM1_ICSelection,
                     uint8_t TIM1_ICFilter);
void TIM1_TI2_Config(uint8_t TIM1_ICPolarity, uint8_t TIM1_ICSelection,
                     uint8_t TIM1_ICFilter);
void TIM1_TI3_Config(uint8_t TIM1_ICPolarity, uint8_t TIM1_ICSelection,
                     uint8_t TIM1_ICFilter);
void TIM1_TI4_Config(uint8_t TIM1_ICPolarity, uint8_t TIM1_ICSelection,
                     uint8_t TIM1_ICFilter);

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
