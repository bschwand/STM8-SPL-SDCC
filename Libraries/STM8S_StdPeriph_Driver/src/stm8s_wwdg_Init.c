
/**
  ********************************************************************************
  * @file    stm8s_wwdg_Init.c
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
#include "stm8s_wwdg.h"
#include "private/stm8s_wwdg_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup WWDG_Public_Functions
  * @{
  */

/**
  * @brief  Initializes the WWDG peripheral.
  *         This function set Window Register = WindowValue, Counter Register
  *         according to Counter and \b ENABLE \b WWDG
  * @param  Counter : WWDG counter value
  * @param  WindowValue : specifies the WWDG Window Register, range is 0x00 to 0x7F.
  * @retval None
  */
void WWDG_Init(uint8_t Counter, uint8_t WindowValue)
{
  /* Check the parameters */
  assert_param(IS_WWDG_WINDOWLIMITVALUE_OK(WindowValue));
  
  WWDG->WR = WWDG_WR_RESET_VALUE;
  WWDG->CR = (uint8_t)((uint8_t)(WWDG_CR_WDGA | WWDG_CR_T6) | (uint8_t)Counter);
  WWDG->WR = (uint8_t)((uint8_t)(~WWDG_CR_WDGA) & (uint8_t)(WWDG_CR_T6 | WindowValue));
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
