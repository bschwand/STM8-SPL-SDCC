
/**
  ********************************************************************************
  * @file    stm8s_can_TransmitStatus.c
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
  * @brief  Checks the transmission of a message.
  * @param   TransmitMailbox: the number of the mailbox that is used for transmission, can be on of  @ref CAN_TransmitMailBox_TypeDef.
  * @retval CAN_TxStatus_Ok if the CAN driver transmits the message, CAN_TxStatus_Failed in an other case.
  */
CAN_TxStatus_TypeDef CAN_TransmitStatus(CAN_TransmitMailBox_TypeDef CAN_TransmitMailbox)
{
  /* RQCP, TXOK and TME bits */
  CAN_TxStatus_TypeDef tstate = CAN_TxStatus_Failed;
  uint8_t tmpstate=0;
  
  /* Check the parameters */
  assert_param(IS_CAN_TRANSMITMAILBOX_OK(CAN_TransmitMailbox));
  
  switch (CAN_TransmitMailbox)
  {
  case (CAN_TransmitMailBox_0): tmpstate = (uint8_t)((CAN->TSR & (uint8_t)(CAN_TSR_RQCP0|CAN_TSR_TXOK0)));
  tmpstate |= (uint8_t)((CAN->TPR & CAN_TPR_TME0));
  break;
  case (CAN_TransmitMailBox_1): tmpstate = (uint8_t)((uint8_t)(CAN->TSR & (uint8_t)(CAN_TSR_RQCP1|CAN_TSR_TXOK1))>>1);
  tmpstate |= (uint8_t)((uint8_t)(CAN->TPR & CAN_TPR_TME1) >> 1);
  break;
  case (CAN_TransmitMailBox_2): tmpstate = (uint8_t)((uint8_t)(CAN->TSR & (uint8_t)(CAN_TSR_RQCP2|CAN_TSR_TXOK2))>>2);
  tmpstate |= (uint8_t)((uint8_t)(CAN->TPR & CAN_TPR_TME2) >> 2);
  break;
  default:
    tstate = CAN_TxStatus_Failed;
    break;
  }
  
  switch (tmpstate)
  {
    /*transmit pending  */
  case (0x00): tstate = CAN_TxStatus_Pending;
  break;
  /* transmit failed  */
  case (0x05): tstate = CAN_TxStatus_Failed;
  break;
  /* transmit succeeded */
  case (0x15): tstate = CAN_TxStatus_Ok;
  break;
  /* transmit mailbox is empty : no activity on this TX mail box */
  case (0x04): tstate = CAN_TxStatus_MailBoxEmpty;
  break;
  default:
    tstate = CAN_TxStatus_Failed;
    break;
  }
  
  return (CAN_TxStatus_TypeDef)tstate;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
