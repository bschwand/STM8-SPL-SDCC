
/**
  ********************************************************************************
  * @file    stm8s_can_GetReceivedData.c
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
  * @brief  Gets the  CAN Data of the received message.
  * @param   CAN_DataIndexe : number of the received Data, it can
  *  be an integer between 0 to 7.
  * @retval the received CAN message ith Data.
  * @par Required preconditions:
  * This function is used to get data loaded by CAN_Receive function.
  * Before using this function, CAN_Receive function must be called.
  */
uint8_t CAN_GetReceivedData(uint8_t CAN_DataIndex)
{
  assert_param(IS_CAN_DLC_OK(CAN_DataIndex));
  return (_Data[CAN_DataIndex]);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
