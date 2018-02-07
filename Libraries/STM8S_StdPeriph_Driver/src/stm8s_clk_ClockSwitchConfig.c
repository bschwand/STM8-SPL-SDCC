
/**
  ********************************************************************************
  * @file    stm8s_clk_ClockSwitchConfig.c
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
#include "stm8s_clk.h"
#include "private/stm8s_clk_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup CLK_Public_Functions
  * @{
  */

/**
  * @brief  configures the Switch from one clock to another
  * @param   CLK_SwitchMode select the clock switch mode.
  * It can be set of the values of @ref CLK_SwitchMode_TypeDef
  * @param   CLK_NewClock choice of the future clock.
  * It can be set of the values of @ref CLK_Source_TypeDef
  * @param   NewState Enable or Disable the Clock Switch interrupt.
  * @param   CLK_CurrentClockState current clock to switch OFF or to keep ON.
  * It can be set of the values of @ref CLK_CurrentClockState_TypeDef
  * @note LSI selected as master clock source only if LSI_EN option bit is set.
  * @retval ErrorStatus this shows the clock switch status (ERROR/SUCCESS).
  */
ErrorStatus CLK_ClockSwitchConfig(CLK_SwitchMode_TypeDef CLK_SwitchMode, CLK_Source_TypeDef CLK_NewClock, FunctionalState ITState, CLK_CurrentClockState_TypeDef CLK_CurrentClockState)
{
  CLK_Source_TypeDef clock_master;
  uint16_t DownCounter = CLK_TIMEOUT;
  ErrorStatus Swif = ERROR;
  
  /* Check the parameters */
  assert_param(IS_CLK_SOURCE_OK(CLK_NewClock));
  assert_param(IS_CLK_SWITCHMODE_OK(CLK_SwitchMode));
  assert_param(IS_FUNCTIONALSTATE_OK(ITState));
  assert_param(IS_CLK_CURRENTCLOCKSTATE_OK(CLK_CurrentClockState));
  
  /* Current clock master saving */
  clock_master = (CLK_Source_TypeDef)CLK->CMSR;
  
  /* Automatic switch mode management */
  if (CLK_SwitchMode == CLK_SWITCHMODE_AUTO)
  {
    /* Enables Clock switch */
    CLK->SWCR |= CLK_SWCR_SWEN;
    
    /* Enables or Disables Switch interrupt */
    if (ITState != DISABLE)
    {
      CLK->SWCR |= CLK_SWCR_SWIEN;
    }
    else
    {
      CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
    }
    
    /* Selection of the target clock source */
    CLK->SWR = (uint8_t)CLK_NewClock;
    
    /* Wait until the target clock source is ready */
    while((((CLK->SWCR & CLK_SWCR_SWBSY) != 0 )&& (DownCounter != 0)))
    {
      DownCounter--;
    }
    
    if(DownCounter != 0)
    {
      Swif = SUCCESS;
    }
    else
    {
      Swif = ERROR;
    }
  }
  else /* CLK_SwitchMode == CLK_SWITCHMODE_MANUAL */
  {
    /* Enables or Disables Switch interrupt  if required  */
    if (ITState != DISABLE)
    {
      CLK->SWCR |= CLK_SWCR_SWIEN;
    }
    else
    {
      CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
    }
    
    /* Selection of the target clock source */
    CLK->SWR = (uint8_t)CLK_NewClock;
    
    /* Wait until the target clock source is ready */
    while((((CLK->SWCR & CLK_SWCR_SWIF) != 0 ) && (DownCounter != 0)))
    {
      DownCounter--;
    }
    
    if(DownCounter != 0)
    {
      /* Enables Clock switch */
      CLK->SWCR |= CLK_SWCR_SWEN;
      Swif = SUCCESS;
    }
    else
    {
      Swif = ERROR;
    }
  }
  if(Swif != ERROR)
  {
    /* Switch OFF current clock if required */
    if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSI))
    {
      CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
    }
    else if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_LSI))
    {
      CLK->ICKR &= (uint8_t)(~CLK_ICKR_LSIEN);
    }
    else if ((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSE))
    {
      CLK->ECKR &= (uint8_t)(~CLK_ECKR_HSEEN);
    }
  }
  return(Swif);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
