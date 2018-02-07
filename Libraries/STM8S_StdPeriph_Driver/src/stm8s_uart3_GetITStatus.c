
/**
  ********************************************************************************
  * @file    stm8s_uart3_GetITStatus.c
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
#include "stm8s_uart3.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup UART3_Public_Functions
  * @{
  */

/**
  * @brief  Checks whether the specified UART3 interrupt has occurred or not.
  * @param  UART3_IT: Specifies the UART3 interrupt pending bit to check.
  *         This parameter can be one of the following values:
  *         - UART3_IT_LBDF:  LIN Break detection interrupt
  *         - UART3_IT_TXE:  Transmit Data Register empty interrupt
  *         - UART3_IT_TC:   Transmission complete interrupt
  *         - UART3_IT_RXNE: Receive Data register not empty interrupt
  *         - UART3_IT_IDLE: Idle line detection interrupt
  *         - UART3_IT_OR:  OverRun Error interrupt
  *         - UART3_IT_PE:   Parity Error interrupt
  * @retval The state of UART3_IT (SET or RESET).
  */
ITStatus UART3_GetITStatus(UART3_IT_TypeDef UART3_IT)
{
  ITStatus pendingbitstatus = RESET;
  uint8_t itpos = 0;
  uint8_t itmask1 = 0;
  uint8_t itmask2 = 0;
  uint8_t enablestatus = 0;
  
  /* Check parameters */
  assert_param(IS_UART3_GET_IT_OK(UART3_IT));
  
  /* Get the UART3 IT index*/
  itpos = (uint8_t)((uint8_t)1 << (uint8_t)((uint8_t)UART3_IT & (uint8_t)0x0F));
  /* Get the UART3 IT index*/
  itmask1 = (uint8_t)((uint8_t)UART3_IT >> (uint8_t)4);
  /* Set the IT mask*/
  itmask2 = (uint8_t)((uint8_t)1 << itmask1);
  
  /* Check the status of the specified UART3 pending bit*/
  if (UART3_IT == UART3_IT_PE)
  {
    /* Get the UART3_ITPENDINGBIT enable bit status*/
    enablestatus = (uint8_t)((uint8_t)UART3->CR1 & itmask2);
    /* Check the status of the specified UART3 interrupt*/
    
    if (((UART3->SR & itpos) != (uint8_t)0x00) && enablestatus)
    {
      /* Interrupt occurred*/
      pendingbitstatus = SET;
    }
    else
    {
      /* Interrupt not occurred*/
      pendingbitstatus = RESET;
    }
  }
  else if (UART3_IT == UART3_IT_LBDF)
  {
    /* Get the UART3_IT enable bit status*/
    enablestatus = (uint8_t)((uint8_t)UART3->CR4 & itmask2);
    /* Check the status of the specified UART3 interrupt*/
    if (((UART3->CR4 & itpos) != (uint8_t)0x00) && enablestatus)
    {
      /* Interrupt occurred*/
      pendingbitstatus = SET;
    }
    else
    {
      /* Interrupt not occurred*/
      pendingbitstatus = RESET;
    }
  }
  else if (UART3_IT == UART3_IT_LHDF)
  {
    /* Get the UART3_IT enable bit status*/
    enablestatus = (uint8_t)((uint8_t)UART3->CR6 & itmask2);
    /* Check the status of the specified UART3 interrupt*/
    if (((UART3->CR6 & itpos) != (uint8_t)0x00) && enablestatus)
    {
      /* Interrupt occurred*/
      pendingbitstatus = SET;
    }
    else
    {
      /* Interrupt not occurred*/
      pendingbitstatus = RESET;
    }
  }
  else
  {
    /* Get the UART3_IT enable bit status*/
    enablestatus = (uint8_t)((uint8_t)UART3->CR2 & itmask2);
    /* Check the status of the specified UART3 interrupt*/
    if (((UART3->SR & itpos) != (uint8_t)0x00) && enablestatus)
    {
      /* Interrupt occurred*/
      pendingbitstatus = SET;
    }
    else
    {
      /* Interrupt not occurred*/
      pendingbitstatus = RESET;
    }
  }
  /* Return the UART3_IT status*/
  return  pendingbitstatus;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
