
/**
  ********************************************************************************
  * @file    stm8s_spi_GetCRC.c
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
  * @brief  Returns the transmit or the receive CRC register value.
  * @param  SPI_CRC Specifies the CRC register to be read.
  * @retval The selected CRC register value.
  */
uint8_t SPI_GetCRC(SPI_CRC_TypeDef SPI_CRC)
{
  uint8_t crcreg = 0;
  
  /* Check function parameters */
  assert_param(IS_SPI_CRC_OK(SPI_CRC));
  
  if (SPI_CRC != SPI_CRC_RX)
  {
    crcreg = SPI->TXCRCR;  /* Get the Tx CRC register*/
  }
  else
  {
    crcreg = SPI->RXCRCR; /* Get the Rx CRC register*/
  }
  
  /* Return the selected CRC register status*/
  return crcreg;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
