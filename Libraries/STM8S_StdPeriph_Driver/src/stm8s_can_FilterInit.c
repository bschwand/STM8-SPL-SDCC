
/**
  ********************************************************************************
  * @file    stm8s_can_FilterInit.c
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
  * @brief  Initializes the CAN peripheral Filter according to the specified parameters.
  * @param   CAN_FilterNumber : CAN Filter number , can be one of @ref CAN_FilterNumber_TypeDef
  * @param   CAN_FilterActivation : CAN Filter Activation state , can be one of @ref FunctionalState
  * @param   CAN_FilterMode : CAN Filter Mode , can be one of @ref CAN_FilterMode_TypeDef
  * @param   CAN_FilterScale : CAN Filter Scale , can be one of @ref CAN_FilterScale_TypeDef
  * @param   CAN_FilterID1 : CAN Filter ID 1 , can be a value from 0x00 to 0xFF
  * @param   CAN_FilterID2 : CAN Filter ID 2 , can be a value from 0x00 to 0xFF
  * @param   CAN_FilterID3 : CAN Filter ID 3 , can be a value from 0x00 to 0xFF
  * @param   CAN_FilterID4 : CAN Filter ID 4 , can be a value from 0x00 to 0xFF
  * @param   CAN_FilterIDMask1 : CAN Filter ID 1/ Mask 1  , can be a value from 0x00 to 0xFF depending of CAN_FilterMode parameter
  * @param   CAN_FilterIDMask2 : CAN Filter ID 2/ Mask 2 , can be a value from 0x00 to 0xFF depending of CAN_FilterMode parameter
  * @param   CAN_FilterIDMask3 : CAN Filter ID 3/ Mask 3 , can be a value from 0x00 to 0xFF depending of CAN_FilterMode parameter
  * @param   CAN_FilterIDMask4 : CAN Filter ID 4/ Mask 4 , can be a value from 0x00 to 0xFF depending of CAN_FilterMode parameter
  * @retval None
  */
void CAN_FilterInit(CAN_FilterNumber_TypeDef CAN_FilterNumber,
                    FunctionalState CAN_FilterActivation,
                    CAN_FilterMode_TypeDef CAN_FilterMode,
                    CAN_FilterScale_TypeDef CAN_FilterScale,
                    uint8_t CAN_FilterID1,
                    uint8_t CAN_FilterID2,
                    uint8_t CAN_FilterID3,
                    uint8_t CAN_FilterID4,
                    uint8_t CAN_FilterIDMask1,
                    uint8_t CAN_FilterIDMask2,
                    uint8_t CAN_FilterIDMask3,
                    uint8_t CAN_FilterIDMask4)
{
  uint8_t fact = 0;
  uint8_t fsc  = 0;
  uint8_t fmhl = 0;
  
  CAN_Page_TypeDef can_page_filter = CAN_Page_Filter01;
  CAN_Page_TypeDef can_page = CAN_GetSelectedPage();
  
  /* Check the parameters */
  assert_param(IS_CAN_FILTER_NUMBER_OK(CAN_FilterNumber));
  assert_param(IS_FUNCTIONALSTATE_OK(CAN_FilterActivation));
  assert_param(IS_CAN_FILTER_MODE_OK(CAN_FilterMode));
  assert_param(IS_CAN_FILTER_SCALE_OK(CAN_FilterScale));
  
  
  if (CAN_FilterNumber == CAN_FilterNumber_0)
  {
    fact = 0x01;
    fsc  = 0x00;
    fmhl = 0x03;
    
    can_page_filter = CAN_Page_Filter01;
  }
  else if (CAN_FilterNumber == CAN_FilterNumber_1)
  {
    fact = 0x10;
    fsc  = 0x04;
    fmhl = 0x0C;
    
    can_page_filter = CAN_Page_Filter01;
  }
  else if (CAN_FilterNumber == CAN_FilterNumber_2)
  {
    fact = 0x01;
    fsc  = 0x00;
    fmhl = 0x30;
    
    can_page_filter = CAN_Page_Filter23;
  }
  else if (CAN_FilterNumber == CAN_FilterNumber_3)
  {
    fact = 0x10;
    fsc  = 0x04;
    fmhl = 0xC0;
    
    can_page_filter = CAN_Page_Filter23;
  }
  else if (CAN_FilterNumber == CAN_FilterNumber_4)
  {
    fact = 0x01;
    fsc  = 0x00;
    fmhl = 0x03;
    
    can_page_filter = CAN_Page_Filter45;
  }
  else /*if (CAN_FilterNumber == CAN_FilterNumber_5)*/
  {
    fact = 0x10;
    fsc  = 0x04;
    fmhl = 0x0C;
    
    can_page_filter = CAN_Page_Filter45;
  }
  
  
  CAN_OperatingModeRequest(CAN_OperatingMode_Initialization);
  
  CAN->PSR = CAN_Page_Config;
  /*---------------------------------------------------------*/
  /*Configuration of Filter Scale                            */
  /*---------------------------------------------------------*/
  
  if (can_page_filter == CAN_Page_Filter01) /* FCR1 */
  {
    /* Filter Deactivation  & Reset the Filter Scale */
    CAN->Page.Config.FCR1 &= (uint8_t)(~(uint8_t)(fact | (uint8_t)((uint8_t)(CAN_FCR1_FSC00|CAN_FCR1_FSC01) << fsc )));
    /* Set the new Filter Scale */
    CAN->Page.Config.FCR1 |= (uint8_t)(CAN_FilterScale << fsc);
  }
  else if (can_page_filter == CAN_Page_Filter23) /* FCR2*/
  {
    /* Filter Deactivation  & Reset the Filter Scale */
    CAN->Page.Config.FCR2 &= (uint8_t)~(uint8_t)( fact | (uint8_t)((uint8_t)(CAN_FCR1_FSC00|CAN_FCR1_FSC01) << fsc ));
    
    /* Set the new Filter Scale */
    CAN->Page.Config.FCR2 |= (uint8_t)(CAN_FilterScale << fsc);
    
  }
  else /*if(can_page_filter == CAN_Page_Filter45)*/ /* FCR3*/
  {
    /* Filter Deactivation  & Reset the Filter Scale */
    CAN->Page.Config.FCR3 &= (uint8_t)~(uint8_t)( fact | (uint8_t)((uint8_t)(CAN_FCR1_FSC00|CAN_FCR1_FSC01) << fsc ));
    
    /* Set the new Filter Scale */
    CAN->Page.Config.FCR3 |= (uint8_t)(CAN_FilterScale << fsc);
  }
  
  /*---------------------------------------------------------*/
  /*Configuration of Filter Mode                             */
  /*---------------------------------------------------------*/
  if (can_page_filter != CAN_Page_Filter45) /* FMR1*/
  {
    /* Filter Mode */
    if (CAN_FilterMode == CAN_FilterMode_IdMask)
    {
      /*Id/Mask mode for the filter*/
      CAN->Page.Config.FMR1 &= (uint8_t)~(fmhl);
    }
    else if ( CAN_FilterMode == CAN_FilterMode_IdList)
    {
      /*Identifier list mode for the filter*/
      CAN->Page.Config.FMR1 |= (uint8_t)(fmhl);
    }
    else if ( CAN_FilterMode == CAN_FilterMode_IdList_IdMask)
    {
      /*Identifier list mode is first  for the filter*/
      CAN->Page.Config.FMR1 |= (uint8_t)(fmhl & CAN_IDLIST_IDMASK_MASK);
    }
    else /* ( CAN_FilterMode == CAN_FilterMode_IdMask_IdList)*/
    {
      /*Id Mask mode is first  for the filter*/
      CAN->Page.Config.FMR1 |= (uint8_t)(fmhl & CAN_IDMASK_IDLIST_MASK);
    }
    
    
  }
  else /* FMR2 */
  {
    
    /* Filter Mode */
    if (CAN_FilterMode == CAN_FilterMode_IdMask)
    {
      /*Id/Mask mode for the filter*/
      CAN->Page.Config.FMR2 &= (uint8_t)~(fmhl);
    }
    else if ( CAN_FilterMode == CAN_FilterMode_IdList)
    {
      /*Identifier list mode for the filter*/
      CAN->Page.Config.FMR2 |= (uint8_t)(fmhl);
    }
    else if ( CAN_FilterMode == CAN_FilterMode_IdList_IdMask)
    {
      /*Identifier list mode is first  for the filter*/
      CAN->Page.Config.FMR2 |= (uint8_t)(fmhl & CAN_IDLIST_IDMASK_MASK);
    }
    else /* ( CAN_FilterMode == CAN_FilterMode_IdMask_IdList)*/
    {
      /*Id Mask mode is first  for the filter*/
      CAN->Page.Config.FMR2 |= (uint8_t)(fmhl & CAN_IDMASK_IDLIST_MASK);
    }
  }
  /*---------------------------------------------------------*/
  /*Configuration of Filter IDs                              */
  /*---------------------------------------------------------*/
  CAN->PSR = (uint8_t)can_page_filter;
  if (fsc != 0)
  {
    /* Filter Scale */
    if (CAN_FilterScale == CAN_FilterScale_8Bit)
    {
      CAN->Page.Filter.FR09 = CAN_FilterID1;
      CAN->Page.Filter.FR10 = CAN_FilterIDMask1;
      CAN->Page.Filter.FR11 = CAN_FilterID2;
      CAN->Page.Filter.FR12 = CAN_FilterIDMask2;
      CAN->Page.Filter.FR13 = CAN_FilterID3;
      CAN->Page.Filter.FR14 = CAN_FilterIDMask3;
      CAN->Page.Filter.FR15 = CAN_FilterID4;
      CAN->Page.Filter.FR16 = CAN_FilterIDMask4;
    }
    else if (CAN_FilterScale == CAN_FilterScale_16_8Bit)
    {
      CAN->Page.Filter.FR09 = CAN_FilterID1;
      CAN->Page.Filter.FR10 = CAN_FilterID2;
      CAN->Page.Filter.FR11 = CAN_FilterIDMask1;
      CAN->Page.Filter.FR12 = CAN_FilterIDMask2;
      CAN->Page.Filter.FR13 = CAN_FilterID3;
      CAN->Page.Filter.FR14 = CAN_FilterIDMask3;
      CAN->Page.Filter.FR15 = CAN_FilterID4;
      CAN->Page.Filter.FR16 = CAN_FilterIDMask4;
    }
    else if (CAN_FilterScale == CAN_FilterScale_16Bit)
    {
      CAN->Page.Filter.FR09 = CAN_FilterID1;
      CAN->Page.Filter.FR10 = CAN_FilterID2;
      CAN->Page.Filter.FR11 = CAN_FilterIDMask1;
      CAN->Page.Filter.FR12 = CAN_FilterIDMask2;
      CAN->Page.Filter.FR13 = CAN_FilterID3;
      CAN->Page.Filter.FR14 = CAN_FilterID4;
      CAN->Page.Filter.FR15 = CAN_FilterIDMask3;
      CAN->Page.Filter.FR16 = CAN_FilterIDMask4;
    }
    else if (CAN_FilterScale == CAN_FilterScale_32Bit)
    {
      CAN->Page.Filter.FR09 = CAN_FilterID1;
      CAN->Page.Filter.FR10 = CAN_FilterID2;
      CAN->Page.Filter.FR11 = CAN_FilterID3;
      CAN->Page.Filter.FR12 = CAN_FilterID4;
      CAN->Page.Filter.FR13 = CAN_FilterIDMask1;
      CAN->Page.Filter.FR14 = CAN_FilterIDMask2;
      CAN->Page.Filter.FR15 = CAN_FilterIDMask3;
      CAN->Page.Filter.FR16 = CAN_FilterIDMask4;
    }
  }
  else
  {
    /* Filter Scale */
    if (CAN_FilterScale == CAN_FilterScale_8Bit)
    {
      CAN->Page.Filter.FR01 = CAN_FilterID1;
      CAN->Page.Filter.FR02 = CAN_FilterIDMask1;
      CAN->Page.Filter.FR03 = CAN_FilterID2;
      CAN->Page.Filter.FR04 = CAN_FilterIDMask2;
      CAN->Page.Filter.FR05 = CAN_FilterID3;
      CAN->Page.Filter.FR06 = CAN_FilterIDMask3;
      CAN->Page.Filter.FR07 = CAN_FilterID4;
      CAN->Page.Filter.FR08 = CAN_FilterIDMask4;
    }
    else if (CAN_FilterScale == CAN_FilterScale_16_8Bit)
    {
      CAN->Page.Filter.FR01 = CAN_FilterID1;
      CAN->Page.Filter.FR02 = CAN_FilterID2;
      CAN->Page.Filter.FR03 = CAN_FilterIDMask1;
      CAN->Page.Filter.FR04 = CAN_FilterIDMask2;
      CAN->Page.Filter.FR05 = CAN_FilterID3;
      CAN->Page.Filter.FR06 = CAN_FilterIDMask3;
      CAN->Page.Filter.FR07 = CAN_FilterID4;
      CAN->Page.Filter.FR08 = CAN_FilterIDMask4;
    }
    else if (CAN_FilterScale == CAN_FilterScale_16Bit)
    {
      CAN->Page.Filter.FR01 = CAN_FilterID1;
      CAN->Page.Filter.FR02 = CAN_FilterID2;
      CAN->Page.Filter.FR03 = CAN_FilterIDMask1;
      CAN->Page.Filter.FR04 = CAN_FilterIDMask2;
      CAN->Page.Filter.FR05 = CAN_FilterID3;
      CAN->Page.Filter.FR06 = CAN_FilterID4;
      CAN->Page.Filter.FR07 = CAN_FilterIDMask3;
      CAN->Page.Filter.FR08 = CAN_FilterIDMask4;
    }
    else if (CAN_FilterScale == CAN_FilterScale_32Bit)
    {
      CAN->Page.Filter.FR01 = CAN_FilterID1;
      CAN->Page.Filter.FR02 = CAN_FilterID2;
      CAN->Page.Filter.FR03 = CAN_FilterID3;
      CAN->Page.Filter.FR04 = CAN_FilterID4;
      CAN->Page.Filter.FR05 = CAN_FilterIDMask1;
      CAN->Page.Filter.FR06 = CAN_FilterIDMask2;
      CAN->Page.Filter.FR07 = CAN_FilterIDMask3;
      CAN->Page.Filter.FR08 = CAN_FilterIDMask4;
    }
  }
  
  
  /*---------------------------------------------------------*/
  /*Configuration of Filter Activation                       */
  /*---------------------------------------------------------*/
  /* Filter activation */
  CAN->PSR = CAN_Page_Config;
  if (CAN_FilterActivation != DISABLE)
  {
    if ((CAN_FilterNumber & 0x06) == 0x00) /* FCR1*/
    {   CAN->Page.Config.FCR1 |= (uint8_t)fact;
    }
    else if ((CAN_FilterNumber & 0x06) == 0x02) /*FCR2*/
    { CAN->Page.Config.FCR2 |= (uint8_t)fact;
    }
    else /*if((CAN_FilterNumber & 0x06) == 0x04)*/ /*FCR3*/
    { CAN->Page.Config.FCR3 |= (uint8_t)fact;
    }
  }
  CAN_OperatingModeRequest(CAN_OperatingMode_Normal);
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
