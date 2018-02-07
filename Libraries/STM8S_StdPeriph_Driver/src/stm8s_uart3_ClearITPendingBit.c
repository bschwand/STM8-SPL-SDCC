
/**
  ********************************************************************************
  * @file    stm8s_uart3_ClearITPendingBit.c
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
  * @brief  Clears the UART3 pending flags.
  * @param  UART3_IT specifies the pending bit to clear
  *         This parameter can be one of the following values:
  *         - UART3_IT_LBDF:  LIN Break detection interrupt
  *         - UART3_IT_LHDF:  LIN Header detection interrupt
  *         - UART3_IT_RXNE: Receive Data register not empty interrupt.
  *
  * @note
  *         - PE (Parity error), FE (Framing error), NF (Noise error), 
  *           OR (OverRun error) and IDLE (Idle line detected) pending bits are 
  *           cleared by software sequence: a read operation to UART3_SR register
  *           (UART3_GetITStatus()) followed by a read operation to UART3_DR register 
  *           (UART3_ReceiveData8() or UART3_ReceiveData9()).
  *             
  *         - RXNE pending bit can be also cleared by a read to the UART3_DR register
  *           (UART3_ReceiveData8() or UART3_ReceiveData9() ).
  *             
  *         - TC (Transmit complete) pending bit can be cleared by software 
  *           sequence: a read operation to UART3_SR register (UART3_GetITStatus())
  *           followed by a write operation to UART3_DR register 
  *           (UART3_SendData8()or UART3_SendData9()).
  *             
  *         - TXE pending bit is cleared only by a write to the UART3_DR register
  *           (UART3_SendData8() or UART3_SendData9()).
  * @retval None
  */
void UART3_ClearITPendingBit(UART3_IT_TypeDef UART3_IT)
{
  /* Check the parameters */
  assert_param(IS_UART3_CLEAR_IT_OK(UART3_IT));
  
  /*Clear the Receive Register Not Empty pending bit */
  if (UART3_IT == UART3_IT_RXNE)
  {
    UART3->SR = (uint8_t)~(UART3_SR_RXNE);
  }
  /*Clear the LIN Break Detection pending bit */
  else if (UART3_IT == UART3_IT_LBDF)
  {
    UART3->CR4 &= (uint8_t)~(UART3_CR4_LBDF);
  }
  /*Clear the LIN Header Detection pending bit */
  else
  {
    UART3->CR6 &= (uint8_t)(~UART3_CR6_LHDF);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
