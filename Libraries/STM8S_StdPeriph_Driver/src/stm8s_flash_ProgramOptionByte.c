
/**
  ********************************************************************************
  * @file    stm8s_flash_ProgramOptionByte.c
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
#include "stm8s_flash.h"
#include "private/stm8s_flash_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup FLASH_Public_Functions
  * @{
  */

/**
  * @brief  Programs option byte
  * @param  Address : option byte address to program
  * @param  Data : Value to write
  * @retval None
  */
void FLASH_ProgramOptionByte(uint16_t Address, uint8_t Data)
{
  /* Check parameter */
  assert_param(IS_OPTION_BYTE_ADDRESS_OK(Address));
  
  /* Enable write access to option bytes */
  FLASH->CR2 |= FLASH_CR2_OPT;
  FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NOPT);
  
  /* check if the option byte to program is ROP*/
  if(Address == 0x4800)
  {
    /* Program option byte*/
    *((NEAR uint8_t*)Address) = Data;
  }
  else
  {
    /* Program option byte and his complement */
    *((NEAR uint8_t*)Address) = Data;
    *((NEAR uint8_t*)((uint16_t)(Address + 1))) = (uint8_t)(~Data);
  }
  FLASH_WaitForLastOperation(FLASH_MEMTYPE_PROG);
  
  /* Disable write access to option bytes */
  FLASH->CR2 &= (uint8_t)(~FLASH_CR2_OPT);
  FLASH->NCR2 |= FLASH_NCR2_NOPT;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
