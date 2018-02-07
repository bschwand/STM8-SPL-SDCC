
/**
  ********************************************************************************
  * @file    stm8s_clk_SWIMConfig.c
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
  * @brief  Configures the SWIM clock frequency on the fly.
  * @param   CLK_SWIMDivider Specifies the SWIM clock divider to apply.
  * can be one of the value of @ref CLK_SWIMDivider_TypeDef
  * @retval None
  */
void CLK_SWIMConfig(CLK_SWIMDivider_TypeDef CLK_SWIMDivider)
{
  /* check the parameters */
  assert_param(IS_CLK_SWIMDIVIDER_OK(CLK_SWIMDivider));
  
  if (CLK_SWIMDivider != CLK_SWIMDIVIDER_2)
  {
    /* SWIM clock is not divided by 2 */
    CLK->SWIMCCR |= CLK_SWIMCCR_SWIMDIV;
  }
  else /* CLK_SWIMDivider == CLK_SWIMDIVIDER_2 */
  {
    /* SWIM clock is divided by 2 */
    CLK->SWIMCCR &= (uint8_t)(~CLK_SWIMCCR_SWIMDIV);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
