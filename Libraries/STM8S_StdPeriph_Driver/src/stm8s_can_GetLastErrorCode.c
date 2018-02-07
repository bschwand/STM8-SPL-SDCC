
/**
  ********************************************************************************
  * @file    stm8s_can_GetLastErrorCode.c
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
  * @brief  Gets the  Last Error Code.
  * @param  None
  * @retval Error Code.
  */
CAN_ErrorCode_TypeDef CAN_GetLastErrorCode(void)
{
  CAN_ErrorCode_TypeDef errcode = CAN_ErrorCode_NoErr;
  CAN_Page_TypeDef can_page = CAN_GetSelectedPage();
  
  CAN->PSR = CAN_Page_Config;
  errcode = (CAN_ErrorCode_TypeDef)((CAN->Page.Config.ESR) & (CAN_ESR_LEC));
  
  /*Restore Last Page*/
  CAN_SelectPage(can_page);
  
  return (CAN_ErrorCode_TypeDef)(errcode);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
