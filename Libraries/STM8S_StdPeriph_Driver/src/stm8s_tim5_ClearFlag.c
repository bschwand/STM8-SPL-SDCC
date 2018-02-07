
/**
  ********************************************************************************
  * @file    stm8s_tim5_ClearFlag.c
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
  * @brief  Clears the TIM5’s pending flags.
  * @param   TIM5_FLAG specifies the flag to clear.
  * This parameter can be one of the following values:
  *                       - TIM5_FLAG_UPDATE: TIM5 update Flag
  *                       - TIM5_FLAG_CC1: TIM5 Capture Compare 1 Flag
  *                       - TIM5_FLAG_CC2: TIM5 Capture Compare 2 Flag
  *                       - TIM5_FLAG_CC3: TIM5 Capture Compare 3 Flag
  *                       - TIM5_FLAG_CC1OF: TIM5 Capture Compare 1 overcapture Flag
  *                       - TIM5_FLAG_CC2OF: TIM5 Capture Compare 2 overcapture Flag
  *                       - TIM5_FLAG_CC3OF: TIM5 Capture Compare 3 overcapture Flag
  * @retval None.
  */
void TIM5_ClearFlag(TIM5_FLAG_TypeDef TIM5_FLAG)
{
  /* Check the parameters */
  assert_param(IS_TIM5_CLEAR_FLAG_OK(TIM5_FLAG));
  
  /* Clear the flags (rc_w0) clear this bit by writing 0. Writing ‘1’ has no effect*/
  TIM5->SR1 = (uint8_t)(~((uint8_t)(TIM5_FLAG)));
  TIM5->SR2 &= (uint8_t)(~((uint8_t)((uint16_t)TIM5_FLAG >> 8)));
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
