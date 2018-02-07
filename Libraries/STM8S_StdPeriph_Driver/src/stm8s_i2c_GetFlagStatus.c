
/**
  ********************************************************************************
  * @file    stm8s_i2c_GetFlagStatus.c
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
  * @brief  Checks whether the specified I2C flag is set or not.
  * @param  I2C_FLAG: specifies the flag to check.
  *   This parameter can be one of the following values:
  *     @arg I2C_FLAG_GENERALCALL: General call header flag (Slave mode)
  *     @arg I2C_FLAG_TRANSMITTERRECEIVER: Transmitter/Receiver flag
  *     @arg I2C_FLAG_BUSBUSY: Bus busy flag
  *     @arg I2C_FLAG_MASTERSLAVE: Master/Slave flag
  *     @arg I2C_FLAG_WAKEUPFROMHALT: Wake up from HALT flag  
  *     @arg I2C_FLAG_OVERRUNUNDERRUN: Overrun/Underrun flag (Slave mode)
  *     @arg I2C_FLAG_ACKNOWLEDGEFAILURE: Acknowledge failure flag
  *     @arg I2C_FLAG_ARBITRATIONLOSS: Arbitration lost flag (Master mode)
  *     @arg I2C_FLAG_BUSERROR: Bus error flag
  *     @arg I2C_FLAG_TXEMPTY: Data register empty flag (Transmitter)
  *     @arg I2C_FLAG_RXNOTEMPTY: Data register not empty (Receiver) flag
  *     @arg I2C_FLAG_STOPDETECTION: Stop detection flag (Slave mode)
  *     @arg I2C_FLAG_HEADERSENT: 10-bit header sent flag (Master mode)
  *     @arg I2C_FLAG_TRANSFERFINISHED: Byte transfer finished flag
  *     @arg I2C_FLAG_ADDRESSSENTMATCHED: Address sent flag (Master mode) ADSL
  *   Address matched flag (Slave mode) ENDAD
  *     @arg I2C_FLAG_STARTDETECTION: Start bit flag (Master mode)
  * @retval The new state of I2C_FLAG (SET or RESET).
  */
FlagStatus I2C_GetFlagStatus(I2C_Flag_TypeDef I2C_Flag)
{
  uint8_t tempreg = 0;
  uint8_t regindex = 0;
  FlagStatus bitstatus = RESET;

  /* Check the parameters */
  assert_param(IS_I2C_FLAG_OK(I2C_Flag));

  /* Read flag register index */
  regindex = (uint8_t)((uint16_t)I2C_Flag >> 8);
  /* Check SRx index */
  switch (regindex)
  {
      /* Returns whether the status register to check is SR1 */
    case 0x01:
      tempreg = (uint8_t)I2C->SR1;
      break;

      /* Returns whether the status register to check is SR2 */
    case 0x02:
      tempreg = (uint8_t)I2C->SR2;
      break;

      /* Returns whether the status register to check is SR3 */
    case 0x03:
      tempreg = (uint8_t)I2C->SR3;
      break;

    default:
      break;
  }

  /* Check the status of the specified I2C flag */
  if ((tempreg & (uint8_t)I2C_Flag ) != 0)
  {
    /* Flag is set */
    bitstatus = SET;
  }
  else
  {
    /* Flag is reset */
    bitstatus = RESET;
  }
  /* Return the flag status */
  return bitstatus;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
