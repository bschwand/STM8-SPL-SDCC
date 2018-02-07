
/**
  ********************************************************************************
  * @file    stm8s_uart2_ClearFlag.c
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
#include "stm8s_uart2.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup UART2_Public_Functions
  * @{
  */

/**
  * @brief  Clears the UART2 flags.
  * @param  UART2_FLAG specifies the flag to clear
  *         This parameter can be any combination of the following values:
  *         - UART2_FLAG_LBDF: LIN Break detection flag.
  *         - UART2_FLAG_LHDF: LIN Header detection flag.
  *         - UART2_FLAG_LSF: LIN synchrone field flag.
  *         - UART2_FLAG_RXNE: Receive data register not empty flag.
  * @note:
  *         - PE (Parity error), FE (Framing error), NE (Noise error), 
  *           OR (OverRun error) and IDLE (Idle line detected) flags are cleared
  *           by software sequence: a read operation to UART2_SR register 
  *           (UART2_GetFlagStatus())followed by a read operation to UART2_DR 
  *           register(UART2_ReceiveData8() or UART2_ReceiveData9()).
  *        
  *         - RXNE flag can be also cleared by a read to the UART2_DR register
  *           (UART2_ReceiveData8()or UART2_ReceiveData9()).
  *
  *         - TC flag can be also cleared by software sequence: a read operation
  *           to UART2_SR register (UART2_GetFlagStatus()) followed by a write 
  *           operation to UART2_DR register (UART2_SendData8() or UART2_SendData9()).
  *             
  *         - TXE flag is cleared only by a write to the UART2_DR register 
  *           (UART2_SendData8() or UART2_SendData9()).
  *             
  *         - SBK flag is cleared during the stop bit of break.
  * @retval None
  */
void UART2_ClearFlag(UART2_Flag_TypeDef UART2_FLAG)
{
  assert_param(IS_UART2_CLEAR_FLAG_OK(UART2_FLAG));
  
  /*  Clear the Receive Register Not Empty flag */
  if (UART2_FLAG == UART2_FLAG_RXNE)
  {
    UART2->SR = (uint8_t)~(UART2_SR_RXNE);
  }
  /*  Clear the LIN Break Detection flag */
  else if (UART2_FLAG == UART2_FLAG_LBDF)
  {
    UART2->CR4 &= (uint8_t)(~UART2_CR4_LBDF);
  }
  /*  Clear the LIN Header Detection Flag */
  else if (UART2_FLAG == UART2_FLAG_LHDF)
  {
    UART2->CR6 &= (uint8_t)(~UART2_CR6_LHDF);
  }
  /*  Clear the LIN Synch Field flag */
  else
  {
    UART2->CR6 &= (uint8_t)(~UART2_CR6_LSF);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
