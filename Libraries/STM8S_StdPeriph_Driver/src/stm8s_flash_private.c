
/**
  ********************************************************************************
  * @file    stm8s_flash_private.c
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

/* Private variables ---------------------------------------------------------*/

/* SDCC patch: for >64kB to pass data to/from inline ASM (SDCC doesn't support far pointers yet) */
#if defined(_SDCC_BIGMEM_)
uint32_t    asm_addr;      // 16b/24b address
uint8_t     asm_val;       // 1B data for r/w data
#endif // _SDCC_BIGMEM_

#if defined (_SDCC_BIGMEM_)
/**
  * @brief  write single byte to address
  * @note   is required for >64kB memory space and SDCC, which doesn't yet support far pointers
  * @param  Address : address to write to
  *         Data :    value to write
  * @retval None
  */
void write_byte_address(uint32_t Address, uint8_t Data)
{
  /* store address & data globally for assember */
  asm_addr = Address;
  asm_val  = Data;

  /* use inline assembler to write to 16b/24b address */
__asm
  ld	a,_asm_val
  ldf	[_asm_addr+1].e,a
__endasm;

}


/**
  * @brief  Reads any byte from flash memory
  * @note   is required for >64kB memory space and SDCC, which doesn't yet support far pointers
  * @param  Address : address to read
  * @retval value read
  */
uint8_t read_byte_address(uint32_t Address)
{
  /* store address globally for assember */
  asm_addr = Address;

  /* use inline assembler to read from 16b/24b address */
__asm
  ldf	a,[_asm_addr+1].e
  ld	_asm_val,a
__endasm;

  /* return read byte */
  return(asm_val);
  
}

#endif // _SDCC_BIGMEM_

/**
  * @brief
  *******************************************************************************
  *                         Execution from RAM enable
  *******************************************************************************
  *
  * To enable execution from RAM you can either uncomment the following define 
  * in the stm8s.h file or define it in your toolchain compiler preprocessor
  * - #define RAM_EXECUTION  (1) 
  */

/* SDCC patch: code in RAM not yet patched */
#if defined (_SDCC_) && defined (RAM_EXECUTION)
 #error RAM execution not yet implemented in patch, comment RAM_EXECUTION in stm8s.h
#endif

#if defined (_COSMIC_) && defined (RAM_EXECUTION)
 #pragma section (FLASH_CODE)
#endif  /* _COSMIC_ && RAM_EXECUTION */

/**
  * @brief  Wait for a Flash operation to complete.
  * @note   The call and execution of this function must be done from RAM in case
  *         of Block operation.
  * @param  FLASH_MemType : Memory type
  *         This parameter can be a value of @ref FLASH_MemType_TypeDef
  * @retval FLASH status
  */
IN_RAM(FLASH_Status_TypeDef FLASH_WaitForLastOperation(FLASH_MemType_TypeDef FLASH_MemType)) 
{
  uint8_t flagstatus = 0x00;
  uint16_t timeout = OPERATION_TIMEOUT;
  
  /* Wait until operation completion or write protection page occurred */
#if defined (STM8S208) || defined(STM8S207) || defined(STM8S007) || defined(STM8S105) || \
  defined(STM8S005) || defined(STM8AF52Ax) || defined(STM8AF62Ax) || defined(STM8AF626x)  
    if(FLASH_MemType == FLASH_MEMTYPE_PROG)
    {
      while((flagstatus == 0x00) && (timeout != 0x00))
      {
        flagstatus = (uint8_t)(FLASH->IAPSR & (uint8_t)(FLASH_IAPSR_EOP |
                                                        FLASH_IAPSR_WR_PG_DIS));
        timeout--;
      }
    }
    else
    {
      while((flagstatus == 0x00) && (timeout != 0x00))
      {
        flagstatus = (uint8_t)(FLASH->IAPSR & (uint8_t)(FLASH_IAPSR_HVOFF |
                                                        FLASH_IAPSR_WR_PG_DIS));
        timeout--;
      }
    }
#else /*STM8S103, STM8S903, STM8AF622x */
  while((flagstatus == 0x00) && (timeout != 0x00))
  {
    flagstatus = (uint8_t)(FLASH->IAPSR & (FLASH_IAPSR_EOP | FLASH_IAPSR_WR_PG_DIS));
    timeout--;
  }
#endif /* STM8S208, STM8S207, STM8S105, STM8AF52Ax, STM8AF62Ax, STM8AF262x */
  
  if(timeout == 0x00 )
  {
    flagstatus = FLASH_STATUS_TIMEOUT;
  }
  
  return((FLASH_Status_TypeDef)flagstatus);
}

/**
  * @brief  Erases a block in the program or data memory.
  * @note   This function should be executed from RAM.
  * @param  FLASH_MemType :  The type of memory to erase
  * @param  BlockNum : Indicates the block number to erase
  * @retval None.
  */
IN_RAM(void FLASH_EraseBlock(uint16_t BlockNum, FLASH_MemType_TypeDef FLASH_MemType))
{
  uint32_t startaddress = 0;
  
#if defined(STM8S105) || defined(STM8S005) || defined(STM8S103) || defined(STM8S003) || \
  defined (STM8S903) || defined (STM8AF626x) || defined (STM8AF622x)
    uint32_t PointerAttr  *pwFlash;
#elif defined (STM8S208) || defined(STM8S207) || defined(STM8S007) || defined (STM8AF62Ax) || defined (STM8AF52Ax) 
  uint8_t PointerAttr  *pwFlash;
#endif
  
  /* Check parameters */
  assert_param(IS_MEMORY_TYPE_OK(FLASH_MemType));
  if(FLASH_MemType == FLASH_MEMTYPE_PROG)
  {
    assert_param(IS_FLASH_PROG_BLOCK_NUMBER_OK(BlockNum));
    startaddress = FLASH_PROG_START_PHYSICAL_ADDRESS;
  }
  else
  {
    assert_param(IS_FLASH_DATA_BLOCK_NUMBER_OK(BlockNum));
    startaddress = FLASH_DATA_START_PHYSICAL_ADDRESS;
  }
  
  /* Point to the first block address */
#if defined (STM8S208) || defined(STM8S207) || defined(STM8S007) || defined (STM8AF62Ax) || defined (STM8AF52Ax)
  pwFlash = (PointerAttr uint8_t *)(MemoryAddressCast)(startaddress + ((uint32_t)BlockNum * FLASH_BLOCK_SIZE));
#elif defined(STM8S105) || defined(STM8S005) || defined(STM8S103) || defined(STM8S003) || \
  defined (STM8S903) || defined (STM8AF626x) || defined (STM8AF622x)
    pwFlash = (PointerAttr uint32_t *)(MemoryAddressCast)(startaddress + ((uint32_t)BlockNum * FLASH_BLOCK_SIZE));
#endif	/* STM8S208, STM8S207 */
  
  /* Enable erase block mode */
  FLASH->CR2 |= FLASH_CR2_ERASE;
  FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NERASE);
  
#if defined(STM8S105) || defined(STM8S005) || defined(STM8S103) || defined(STM8S003) ||  \
  defined (STM8S903) || defined (STM8AF626x) || defined (STM8AF622x)
    *pwFlash = (uint32_t)0;
#elif defined (STM8S208) || defined(STM8S207) || defined(STM8S007) || defined (STM8AF62Ax) || \
  defined (STM8AF52Ax)
    *pwFlash = (uint8_t)0;
  *(pwFlash + 1) = (uint8_t)0;
  *(pwFlash + 2) = (uint8_t)0;
  *(pwFlash + 3) = (uint8_t)0;    
#endif
}

/**
  * @brief  Programs a memory block
  * @note   This function should be executed from RAM.
  * @param  FLASH_MemType : The type of memory to program
  * @param  BlockNum : The block number
  * @param  FLASH_ProgMode : The programming mode.
  * @param  Buffer : Pointer to buffer containing source data.
  * @retval None.
  */
IN_RAM(void FLASH_ProgramBlock(uint16_t BlockNum, FLASH_MemType_TypeDef FLASH_MemType, 
                        FLASH_ProgramMode_TypeDef FLASH_ProgMode, uint8_t *Buffer))
{
  uint16_t Count = 0;
  uint32_t startaddress = 0;
  
  /* Check parameters */
  assert_param(IS_MEMORY_TYPE_OK(FLASH_MemType));
  assert_param(IS_FLASH_PROGRAM_MODE_OK(FLASH_ProgMode));
  if(FLASH_MemType == FLASH_MEMTYPE_PROG)
  {
    assert_param(IS_FLASH_PROG_BLOCK_NUMBER_OK(BlockNum));
    startaddress = FLASH_PROG_START_PHYSICAL_ADDRESS;
  }
  else
  {
    assert_param(IS_FLASH_DATA_BLOCK_NUMBER_OK(BlockNum));
    startaddress = FLASH_DATA_START_PHYSICAL_ADDRESS;
  }
  
  /* Point to the first block address */
  startaddress = startaddress + ((uint32_t)BlockNum * FLASH_BLOCK_SIZE);
  
  /* Selection of Standard or Fast programming mode */
  if(FLASH_ProgMode == FLASH_PROGRAMMODE_STANDARD)
  {
    /* Standard programming mode */ /*No need in standard mode */
    FLASH->CR2 |= FLASH_CR2_PRG;
    FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NPRG);
  }
  else
  {
    /* Fast programming mode */
    FLASH->CR2 |= FLASH_CR2_FPRG;
    FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NFPRG);
  }
  
  /* Copy data bytes from RAM to FLASH memory */
  for(Count = 0; Count < FLASH_BLOCK_SIZE; Count++)
  {
    *((PointerAttr uint8_t*) (MemoryAddressCast)startaddress + Count) = ((uint8_t)(Buffer[Count]));
  }
}

#if defined (_COSMIC_) && defined (RAM_EXECUTION)
 /* End of FLASH_CODE section */
 #pragma section ()
#endif /* _COSMIC_ && RAM_EXECUTION */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
