
/**
  ********************************************************************************
  * @file    stm8s_uart4_ITConfig.c
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
#include "stm8s_uart4.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup UART4_Public_Functions
  * @{
  */

/**
  * @brief  Enables or disables the specified UART4 interrupts.
  * @param  UART4_IT specifies the UART4 interrupt sources to be enabled or disabled.
  *         This parameter can be one of the following values:
  *         - UART4_IT_LBDF:  LIN Break detection interrupt
  *         - UART4_IT_LHDF:  LIN Break detection interrupt
  *         - UART4_IT_TXE:  Transmit Data Register empty interrupt
  *         - UART4_IT_TC:   Transmission complete interrupt
  *         - UART4_IT_RXNE_OR: Receive Data register not empty/Over run error interrupt
  *         - UART4_IT_IDLE: Idle line detection interrupt
  *         - UART4_IT_PE:   Parity Error interrupt
  * @param  NewState new state of the specified UART4 interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART4_ITConfig(UART4_IT_TypeDef UART4_IT, FunctionalState NewState)
{
  uint8_t uartreg = 0, itpos = 0x00;
  
  /* Check the parameters */
  assert_param(IS_UART4_CONFIG_IT_OK(UART4_IT));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  
  /* Get the UART4 register index */
  uartreg = (uint8_t)((uint16_t)UART4_IT >> 0x08);
  
  /* Get the UART4 IT index */
  itpos = (uint8_t)((uint8_t)1 << (uint8_t)((uint8_t)UART4_IT & (uint8_t)0x0F));
  
  if(NewState != DISABLE)
  {
    /* Enable the Interrupt bits according to UART4_IT mask */
    if(uartreg == 0x01)
    {
      UART4->CR1 |= itpos;
    }
    else if(uartreg == 0x02)
    {
      UART4->CR2 |= itpos;
    }
    else if(uartreg == 0x03)
    {
      UART4->CR4 |= itpos;
    }
    else
    {
      UART4->CR6 |= itpos;
    }
  }
  else
  {
    /* Disable the interrupt bits according to UART4_IT mask */
    if(uartreg == 0x01)
    {
      UART4->CR1 &= (uint8_t)(~itpos);
    }
    else if(uartreg == 0x02)
    {
      UART4->CR2 &= (uint8_t)(~itpos);
    }
    else if(uartreg == 0x03)
    {
      UART4->CR4 &= (uint8_t)(~itpos);
    }
    else
    {
      UART4->CR6 &= (uint8_t)(~itpos);
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
