
/**
  ********************************************************************************
  * @file    stm8s_tim1_BDTRConfig.c
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
  * @brief  Configures the Break feature, dead time, Lock level, the OSSI,
  *         and the AOE(automatic output enable).
  * @param  TIM1_OSSIState specifies the OSSIS State from @ref TIM1_OSSIState_TypeDef.
  * @param  TIM1_LockLevel specifies the lock level from @ref TIM1_LockLevel_TypeDef.
  * @param  TIM1_DeadTime specifies the dead time value.
  * @param  TIM1_Break specifies the Break state @ref TIM1_BreakState_TypeDef.
  * @param  TIM1_BreakPolarity specifies the Break polarity from 
  *         @ref TIM1_BreakPolarity_TypeDef.
  * @param  TIM1_AutomaticOutput specifies the Automatic Output configuration 
  *         from @ref TIM1_AutomaticOutput_TypeDef.
  * @retval None
  */
void TIM1_BDTRConfig(TIM1_OSSIState_TypeDef TIM1_OSSIState,
                     TIM1_LockLevel_TypeDef TIM1_LockLevel,
                     uint8_t TIM1_DeadTime,
                     TIM1_BreakState_TypeDef TIM1_Break,
                     TIM1_BreakPolarity_TypeDef TIM1_BreakPolarity,
                     TIM1_AutomaticOutput_TypeDef TIM1_AutomaticOutput)
{
  /* Check the parameters */
  assert_param(IS_TIM1_OSSI_STATE_OK(TIM1_OSSIState));
  assert_param(IS_TIM1_LOCK_LEVEL_OK(TIM1_LockLevel));
  assert_param(IS_TIM1_BREAK_STATE_OK(TIM1_Break));
  assert_param(IS_TIM1_BREAK_POLARITY_OK(TIM1_BreakPolarity));
  assert_param(IS_TIM1_AUTOMATIC_OUTPUT_STATE_OK(TIM1_AutomaticOutput));
  
  TIM1->DTR = (uint8_t)(TIM1_DeadTime);
  /* Set the Lock level, the Break enable Bit and the Polarity, the OSSI State,
  the dead time value  and the Automatic Output Enable Bit */
  
  TIM1->BKR  =  (uint8_t)((uint8_t)(TIM1_OSSIState | (uint8_t)TIM1_LockLevel)  | 
                          (uint8_t)((uint8_t)(TIM1_Break | (uint8_t)TIM1_BreakPolarity)  | 
                          (uint8_t)TIM1_AutomaticOutput));
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
