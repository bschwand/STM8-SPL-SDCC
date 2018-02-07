
/**
  ********************************************************************************
  * @file    stm8s_tim5_OC2PolarityConfig.c
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
  * @brief  Configures the TIM5 Channel 2 polarity.
  * @param   TIM5_OCPolarity specifies the OC2 Polarity.
  * This parameter can be one of the following values:
  *                       - TIM5_OCPOLARITY_LOW: Output Compare active low
  *                       - TIM5_OCPOLARITY_HIGH: Output Compare active high
  * @retval None
  */
void TIM5_OC2PolarityConfig(TIM5_OCPolarity_TypeDef TIM5_OCPolarity)
{
  /* Check the parameters */
  assert_param(IS_TIM5_OC_POLARITY_OK(TIM5_OCPolarity));
  
  /* Set or Reset the CC2P Bit */
  if (TIM5_OCPolarity != TIM5_OCPOLARITY_HIGH)
  {
    TIM5->CCER1 |= TIM5_CCER1_CC2P ;
  }
  else
  {
    TIM5->CCER1 &= (uint8_t)(~TIM5_CCER1_CC2P) ;
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
