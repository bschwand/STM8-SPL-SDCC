
/**
  ********************************************************************************
  * @file    stm8s_tim6_SelectOutputTrigger.c
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
  * @brief  Selects the TIM6 Trigger Output Mode.
  * @param   TIM6_TRGOSource : Specifies the Trigger Output source.
  * This parameter can be one of the @ref TIM6_TRGOSource_TypeDef enumeration.
  * @retval None
  */
void TIM6_SelectOutputTrigger(TIM6_TRGOSource_TypeDef TIM6_TRGOSource)
{
  uint8_t tmpcr2 = 0;
  
  /* Check the parameters */
  assert_param(IS_TIM6_TRGO_SOURCE_OK(TIM6_TRGOSource));
  
  tmpcr2 = TIM6->CR2;
  
  /* Reset the MMS Bits */
  tmpcr2 &= (uint8_t)(~TIM6_CR2_MMS);
  
  /* Select the TRGO source */
  tmpcr2 |=  (uint8_t)TIM6_TRGOSource;
  
  TIM6->CR2 = tmpcr2;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
