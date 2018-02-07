
/**
  ********************************************************************************
  * @file    stm8s_i2c_GetITStatus.c
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
  * @brief  Checks whether the specified I2C interrupt has occurred or not.
  * @param  I2C_ITPendingBit: specifies the interrupt source to check.
  *            This parameter can be one of the following values:
  *               - I2C_ITPENDINGBIT_WAKEUPFROMHALT: Wakeup from Halt
  *               - I2C_ITPENDINGBIT_OVERRUNUNDERRUN: Overrun/Underrun flag (Slave mode)
  *               - I2C_ITPENDINGBIT_ACKNOWLEDGEFAILURE: Acknowledge failure flag
  *               - I2C_ITPENDINGBIT_ARBITRATIONLOSS: Arbitration lost flag (Master mode)
  *               - I2C_ITPENDINGBIT_BUSERROR: Bus error flag
  *               - I2C_ITPENDINGBIT_TXEMPTY: Data register empty flag (Transmitter)
  *               - I2C_ITPENDINGBIT_RXNOTEMPTY: Data register not empty (Receiver) flag
  *               - I2C_ITPENDINGBIT_STOPDETECTION: Stop detection flag (Slave mode)
  *               - I2C_ITPENDINGBIT_HEADERSENT: 10-bit header sent flag (Master mode)
  *               - I2C_ITPENDINGBIT_TRANSFERFINISHED: Byte transfer finished flag
  *               - I2C_ITPENDINGBIT_ADDRESSSENTMATCHED: Address sent flag (Master mode) ADSL
  *                              Address matched flag (Slave mode) ENDAD
  *               - I2C_ITPENDINGBIT_STARTDETECTION: Start bit flag (Master mode)
  * @retval The new state of I2C_ITPendingBit
  *   This parameter can be any of the @ref ITStatus enumeration.
  */
ITStatus I2C_GetITStatus(I2C_ITPendingBit_TypeDef I2C_ITPendingBit)
{
  ITStatus bitstatus = RESET;
  __IO uint8_t enablestatus = 0;
  uint16_t tempregister = 0;

    /* Check the parameters */
    assert_param(IS_I2C_ITPENDINGBIT_OK(I2C_ITPendingBit));

  tempregister = (uint8_t)( ((uint16_t)((uint16_t)I2C_ITPendingBit & ITEN_Mask)) >> 8);

  /* Check if the interrupt source is enabled or not */
  enablestatus = (uint8_t)(I2C->ITR & ( uint8_t)tempregister);

  if ((uint16_t)((uint16_t)I2C_ITPendingBit & REGISTER_Mask) == REGISTER_SR1_Index)
  {
    /* Check the status of the specified I2C flag */
    if (((I2C->SR1 & (uint8_t)I2C_ITPendingBit) != RESET) && enablestatus)
    {
      /* I2C_IT is set */
      bitstatus = SET;
    }
    else
    {
      /* I2C_IT is reset */
      bitstatus = RESET;
    }
  }
  else
  {
    /* Check the status of the specified I2C flag */
    if (((I2C->SR2 & (uint8_t)I2C_ITPendingBit) != RESET) && enablestatus)
    {
      /* I2C_IT is set */
      bitstatus = SET;
    }
    else
    {
      /* I2C_IT is reset */
      bitstatus = RESET;
    }
  }
  /* Return the I2C_IT status */
  return  bitstatus;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
