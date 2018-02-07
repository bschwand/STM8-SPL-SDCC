
/**
  ********************************************************************************
  * @file    stm8s_i2c_Send7bitAddress.c
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
  * @brief  Transmits the 7-bit address (to select the) slave device.
  * @param   Address : Specifies the slave address which will be transmitted.
  * @param   Direction : Specifies whether the I2C device will be a Transmitter or a Receiver.
  * This parameter can be any of the @ref I2C_Direction_TypeDef enumeration.
  * @retval None
  */
void I2C_Send7bitAddress(uint8_t Address, I2C_Direction_TypeDef Direction)
{
  /* Check function parameters */
  assert_param(IS_I2C_ADDRESS_OK(Address));
  assert_param(IS_I2C_DIRECTION_OK(Direction));

  /* Clear bit0 (direction) just in case */
  Address &= (uint8_t)0xFE;

  /* Send the Address + Direction */
  I2C->DR = (uint8_t)(Address | (uint8_t)Direction);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
