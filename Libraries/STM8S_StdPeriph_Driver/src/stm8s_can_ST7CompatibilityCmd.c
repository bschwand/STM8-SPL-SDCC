
/**
  ********************************************************************************
  * @file    stm8s_can_ST7CompatibilityCmd.c
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
#include "stm8s_can.h"
#include "private/stm8s_can_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup CAN_Public_Functions
  * @{
  */

/**
  * @brief   Enables or Disables the ST7 CAN Compatibility.
  * if the ST7 compatibility is Enabled, CAN provides only 2 mailboxes.
  * if the ST7 compatibility is Disabled, CAN provides 3 mailboxes.
  * @param   CAN_ST7Compatibility : CAN ST7 Compatibility , this parameter can be one of @ref CAN_ST7Compatibility_TypeDef enumeration.
  * @retval None
  */
void CAN_ST7CompatibilityCmd(CAN_ST7Compatibility_TypeDef CAN_ST7Compatibility)
{
  /* Check the parameters */
  assert_param(IS_CAN_ST7_COMPATIBILITY_OK(CAN_ST7Compatibility));
  /*Reset the old configuration of TXM2E */
  CAN->DGR &= (uint8_t)(~CAN_DGR_TXM2E);
  
  /*Set the old configuration of TXM2E */
  CAN->DGR |= (uint8_t)CAN_ST7Compatibility;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
