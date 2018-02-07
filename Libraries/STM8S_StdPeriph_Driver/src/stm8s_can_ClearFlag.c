
/**
  ********************************************************************************
  * @file    stm8s_can_ClearFlag.c
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
  * @brief  Clears the CAN's pending flags.
  * @param   CAN_FLAG : Flag to be cleared, can be one of the following parameters:
  *          CAN_FLAG_RQCP0            Request MailBox0  Flag
  *          CAN_FLAG_RQCP1            Request MailBox1  Flag
  *          CAN_FLAG_RQCP2            Request MailBox2  Flag
  *       CAN_FLAG_FF               FIFO Full  Flag
  *       CAN_FLAG_FOV              FIFO Overrun  Flag
  *       CAN_FLAG_WKU              wake up   Flag
  *          CAN_FLAG_LEC               Last error code Flag
  * @retval None
  */
void CAN_ClearFlag(CAN_FLAG_TypeDef CAN_Flag)
{
  CAN_Page_TypeDef can_page = (CAN_Page_TypeDef)0;
  /* Check the parameters */
  assert_param(IS_CAN_FLAG_CLEAR_OK(CAN_Flag));
  if (((uint16_t)CAN_Flag & 0x0700)!= RESET)
  {
    if (((uint16_t)CAN_Flag & 0x020B)!= RESET)
    {
      /*Receive Flags*/
      CAN->RFR = (uint8_t)(CAN_Flag);
    }
    else if (((uint16_t)CAN_Flag & 0x0403)!= RESET)
    {
      /*Transmit Flags*/
      CAN->TSR = (uint8_t)(CAN_Flag);
    }
    else /*if((CAN_Flag & 0x0108)!=(uint16_t)RESET)*/
    {
      /*wake up Flags*/
      CAN->MSR = (uint8_t)(CAN_Flag);
    }
  }
  else
  {
    /*Error Flags*/
    can_page = CAN_GetSelectedPage();
    
    /* Clear the selected CAN flags */
    CAN->PSR = CAN_Page_Config;
    CAN->Page.Config.ESR = (uint8_t)RESET;
    
    /*Restore Last Page*/
    CAN_SelectPage(can_page);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
