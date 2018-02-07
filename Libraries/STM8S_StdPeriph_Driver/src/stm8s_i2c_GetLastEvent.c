
/**
  ********************************************************************************
  * @file    stm8s_i2c_GetLastEvent.c
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
#include "stm8s_i2c.h"
#include "private/stm8s_i2c_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup I2C_Public_Functions
  * @{
  */

/**
  * @brief  Returns the last I2C Event.
  *
  * @note: For detailed description of Events, please refer to section
  *    I2C_Events in stm8s_i2c.h file.
  *
  * @retval The last event
  *   This parameter can be any of the  @ref I2C_Event_TypeDef enumeration.
  */
I2C_Event_TypeDef I2C_GetLastEvent(void)
{
  __IO uint16_t lastevent = 0;
  uint16_t flag1 = 0;
  uint16_t flag2 = 0;

  if ((I2C->SR2 & I2C_SR2_AF) != 0x00)
  {
    lastevent = I2C_EVENT_SLAVE_ACK_FAILURE;
  }
  else
  {
    /* Read the I2C status register */
    flag1 = I2C->SR1;
    flag2 = I2C->SR3;

    /* Get the last event value from I2C status register */
    lastevent = ((uint16_t)((uint16_t)flag2 << 8) | (uint16_t)flag1);
  }
  /* Return status */
  return (I2C_Event_TypeDef)lastevent;
}

/**
 *
 *  3) Flag-based state monitoring
 *******************************************************************************
 */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
