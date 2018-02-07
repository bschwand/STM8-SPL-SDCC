
/**
  ********************************************************************************
  * @file    stm8s_clk_CCOConfig.c
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
  * @brief  Output the selected clock on a dedicated I/O pin.
  * @param   CLK_CCO : Specifies the clock source.
  * This parameter can be any of the  @ref CLK_Output_TypeDef enumeration.
  * @retval None
  * @par Required preconditions:
  * The dedicated I/O pin must be set at 1 in the corresponding Px_CR1 register \n
  * to be set as input with pull-up or push-pull output.
  */
void CLK_CCOConfig(CLK_Output_TypeDef CLK_CCO)
{
  /* check the parameters */
  assert_param(IS_CLK_OUTPUT_OK(CLK_CCO));
  
  /* Clears of the CCO type bits part */
  CLK->CCOR &= (uint8_t)(~CLK_CCOR_CCOSEL);
  
  /* Selects the source provided on cco_ck output */
  CLK->CCOR |= (uint8_t)CLK_CCO;
  
  /* Enable the clock output */
  CLK->CCOR |= CLK_CCOR_CCOEN;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
