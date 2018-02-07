
/**
  ********************************************************************************
  * @file    stm8s_tim6_GetFlagStatus.c
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
  * @brief  Checks whether the specified TIM6 flag is set or not.
  * @param   TIM6_FLAG : Specifies the flag to check.
  * This parameter can be one of the @ref TIM6_FLAG_TypeDef enumeration.
  * @retval FlagStatus : The new state of TIM6_FLAG.
  * This parameter can be any of the @ref FlagStatus enumeration.
  */
FlagStatus TIM6_GetFlagStatus(TIM6_FLAG_TypeDef TIM6_FLAG)
{
  volatile FlagStatus bitstatus = RESET;
  
  /* Check the parameters */
  assert_param(IS_TIM6_GET_FLAG_OK(TIM6_FLAG));
  
  if ((TIM6->SR1 & (uint8_t)TIM6_FLAG)  != 0)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  return ((FlagStatus)bitstatus);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
