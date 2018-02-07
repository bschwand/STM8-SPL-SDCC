
/**
  ********************************************************************************
  * @file    stm8s_can_Init.c
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
  * @brief  Initializes the CAN peripheral according to the specified parameters.
  * @param   CAN_MasterCtrl : Master control option, can be one or a combination of @ref CAN_MasterCtrl_TypeDef.
  * @param   CAN_Mode : CAN mode , can be one of @ref CAN_Mode_TypeDef.
  * @param   CAN_SynJumpWidth : CAN Synchronisation Jump Width , can be one of @ref CAN_SynJumpWidth_TypeDef.
  * @param   CAN_BitSeg1 : CAN bit segment 1 , can be one of @ref CAN_BitSeg1_TypeDef.
  * @param   CAN_BitSeg2 : CAN bit segment 2 , can be one of @ref CAN_BitSeg2_TypeDef.
  * @param   CAN_Prescaler : CAN Baud Rate Prescaler , can be a value from 0x01 to 0xFF.
  * @retval Indicates if initialization is succeed. it can be one of @ref CAN_InitStatus_TypeDef enumeration.
  */
CAN_InitStatus_TypeDef CAN_Init(CAN_MasterCtrl_TypeDef CAN_MasterCtrl,
                                CAN_Mode_TypeDef CAN_Mode,
                                CAN_SynJumpWidth_TypeDef CAN_SynJumpWidth,
                                CAN_BitSeg1_TypeDef CAN_BitSeg1,
                                CAN_BitSeg2_TypeDef CAN_BitSeg2,
                                uint8_t CAN_Prescaler)
{
  CAN_InitStatus_TypeDef InitStatus =  CAN_InitStatus_Failed;
  uint16_t timeout = CAN_ACKNOWLEDGE_TIMEOUT;
  CAN_Page_TypeDef can_page = CAN_GetSelectedPage();
  
  
  /* Check the parameters */
  assert_param(IS_CAN_MASTERCTRL_OK(CAN_MasterCtrl));
  assert_param(IS_CAN_MODE_OK(CAN_Mode));
  assert_param(IS_CAN_SYNJUMPWIDTH_OK(CAN_SynJumpWidth));
  assert_param(IS_CAN_BITSEG1_OK(CAN_BitSeg1));
  assert_param(IS_CAN_BITSEG2_OK(CAN_BitSeg2));
  assert_param(IS_CAN_PRESCALER_OK(CAN_Prescaler));
  
  /* Request initialisation */
  CAN->MCR = CAN_MCR_INRQ;
  /* Wait the acknowledge */
  while (((uint8_t)(CAN->MSR & CAN_MSR_INAK) != 0x01) && ((uint16_t)timeout != 0))
  {
    timeout--;
  }
  
  /* Check acknowledged */
  if ((CAN->MSR & CAN_MSR_INAK) != CAN_MSR_INAK)
  {
    
    InitStatus =  CAN_InitStatus_Failed;
    
  }
  else
  {
    /* Set the time triggered communication mode  &  Set the automatic bus-off management  &   Set the automatic wake-up mode
    &     Set the no automatic retransmission & Set the receive FIFO locked mode & Set the transmit FIFO priority */
    CAN->MCR |= (uint8_t)CAN_MasterCtrl;
    
    /* Set the bit timing register */
    CAN->DGR |= (uint8_t)CAN_Mode ;
    CAN->PSR = CAN_Page_Config;
    CAN->Page.Config.BTR1 = (uint8_t)((uint8_t)(CAN_Prescaler - (uint8_t)1) | CAN_SynJumpWidth);
    CAN->Page.Config.BTR2 = (uint8_t)(CAN_BitSeg1 | (uint8_t)CAN_BitSeg2);
    
    /* Request leave initialisation */
    CAN->MCR &= (uint8_t)(~CAN_MCR_INRQ);
    /* Wait the acknowledge */
    timeout = 0xFFFF;
    while ((((uint8_t)(CAN->MSR & CAN_MSR_INAK) == 0x01))&&(timeout != 0))
    {
      timeout--;
    }
    /* Check acknowledged */
    if ((CAN->MSR & CAN_MSR_INAK) == CAN_MSR_INAK)
    {
      InitStatus = CAN_InitStatus_Failed;
    }
    else
    {
      InitStatus = CAN_InitStatus_Success;
    }
  }
  /*Restore Last Page*/
  CAN_SelectPage(can_page);
  
  /* Return the status of initialization */
  return (CAN_InitStatus_TypeDef)InitStatus;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
