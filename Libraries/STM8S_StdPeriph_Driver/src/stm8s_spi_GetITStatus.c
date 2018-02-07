
/**
  ********************************************************************************
  * @file    stm8s_spi_GetITStatus.c
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
  * @brief  Checks whether the specified interrupt has occurred or not.
  * @param  SPI_IT: Specifies the SPI interrupt pending bit to check.
  *         This parameter can be one of the following values:
  *         - SPI_IT_CRCERR
  *         - SPI_IT_WKUP
  *         - SPI_IT_OVR
  *         - SPI_IT_MODF
  *         - SPI_IT_RXNE
  *         - SPI_IT_TXE
  * @retval ITStatus : Indicates the state of the SPI_IT.
  *         This parameter can be any of the @ref ITStatus enumeration.
  */
ITStatus SPI_GetITStatus(SPI_IT_TypeDef SPI_IT)
{
  ITStatus pendingbitstatus = RESET;
  uint8_t itpos = 0;
  uint8_t itmask1 = 0;
  uint8_t itmask2 = 0;
  uint8_t enablestatus = 0;
  assert_param(IS_SPI_GET_IT_OK(SPI_IT));
  /* Get the SPI IT index */
  itpos = (uint8_t)((uint8_t)1 << ((uint8_t)SPI_IT & (uint8_t)0x0F));
  
  /* Get the SPI IT mask */
  itmask1 = (uint8_t)((uint8_t)SPI_IT >> (uint8_t)4);
  /* Set the IT mask */
  itmask2 = (uint8_t)((uint8_t)1 << itmask1);
  /* Get the SPI_ITPENDINGBIT enable bit status */
  enablestatus = (uint8_t)((uint8_t)SPI->SR & itmask2);
  /* Check the status of the specified SPI interrupt */
  if (((SPI->ICR & itpos) != RESET) && enablestatus)
  {
    /* SPI_ITPENDINGBIT is set */
    pendingbitstatus = SET;
  }
  else
  {
    /* SPI_ITPENDINGBIT is reset */
    pendingbitstatus = RESET;
  }
  /* Return the SPI_ITPENDINGBIT status */
  return  pendingbitstatus;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
