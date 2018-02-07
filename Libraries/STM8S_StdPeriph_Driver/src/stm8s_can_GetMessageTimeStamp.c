
/**
  ********************************************************************************
  * @file    stm8s_can_GetMessageTimeStamp.c
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
  * @brief  Returns the Received time stamp.
  * @param  None
  * @retval uint16_t the received  time stamp.
  */
uint16_t CAN_GetMessageTimeStamp(void)
{
  uint16_t timestamp = 0;
  CAN_Page_TypeDef can_page = CAN_GetSelectedPage();
  
  /*switch to the specific page */
  CAN->PSR = CAN_Page_RxFifo;
  /* Get the Received Time stamp */
  timestamp = CAN->Page.RxFIFO.MTSRL;
  timestamp |= (uint16_t)(((uint16_t)CAN->Page.RxFIFO.MTSRH)<<8);
  
  /*Restore Last Page*/
  CAN_SelectPage(can_page);
  
  return (uint16_t)(timestamp);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
