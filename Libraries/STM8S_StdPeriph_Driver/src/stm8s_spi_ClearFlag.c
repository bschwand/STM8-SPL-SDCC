
/**
  ********************************************************************************
  * @file    stm8s_spi_ClearFlag.c
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
  * @brief  Clears the SPI flags.
  * @param  SPI_FLAG : Specifies the flag to clear.
  *         This parameter can be one of the following values:
  *         - SPI_FLAG_CRCERR
  *         - SPI_FLAG_WKUP
  * @note   - OVR (OverRun Error) interrupt pending bit is cleared by software
  *         sequence:
  *         a read operation to SPI_DR register (SPI_ReceiveData()) followed by
  *         a read operation to SPI_SR register (SPI_GetFlagStatus()).
  *         - MODF (Mode Fault) interrupt pending bit is cleared by software sequence:
  *         a read/write operation to SPI_SR register (SPI_GetFlagStatus()) followed by
  *         a write operation to SPI_CR1 register (SPI_Cmd() to enable the SPI).
  * @retval None
  */
void SPI_ClearFlag(SPI_Flag_TypeDef SPI_FLAG)
{
  assert_param(IS_SPI_CLEAR_FLAGS_OK(SPI_FLAG));
  /* Clear the flag bit */
  SPI->SR = (uint8_t)(~SPI_FLAG);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
