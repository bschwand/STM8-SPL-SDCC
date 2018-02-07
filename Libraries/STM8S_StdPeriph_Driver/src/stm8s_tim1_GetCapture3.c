
/**
  ********************************************************************************
  * @file    stm8s_tim1_GetCapture3.c
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
  * @brief  Gets the TIM1 Input Capture 3 value.
  * @param  None
  * @retval Capture Compare 3 Register value.
  */
uint16_t TIM1_GetCapture3(void)
{
  /* Get the Capture 3 Register value */
  uint16_t tmpccr3 = 0;
  uint8_t tmpccr3l=0, tmpccr3h=0;
  
  tmpccr3h = TIM1->CCR3H;
  tmpccr3l = TIM1->CCR3L;
  
  tmpccr3 = (uint16_t)(tmpccr3l);
  tmpccr3 |= (uint16_t)((uint16_t)tmpccr3h << 8);
  /* Get the Capture 3 Register value */
  return (uint16_t)tmpccr3;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
