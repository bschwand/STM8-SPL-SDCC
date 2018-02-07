
/**
  ********************************************************************************
  * @file    stm8s_tim1_SelectInputTrigger.c
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
  * @brief  Selects the TIM1 Input Trigger source.
  * @param   TIM1_InputTriggerSource specifies Input Trigger source.
  * This parameter can be one of the following values:
  *                       - TIM1_TS_TI1F_ED: TI1 Edge Detector
  *                       - TIM1_TS_TI1FP1: Filtered Timer Input 1
  *                       - TIM1_TS_TI2FP2: Filtered Timer Input 2
  *                       - TIM1_TS_ETRF: External Trigger input
  * @retval None
  */
void TIM1_SelectInputTrigger(TIM1_TS_TypeDef TIM1_InputTriggerSource)
{
  /* Check the parameters */
  assert_param(IS_TIM1_TRIGGER_SELECTION_OK(TIM1_InputTriggerSource));
  
  /* Select the Tgigger Source */
  TIM1->SMCR = (uint8_t)((uint8_t)(TIM1->SMCR & (uint8_t)(~TIM1_SMCR_TS)) | (uint8_t)TIM1_InputTriggerSource);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
