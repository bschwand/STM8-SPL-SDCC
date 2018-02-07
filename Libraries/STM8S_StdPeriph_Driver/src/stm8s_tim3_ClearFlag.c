
/**
  ********************************************************************************
  * @file    stm8s_tim3_ClearFlag.c
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
  * @brief  Clears the TIM3’s pending flags.
  * @param   TIM3_FLAG specifies the flag to clear.
  * This parameter can be one of the following values:
  *                       - TIM3_FLAG_UPDATE: TIM3 update Flag
  *                       - TIM3_FLAG_CC1: TIM3 Capture Compare 1 Flag
  *                       - TIM3_FLAG_CC2: TIM3 Capture Compare 2 Flag
  *                       - TIM3_FLAG_CC1OF: TIM3 Capture Compare 1 over capture Flag
  *                       - TIM3_FLAG_CC2OF: TIM3 Capture Compare 2 over capture Flag
  * @retval None.
  */
void TIM3_ClearFlag(TIM3_FLAG_TypeDef TIM3_FLAG)
{
  /* Check the parameters */
  assert_param(IS_TIM3_CLEAR_FLAG_OK(TIM3_FLAG));
  
  /* Clear the flags (rc_w0) clear this bit by writing 0. Writing ‘1’ has no effect*/
  TIM3->SR1 = (uint8_t)(~((uint8_t)(TIM3_FLAG)));
  TIM3->SR2 = (uint8_t)(~((uint8_t)((uint16_t)TIM3_FLAG >> 8)));
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
