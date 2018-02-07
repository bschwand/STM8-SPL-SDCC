
/**
  ********************************************************************************
  * @file    stm8s_i2c_ClearITPendingBit.c
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
  * @brief  Clear IT pending bit
  * @param  I2C_IT: specifies the interrupt pending bit to clear.
  *            This parameter can be any combination of the following values:
  *                 - I2C_ITPENDINGBIT_WAKEUPFROMHALT: Wakeup from Halt
  *                 - I2C_ITPENDINGBIT_OVERRUNUNDERRUN: Overrun/Underrun interrupt (Slave mode)
  *                 - I2C_ITPENDINGBIT_ACKNOWLEDGEFAILURE: Acknowledge failure interrupt
  *                 - I2C_ITPENDINGBIT_ARBITRATIONLOSS: Arbitration lost interrupt (Master mode)
  *                 - I2C_ITPENDINGBIT_BUSERROR: Bus error interrupt
  *
  *             Notes:
  *                  - STOPF (STOP detection) is cleared by software
  *                    sequence: a read operation to I2C_SR1 register
  *                    (I2C_GetITStatus()) followed by a write operation to
  *                    I2C_CR2 register (I2C_AcknowledgeConfig() to configure
  *                    the I2C peripheral Acknowledge).
  *                  - ADD10 (10-bit header sent) is cleared by software
  *                    sequence: a read operation to I2C_SR1
  *                    (I2C_GetITStatus()) followed by writing the second
  *                    byte of the address in I2C_DR register.
  *                  - BTF (Byte Transfer Finished) is cleared by software
  *                    sequence: a read operation to I2C_SR1 register
  *                    (I2C_GetITStatus()) followed by a read/write to
  *                    I2C_DR register (I2C_SendData()).
  *                  - ADDR (Address sent) is cleared by software sequence:
  *                    a read operation to I2C_SR1 register (I2C_GetITStatus())
  *                    followed by a read operation to I2C_SR3 register
  *                    ((void)(I2C->SR3)).
  *                  - SB (Start Bit) is cleared by software sequence: a
  *                    read operation to I2C_SR1 register (I2C_GetITStatus())
  *                    followed by a write operation to I2C_DR register
  *                    (I2C_SendData()).
  * @retval None
  */
void I2C_ClearITPendingBit(I2C_ITPendingBit_TypeDef I2C_ITPendingBit)
{
  uint16_t flagpos = 0;

  /* Check the parameters */
  assert_param(IS_I2C_CLEAR_ITPENDINGBIT_OK(I2C_ITPendingBit));

  /* Get the I2C flag position */
  flagpos = (uint16_t)I2C_ITPendingBit & FLAG_Mask;

  /* Clear the selected I2C flag */
  I2C->SR2 = (uint8_t)((uint16_t)~flagpos);
}
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
