
/**
  ********************************************************************************
  * @file    stm8s_uart4_DeInit.c
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
  * @brief  Deinitializes the UART peripheral.
  * @param  None
  * @retval None
  */

void UART4_DeInit(void)
{
  /*  Clear the Idle Line Detected bit in the status register by a read
  to the UART4_SR register followed by a Read to the UART4_DR register */
  (void)UART4->SR;
  (void)UART4->DR;
  
  UART4->BRR2 = UART4_BRR2_RESET_VALUE;  /*  Set UART4_BRR2 to reset value 0x00 */
  UART4->BRR1 = UART4_BRR1_RESET_VALUE;  /*  Set UART4_BRR1 to reset value 0x00 */
  
  UART4->CR1 = UART4_CR1_RESET_VALUE; /*  Set UART4_CR1 to reset value 0x00  */
  UART4->CR2 = UART4_CR2_RESET_VALUE; /*  Set UART4_CR2 to reset value 0x00  */
  UART4->CR3 = UART4_CR3_RESET_VALUE; /*  Set UART4_CR3 to reset value 0x00  */
  UART4->CR4 = UART4_CR4_RESET_VALUE; /*  Set UART4_CR4 to reset value 0x00  */
  UART4->CR5 = UART4_CR5_RESET_VALUE; /*  Set UART4_CR5 to reset value 0x00  */
  UART4->CR6 = UART4_CR6_RESET_VALUE; /*  Set UART4_CR6 to reset value 0x00  */
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
