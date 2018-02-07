
/**
  ********************************************************************************
  * @file    stm8s_clk_ITConfig.c
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
  * @brief   Enables or disables the specified CLK interrupts.
  * @param   CLK_IT This parameter specifies the interrupt sources.
  * It can be one of the values of @ref CLK_IT_TypeDef.
  * @param   NewState New state of the Interrupt.
  * Value accepted ENABLE, DISABLE.
  * @retval None
  */
void CLK_ITConfig(CLK_IT_TypeDef CLK_IT, FunctionalState NewState)
{
  /* check the parameters */
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  assert_param(IS_CLK_IT_OK(CLK_IT));
  
  if (NewState != DISABLE)
  {
    switch (CLK_IT)
    {
    case CLK_IT_SWIF: /* Enable the clock switch interrupt */
      CLK->SWCR |= CLK_SWCR_SWIEN;
      break;
    case CLK_IT_CSSD: /* Enable the clock security system detection interrupt */
      CLK->CSSR |= CLK_CSSR_CSSDIE;
      break;
    default:
      break;
    }
  }
  else  /*(NewState == DISABLE)*/
  {
    switch (CLK_IT)
    {
    case CLK_IT_SWIF: /* Disable the clock switch interrupt */
      CLK->SWCR  &= (uint8_t)(~CLK_SWCR_SWIEN);
      break;
    case CLK_IT_CSSD: /* Disable the clock security system detection interrupt */
      CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSDIE);
      break;
    default:
      break;
    }
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
