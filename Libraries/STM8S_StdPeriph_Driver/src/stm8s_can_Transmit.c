
/**
  ********************************************************************************
  * @file    stm8s_can_Transmit.c
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
  * @brief  Initiates the transmission of a message.
  * @param   CAN_Id the ID number of the message, its size depends on @ref CAN_IDE value.
  * @param[in] CAN_IDE the ID type of the message, this parameter can be one of the @ref CAN_Id_TypeDef enumeration.
  * @param[in] CAN_RTR the message type, this parameter can be one of the @ref CAN_RTR_TypeDef enumeration.
  * @param[in] CAN_DLC the number of data in the message type, this parameter can be a value between 0 to 7.
  * @param[in] CAN_Data pointer to a the @ref uint8_t table which contains data to sent.
  * @retval Transmit Status, this returned value can be one of the @ref CAN_TxStatus_TypeDef enumeration.
  */
CAN_TxStatus_TypeDef CAN_Transmit(uint32_t CAN_Id,
                                  CAN_Id_TypeDef CAN_IDE,
                                  CAN_RTR_TypeDef CAN_RTR,
                                  uint8_t CAN_DLC,
                                  uint8_t *CAN_Data)
{
  CAN_TxStatus_TypeDef CAN_TxStatus = CAN_TxStatus_NoMailBox;
  CAN_Page_TypeDef can_page = CAN_GetSelectedPage();
  /* Check the parameters */
  assert_param(IS_CAN_IDTYPE_OK(CAN_IDE));
  if (CAN_IDE != CAN_Id_Standard)
  {
    assert_param(IS_CAN_EXTID_OK(CAN_Id));
  }
  else
  {
    assert_param(IS_CAN_STDID_OK(CAN_Id));
  }
  assert_param(IS_CAN_RTR_OK(CAN_RTR));
  assert_param(IS_CAN_DLC_OK(CAN_DLC));
  /* Select one empty transmit mailbox */
  if ((CAN->TPR & CAN_TPR_TME0) == CAN_TPR_TME0)
  {
    CAN_TxStatus = CAN_TxStatus_MailBox0Ok;
  }
  else if ((CAN->TPR & CAN_TPR_TME1) == CAN_TPR_TME1)
  {
    CAN_TxStatus = CAN_TxStatus_MailBox1Ok;
  }
  else if ((CAN->TPR & CAN_TPR_TME2) == CAN_TPR_TME2)
  {
    CAN_TxStatus = CAN_TxStatus_MailBox2Ok;
  }
  else
  {
    CAN_TxStatus = CAN_TxStatus_NoMailBox;
  }
  if (CAN_TxStatus != CAN_TxStatus_NoMailBox)
  {
    CAN->PSR = (uint8_t)CAN_TxStatus;
    /* Set up the Id */
    if (CAN_IDE != CAN_Id_Standard)
    {
      CAN_Id &= (uint32_t)CAN_EXTID_SIZE;
      CAN->Page.TxMailbox.MIDR4 = (uint8_t)(CAN_Id);
      CAN_Id = CAN_Id>>8;
      CAN->Page.TxMailbox.MIDR3 = (uint8_t)(CAN_Id);
      CAN_Id = CAN_Id>>8;
      CAN->Page.TxMailbox.MIDR2 = (uint8_t)(CAN_Id);
      CAN_Id = CAN_Id>>8;
      CAN->Page.TxMailbox.MIDR1 = (uint8_t)(CAN_Id |CAN_IDE | CAN_RTR);
    }
    else
    {
      CAN_Id &= (uint16_t)CAN_STDID_SIZE;
      CAN->Page.TxMailbox.MIDR1 = (uint8_t)((CAN_Id>>6) | (CAN_RTR)) ;
      CAN->Page.TxMailbox.MIDR2 = (uint8_t)(CAN_Id<<2);
    }
    /* Set up the DLC                 */
    /*clear old DLC value*/
    CAN->Page.TxMailbox.MDLCR &= (uint8_t)0xF0;
    /*set the new value of DLC*/
    CAN->Page.TxMailbox.MDLCR |= CAN_DLC;
    /* Set up the data field */
    CAN->Page.TxMailbox.MDAR1 = CAN_Data[0];
    CAN->Page.TxMailbox.MDAR2 = CAN_Data[1];
    CAN->Page.TxMailbox.MDAR3 = CAN_Data[2];
    CAN->Page.TxMailbox.MDAR4 = CAN_Data[3];
    CAN->Page.TxMailbox.MDAR5 = CAN_Data[4];
    CAN->Page.TxMailbox.MDAR6 = CAN_Data[5];
    CAN->Page.TxMailbox.MDAR7 = CAN_Data[6];
    CAN->Page.TxMailbox.MDAR8 = CAN_Data[7];
    /* Request transmission */
    CAN->Page.TxMailbox.MCSR |= CAN_MCSR_TXRQ;
  }
  /*Restore Last Page*/
  CAN_SelectPage(can_page);
  return (CAN_TxStatus_TypeDef)CAN_TxStatus;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
