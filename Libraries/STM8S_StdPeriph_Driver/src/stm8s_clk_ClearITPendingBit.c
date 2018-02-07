
/**
  ********************************************************************************
  * @file    stm8s_clk_ClearITPendingBit.c
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
  * @brief  Clears the CLK’s interrupt pending bits.
  * @param   CLK_IT specifies the interrupt pending bits.
  * can be one of the values of @ref CLK_IT_TypeDef
  * @retval None
  */
void CLK_ClearITPendingBit(CLK_IT_TypeDef CLK_IT)
{
  /* check the parameters */
  assert_param(IS_CLK_IT_OK(CLK_IT));
  
  if (CLK_IT == (uint8_t)CLK_IT_CSSD)
  {
    /* Clear the status of the security system detection interrupt */
    CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSD);
  }
  else /* CLK_PendingBit == (uint8_t)CLK_IT_SWIF */
  {
    /* Clear the status of the clock switch interrupt */
    CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIF);
  }
  
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
