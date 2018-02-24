
/**
  ********************************************************************************
  * @file    stm8s_can_private.c
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

/* Private variables ---------------------------------------------------------*/
__IO uint32_t _Id = 0;
__IO uint8_t _IDE = 0;
__IO uint8_t _RTR = 0;
__IO uint8_t _DLC = 0;
__IO uint8_t _Data[8] = {0};
__IO uint8_t _FMI = 0;

/**
  * @brief  Checks whether the CAN interrupt has occurred or not.
  * @param   CAN_Reg: specifies the CAN interrupt register to check.
  * @param   It_Bit: specifies the interrupt source bit to check.
  * @retval The new state of the CAN Interrupt, which can be one of ITStatus.
  */
ITStatus CheckITStatus(uint8_t CAN_Reg, uint8_t It_Bit)
{
  ITStatus pendingbitstatus = RESET;
  if ((CAN_Reg & It_Bit) != (uint8_t)RESET)
  {
    /* CAN_IT is set */
    pendingbitstatus = SET;
  }
  else
  {
    /* CAN_IT is reset */
    pendingbitstatus = RESET;
  }
  return (ITStatus)pendingbitstatus;
}

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
