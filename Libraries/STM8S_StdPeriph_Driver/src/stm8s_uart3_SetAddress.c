
/**
  ********************************************************************************
  * @file    stm8s_uart3_SetAddress.c
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
  * @brief  Sets the address of the UART3 node.
  * @param  UART3_Address: Indicates the address of the UART3 node.
  * @retval None
  */
void UART3_SetAddress(uint8_t UART3_Address)
{
  /* Check the parameters */
  assert_param(IS_UART3_ADDRESS_OK(UART3_Address));
  
  /* Clear the UART3 address */
  UART3->CR4 &= ((uint8_t)~UART3_CR4_ADD);
  /* Set the UART3 address node */
  UART3->CR4 |= UART3_Address;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
