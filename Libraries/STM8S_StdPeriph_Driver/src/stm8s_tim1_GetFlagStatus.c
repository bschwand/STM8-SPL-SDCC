
/**
  ********************************************************************************
  * @file    stm8s_tim1_GetFlagStatus.c
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
  * @brief  Checks whether the specified TIM1 flag is set or not.
  * @param  TIM1_FLAG specifies the flag to check.
  *         This parameter can be one of the following values:
  *                   - TIM1_FLAG_UPDATE: TIM1 update Flag
  *                   - TIM1_FLAG_CC1: TIM1 Capture Compare 1 Flag
  *                   - TIM1_FLAG_CC2: TIM1 Capture Compare 2 Flag
  *                   - TIM1_FLAG_CC3: TIM1 Capture Compare 3 Flag
  *                   - TIM1_FLAG_CC4: TIM1 Capture Compare 4 Flag
  *                   - TIM1_FLAG_COM: TIM1 Commutation Flag
  *                   - TIM1_FLAG_TRIGGER: TIM1 Trigger Flag
  *                   - TIM1_FLAG_BREAK: TIM1 Break Flag
  *                   - TIM1_FLAG_CC1OF: TIM1 Capture Compare 1 overcapture Flag
  *                   - TIM1_FLAG_CC2OF: TIM1 Capture Compare 2 overcapture Flag
  *                   - TIM1_FLAG_CC3OF: TIM1 Capture Compare 3 overcapture Flag
  *                   - TIM1_FLAG_CC4OF: TIM1 Capture Compare 4 overcapture Flag
  * @retval FlagStatus The new state of TIM1_FLAG (SET or RESET).
  */
FlagStatus TIM1_GetFlagStatus(TIM1_FLAG_TypeDef TIM1_FLAG)
{
  FlagStatus bitstatus = RESET;
  uint8_t tim1_flag_l = 0, tim1_flag_h = 0;
  
  /* Check the parameters */
  assert_param(IS_TIM1_GET_FLAG_OK(TIM1_FLAG));
  
  tim1_flag_l = (uint8_t)(TIM1->SR1 & (uint8_t)TIM1_FLAG);
  tim1_flag_h = (uint8_t)((uint16_t)TIM1_FLAG >> 8);
  
  if ((tim1_flag_l | (uint8_t)(TIM1->SR2 & tim1_flag_h)) != 0)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  return (FlagStatus)(bitstatus);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
