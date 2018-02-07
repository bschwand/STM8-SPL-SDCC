
/**
  ********************************************************************************
  * @file    stm8s_uart3_ClearFlag.c
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
  * @brief  Clears the UART3 flags.
  * @param  UART3_FLAG specifies the flag to clear
  *         This parameter can be any combination of the following values:
  *         - UART3_FLAG_LBDF: LIN Break detection flag.
  *         - UART3_FLAG_LHDF: LIN Header detection flag.
  *         - UART3_FLAG_LSF: LIN synchrone field flag.
  *         - UART3_FLAG_RXNE: Receive data register not empty flag.
  * @note
  *         - PE (Parity error), FE (Framing error), NF (Noise error), 
  *           OR (OverRun error) and IDLE (Idle line detected) flags are cleared
  *           by software sequence: a read operation to UART3_SR register 
  *           (UART3_GetFlagStatus())followed by a read operation to UART3_DR 
  *           register(UART3_ReceiveData8() or UART3_ReceiveData9()).
  *             
  *         - RXNE flag can be also cleared by a read to the UART3_DR register
  *           (UART3_ReceiveData8()or UART3_ReceiveData9()).
  *             
  *         - TC flag can be also cleared by software sequence: a read operation
  *           to UART3_SR register (UART3_GetFlagStatus()) followed by a write 
  *           operation to UART3_DR register (UART3_SendData8() or UART3_SendData9()).
  *             
  *         - TXE flag is cleared only by a write to the UART3_DR register 
  *           (UART3_SendData8() or UART3_SendData9()).
  *             
  *         - SBK flag is cleared during the stop bit of break.
  * @retval None
  */
void UART3_ClearFlag(UART3_Flag_TypeDef UART3_FLAG)
{
  /* Check the parameters */
  assert_param(IS_UART3_CLEAR_FLAG_OK(UART3_FLAG));
  
  /*Clear the Receive Register Not Empty flag */
  if (UART3_FLAG == UART3_FLAG_RXNE)
  {
    UART3->SR = (uint8_t)~(UART3_SR_RXNE);
  }
  /*Clear the LIN Break Detection flag */
  else if (UART3_FLAG == UART3_FLAG_LBDF)
  {
    UART3->CR4 &= (uint8_t)(~UART3_CR4_LBDF);
  }
  /*Clear the LIN Header Detection Flag */
  else if (UART3_FLAG == UART3_FLAG_LHDF)
  {
    UART3->CR6 &= (uint8_t)(~UART3_CR6_LHDF);
  }
  /*Clear the LIN Synch Field flag */
  else
  {
    UART3->CR6 &= (uint8_t)(~UART3_CR6_LSF);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
