
/**
  ********************************************************************************
  * @file    stm8s_flash_ProgramWord.c
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
  * @brief  Programs one word (4 bytes) in program or data EEPROM memory
  * @note   PointerAttr define is declared in the stm8s.h file to select if 
  *         the pointer will be declared as near (2 bytes) or far (3 bytes).
  * @param  Address : The address where the data will be programmed
  * @param  Data : Value to be programmed
  * @retval None
  */
void FLASH_ProgramWord(uint32_t Address, uint32_t Data)
{
  /* Check parameters */
  assert_param(IS_FLASH_ADDRESS_OK(Address));
  
  /* Enable Word Write Once */
  FLASH->CR2 |= FLASH_CR2_WPRG;
  FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NWPRG);
  
  /* SDCC patch: SDCC requires helper routines for >64kB addresses due to lack of far pointers */
  #ifndef _SDCC_BIGMEM_
    /* Write one byte - from lowest address*/
    *((PointerAttr uint8_t*)(MemoryAddressCast)Address)       = *((uint8_t*)(&Data));
    /* Write one byte*/
    *(((PointerAttr uint8_t*)(MemoryAddressCast)Address) + 1) = *((uint8_t*)(&Data)+1); 
    /* Write one byte*/    
    *(((PointerAttr uint8_t*)(MemoryAddressCast)Address) + 2) = *((uint8_t*)(&Data)+2); 
    /* Write one byte - from higher address*/
    *(((PointerAttr uint8_t*)(MemoryAddressCast)Address) + 3) = *((uint8_t*)(&Data)+3); 
  #else
    write_byte_address((MemoryAddressCast) (Address    ), *((uint8_t*)(&Data)));
    write_byte_address((MemoryAddressCast) (Address + 1), *((uint8_t*)(&Data)+1));
    write_byte_address((MemoryAddressCast) (Address + 2), *((uint8_t*)(&Data)+2));
    write_byte_address((MemoryAddressCast) (Address + 3), *((uint8_t*)(&Data)+3));
  #endif // _SDCC_BIGMEM_
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
