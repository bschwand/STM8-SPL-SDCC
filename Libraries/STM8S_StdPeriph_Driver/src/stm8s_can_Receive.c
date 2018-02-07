
/**
  ********************************************************************************
  * @file    stm8s_can_Receive.c
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
  * @brief   Receives a message which contains CAN Id, IDE, RTR
  * DLC, data and FMI number.
  * In order to get these data, use CAN_GetReceivedId(), CAN_GetReceivedIDE(), CAN_GetReceivedRTR(),
  * CAN_GetReceivedDLC(), CAN_GetReceivedFMI() and CAN_GetReceivedData() functions.
  * @param  None
  * @retval None
  */
void CAN_Receive(void)
{
  CAN_Page_TypeDef can_page = CAN_GetSelectedPage();
  uint32_t temp1 = 0, temp2 = 0, temp3 = 0;
  
  /* select Fifo page*/
  CAN->PSR = CAN_Page_RxFifo;
  
  /* Get the Id */
  _IDE = (uint8_t)(CAN->Page.RxFIFO.MIDR1 & CAN_Id_Extended);
  if (_IDE != CAN_Id_Standard)
  {
    temp1 = ((uint32_t)((uint32_t)CAN->Page.RxFIFO.MIDR3) << 8);
    temp2 = ((uint32_t)((uint32_t)CAN->Page.RxFIFO.MIDR2) << 16);  
    temp3 = ((uint32_t)((uint32_t)CAN->Page.RxFIFO.MIDR1 & 0x1F) << 24);
    
    _Id = (uint32_t)CAN_EXTID_SIZE & ((CAN->Page.RxFIFO.MIDR4) | temp1 | temp2 | temp3 );
  }
  else
  {
    temp1 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)CAN->Page.RxFIFO.MIDR1 & 0x1F) << 6));
    temp2 = (uint16_t)((uint16_t)((uint16_t)CAN->Page.RxFIFO.MIDR2 >> 2)&0x3F);
    
    _Id = (uint16_t)CAN_STDID_SIZE & (temp1 | temp2 );
  }
  
  _RTR = (uint8_t)((uint8_t)0x20 & CAN->Page.RxFIFO.MIDR1);
  
  /* Get the DLC */
  _DLC = (uint8_t)(CAN->Page.RxFIFO.MDLCR & (uint8_t)0x0F);
  
  /* Get the FMI */
  _FMI = CAN->Page.RxFIFO.MFMI;
  
  /* Get the data field */
  _Data[0] = CAN->Page.RxFIFO.MDAR1;
  _Data[1] = CAN->Page.RxFIFO.MDAR2;
  _Data[2] = CAN->Page.RxFIFO.MDAR3;
  _Data[3] = CAN->Page.RxFIFO.MDAR4;
  _Data[4] = CAN->Page.RxFIFO.MDAR5;
  _Data[5] = CAN->Page.RxFIFO.MDAR6;
  _Data[6] = CAN->Page.RxFIFO.MDAR7;
  _Data[7] = CAN->Page.RxFIFO.MDAR8;
  
  /* Release the FIFO */
  CAN_FIFORelease();
  /*Restore Last Page*/
  CAN_SelectPage(can_page);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
