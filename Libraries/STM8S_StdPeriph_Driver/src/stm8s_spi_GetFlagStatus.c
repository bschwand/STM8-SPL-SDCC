
/**
  ********************************************************************************
  * @file    stm8s_spi_GetFlagStatus.c
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
  * @brief  Checks whether the specified SPI flag is set or not.
  * @param  SPI_FLAG : Specifies the flag to check.
  *         This parameter can be any of the @ref SPI_FLAG_TypeDef enumeration.
  * @retval FlagStatus : Indicates the state of SPI_FLAG.
  *         This parameter can be any of the @ref FlagStatus enumeration.
  */

FlagStatus SPI_GetFlagStatus(SPI_Flag_TypeDef SPI_FLAG)
{
  FlagStatus status = RESET;
  /* Check parameters */
  assert_param(IS_SPI_FLAGS_OK(SPI_FLAG));
  
  /* Check the status of the specified SPI flag */
  if ((SPI->SR & (uint8_t)SPI_FLAG) != (uint8_t)RESET)
  {
    status = SET; /* SPI_FLAG is set */
  }
  else
  {
    status = RESET; /* SPI_FLAG is reset*/
  }
  
  /* Return the SPI_FLAG status */
  return status;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
