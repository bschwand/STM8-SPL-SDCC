
/**
  ********************************************************************************
  * @file    stm8s_can_TTComModeCmd.c
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
  * @brief  Enables or disables the CAN Time TriggerOperation communication mode.
  * @param   NewState : Mode new state , can be one of @ref FunctionalState
  * @retval None
  */
void CAN_TTComModeCmd(FunctionalState NewState)
{
  CAN_Page_TypeDef can_page = CAN_GetSelectedPage();
  /* Check the parameters */
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  if (NewState != DISABLE)
  {
    /*Enable the TTCM mode */
    CAN->MCR |= CAN_MCR_TTCM;
    /*Set TGT bits setting in Tx and FIFO pages*/
    CAN->PSR = CAN_Page_TxMailBox0;
    CAN->Page.TxMailbox.MDLCR |= CAN_MDLCR_TGT;
    CAN->PSR = CAN_Page_TxMailBox1;
    CAN->Page.TxMailbox.MDLCR |= CAN_MDLCR_TGT;
    CAN->PSR = CAN_Page_TxMailBox2;
    CAN->Page.TxMailbox.MDLCR |= CAN_MDLCR_TGT;
    CAN->PSR = CAN_Page_RxFifo;
    CAN->Page.RxFIFO.MDLCR |= CAN_MDLCR_TGT;
  }
  else
  {
    /*Disable the TTCM mode */
    CAN->MCR &= ((uint8_t)~CAN_MCR_TTCM);
    /*Reset TGT bits setting in Tx and FIFO pages*/
    CAN->PSR = CAN_Page_TxMailBox0;
    CAN->Page.TxMailbox.MDLCR &= ((uint8_t)~CAN_MDLCR_TGT);
    CAN->PSR = CAN_Page_TxMailBox1;
    CAN->Page.TxMailbox.MDLCR &= ((uint8_t)~CAN_MDLCR_TGT);
    CAN->PSR = CAN_Page_TxMailBox2;
    CAN->Page.TxMailbox.MDLCR &= ((uint8_t)~CAN_MDLCR_TGT);
    CAN->PSR = CAN_Page_RxFifo;
    CAN->Page.RxFIFO.MDLCR &= ((uint8_t)~CAN_MDLCR_TGT);
  }
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
