
/**
  ********************************************************************************
  * @file    stm8s_i2c_AcknowledgeConfig.c
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
  * @brief  Enable or Disable the I2C acknowledge and position acknowledge feature.
  * @note   This function must be called before data reception start
  * @param  Ack : Specifies the acknowledge mode to apply.
  *         This parameter can be any of the  @ref I2C_Ack_TypeDef enumeration.
  * @retval None
  */
void I2C_AcknowledgeConfig(I2C_Ack_TypeDef Ack)
{
  /* Check function parameters */
  assert_param(IS_I2C_ACK_OK(Ack));

  if (Ack == I2C_ACK_NONE)
  {
    /* Disable the acknowledgement */
    I2C->CR2 &= (uint8_t)(~I2C_CR2_ACK);
  }
  else
  {
    /* Enable the acknowledgement */
    I2C->CR2 |= I2C_CR2_ACK;

    if (Ack == I2C_ACK_CURR)
    {
      /* Configure (N)ACK on current byte */
      I2C->CR2 &= (uint8_t)(~I2C_CR2_POS);
    }
    else
    {
      /* Configure (N)ACK on next byte */
      I2C->CR2 |= I2C_CR2_POS;
    }
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
