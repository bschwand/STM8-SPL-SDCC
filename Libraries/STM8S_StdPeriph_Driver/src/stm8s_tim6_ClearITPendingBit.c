
/**
  ********************************************************************************
  * @file    stm8s_tim6_ClearITPendingBit.c
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
  * @brief  Clears the TIM6's interrupt pending bits.
  * @param   TIM6_IT : Specifies the pending bit to clear.
  * This parameter can be one of the @ref TIM6_IT_TypeDef enumeration.
  * @retval None
  */
void TIM6_ClearITPendingBit(TIM6_IT_TypeDef TIM6_IT)
{
  /* Check the parameters */
  assert_param(IS_TIM6_IT_OK(TIM6_IT));
  
  /* Clear the IT pending Bit */
  TIM6->SR1 &= (uint8_t)(~(uint8_t)TIM6_IT);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
