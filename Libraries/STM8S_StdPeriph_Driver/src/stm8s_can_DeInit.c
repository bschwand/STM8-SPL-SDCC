
/**
  ********************************************************************************
  * @file    stm8s_can_DeInit.c
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
  * @brief  Deinitializes the CAN peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void CAN_DeInit(void)
{
  /* Request initialisation */
  CAN->MCR = CAN_MCR_INRQ;
  CAN->PSR = CAN_Page_Config;
  CAN_OperatingModeRequest(CAN_OperatingMode_Initialization);
  CAN->Page.Config.ESR = CAN_ESR_RESET_VALUE;
  CAN->Page.Config.EIER = CAN_EIER_RESET_VALUE;
  CAN->Page.Config.BTR1 = CAN_BTR1_RESET_VALUE;
  CAN->Page.Config.BTR2 = CAN_BTR2_RESET_VALUE;
  CAN->Page.Config.FMR1 = CAN_FMR1_RESET_VALUE;
  CAN->Page.Config.FMR2 = CAN_FMR2_RESET_VALUE;
  CAN->Page.Config.FCR1 = CAN_FCR_RESET_VALUE;
  CAN->Page.Config.FCR2 = CAN_FCR_RESET_VALUE;
  CAN->Page.Config.FCR3 = CAN_FCR_RESET_VALUE;
  CAN_OperatingModeRequest(CAN_OperatingMode_Normal);
  CAN->PSR = CAN_Page_RxFifo;
  CAN->Page.RxFIFO.MDLCR = CAN_MDLC_RESET_VALUE;
  CAN->PSR = CAN_Page_TxMailBox0;
  CAN->Page.TxMailbox.MDLCR = CAN_MDLC_RESET_VALUE;
  CAN->PSR = CAN_Page_TxMailBox1;
  CAN->Page.TxMailbox.MDLCR = CAN_MDLC_RESET_VALUE;
  CAN->PSR = CAN_Page_TxMailBox2;
  CAN->Page.TxMailbox.MDLCR = CAN_MDLC_RESET_VALUE;
  
  CAN->MCR = CAN_MCR_RESET_VALUE;
  CAN->MSR = (uint8_t)(~CAN_MSR_RESET_VALUE);/* rc_w1 */
  CAN->TSR = (uint8_t)(~CAN_TSR_RESET_VALUE);/* rc_w1 */
  CAN->RFR = (uint8_t)(~CAN_RFR_RESET_VALUE);/* rc_w1 */
  CAN->IER = CAN_IER_RESET_VALUE;
  CAN->DGR = CAN_DGR_RESET_VALUE;
  CAN->PSR = CAN_PSR_RESET_VALUE;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
