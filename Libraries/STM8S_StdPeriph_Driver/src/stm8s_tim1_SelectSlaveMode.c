
/**
  ********************************************************************************
  * @file    stm8s_tim1_SelectSlaveMode.c
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
  * @brief  Selects the TIM1 Slave Mode.
  * @param   TIM1_SlaveMode specifies the TIM1 Slave Mode.
  * This parameter can be one of the following values
  *                       - TIM1_SLAVEMODE_RESET
  *                       - TIM1_SLAVEMODE_GATED
  *                       - TIM1_SLAVEMODE_TRIGGER
  *                       - TIM1_SLAVEMODE_EXTERNAL1
  * @retval None
  */
void TIM1_SelectSlaveMode(TIM1_SlaveMode_TypeDef TIM1_SlaveMode)
{
  /* Check the parameters */
  assert_param(IS_TIM1_SLAVE_MODE_OK(TIM1_SlaveMode));
  
  /* Reset the SMS Bits */ /* Select the Slave Mode */
  TIM1->SMCR = (uint8_t)((uint8_t)(TIM1->SMCR & (uint8_t)(~TIM1_SMCR_SMS)) |
                         (uint8_t)TIM1_SlaveMode);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
