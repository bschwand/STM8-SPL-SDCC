
/**
  ********************************************************************************
  * @file    stm8s_clk_FastHaltWakeUpCmd.c
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
#include "stm8s_clk.h"
#include "private/stm8s_clk_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup CLK_Public_Functions
  * @{
  */

/**
  * @brief   Configures the High Speed Internal oscillator (HSI).
  * @par Full description:
  * If CLK_FastHaltWakeup is enabled, HSI oscillator is automatically
  * switched-on (HSIEN=1) and selected as next clock master
  * (CKM=SWI=HSI) when resuming from HALT/ActiveHalt modes.\n
  * @param   NewState this parameter is the Wake-up Mode state.
  * @retval None
  */
void CLK_FastHaltWakeUpCmd(FunctionalState NewState)
{
  /* check the parameters */
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  
  if (NewState != DISABLE)
  {
    /* Set FHWU bit (HSI oscillator is automatically switched-on) */
    CLK->ICKR |= CLK_ICKR_FHWU;
  }
  else  /* FastHaltWakeup = DISABLE */
  {
    /* Reset FHWU bit */
    CLK->ICKR &= (uint8_t)(~CLK_ICKR_FHWU);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
