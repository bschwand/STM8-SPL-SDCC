
/**
  ********************************************************************************
  * @file    stm8s_spi_ITConfig.c
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
#include "stm8s_spi.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup SPI_Public_Functions
  * @{
  */

/**
  * @brief  Enables or disables the specified interrupts.
  * @param  SPI_IT Specifies the SPI interrupts sources to be enabled or disabled.
  * @param  NewState: The new state of the specified SPI interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SPI_ITConfig(SPI_IT_TypeDef SPI_IT, FunctionalState NewState)
{
  uint8_t itpos = 0;
  /* Check function parameters */
  assert_param(IS_SPI_CONFIG_IT_OK(SPI_IT));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  
  /* Get the SPI IT index */
  itpos = (uint8_t)((uint8_t)1 << (uint8_t)((uint8_t)SPI_IT & (uint8_t)0x0F));
  
  if (NewState != DISABLE)
  {
    SPI->ICR |= itpos; /* Enable interrupt*/
  }
  else
  {
    SPI->ICR &= (uint8_t)(~itpos); /* Disable interrupt*/
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
