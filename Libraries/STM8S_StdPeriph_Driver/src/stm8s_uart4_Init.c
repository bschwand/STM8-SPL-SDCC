
/**
  ********************************************************************************
  * @file    stm8s_uart4_Init.c
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
#include "stm8s_uart4.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup UART4_Public_Functions
  * @{
  */

/**
  * @brief  Initializes the UART4 according to the specified parameters.
  * @param  BaudRate: The baudrate.
  * @param  WordLength : This parameter can be any of the 
  *         @ref UART4_WordLength_TypeDef enumeration.
  * @param  StopBits: This parameter can be any of the 
  *         @ref UART4_StopBits_TypeDef enumeration.
  * @param  Parity: This parameter can be any of the 
  *         @ref UART4_Parity_TypeDef enumeration.
  * @param  SyncMode: This parameter can be any of the 
  *         @ref UART4_SyncMode_TypeDef values.
  * @param  Mode: This parameter can be any of the @ref UART4_Mode_TypeDef values
  * @retval None
  */
void UART4_Init(uint32_t BaudRate, UART4_WordLength_TypeDef WordLength, UART4_StopBits_TypeDef StopBits, UART4_Parity_TypeDef Parity, UART4_SyncMode_TypeDef SyncMode, UART4_Mode_TypeDef Mode)
{
  uint8_t BRR2_1 = 0, BRR2_2 = 0;
  uint32_t BaudRate_Mantissa = 0, BaudRate_Mantissa100 = 0;
  
  /* Check the parameters */
  assert_param(IS_UART4_BAUDRATE_OK(BaudRate));
  assert_param(IS_UART4_WORDLENGTH_OK(WordLength));
  assert_param(IS_UART4_STOPBITS_OK(StopBits));
  assert_param(IS_UART4_PARITY_OK(Parity));
  assert_param(IS_UART4_MODE_OK((uint8_t)Mode));
  assert_param(IS_UART4_SYNCMODE_OK((uint8_t)SyncMode));
  
  /* Clear the word length bit */
  UART4->CR1 &= (uint8_t)(~UART4_CR1_M);
  /* Set the word length bit according to UART4_WordLength value */
  UART4->CR1 |= (uint8_t)WordLength; 
  
  /* Clear the STOP bits */
  UART4->CR3 &= (uint8_t)(~UART4_CR3_STOP);
  /* Set the STOP bits number according to UART4_StopBits value  */
  UART4->CR3 |= (uint8_t)StopBits; 
  
  /* Clear the Parity Control bit */
  UART4->CR1 &= (uint8_t)(~(UART4_CR1_PCEN | UART4_CR1_PS  ));
  /* Set the Parity Control bit to UART4_Parity value */
  UART4->CR1 |= (uint8_t)Parity;
  
  /* Clear the LSB mantissa of UART4DIV  */
  UART4->BRR1 &= (uint8_t)(~UART4_BRR1_DIVM);
  /* Clear the MSB mantissa of UART4DIV  */
  UART4->BRR2 &= (uint8_t)(~UART4_BRR2_DIVM);
  /* Clear the Fraction bits of UART4DIV */
  UART4->BRR2 &= (uint8_t)(~UART4_BRR2_DIVF);
  
  /* Set the UART4 BaudRates in BRR1 and BRR2 registers according to UART4_BaudRate value */
  BaudRate_Mantissa    = ((uint32_t)CLK_GetClockFreq() / (BaudRate << 4));
  BaudRate_Mantissa100 = (((uint32_t)CLK_GetClockFreq() * 100) / (BaudRate << 4));
  
  /* The fraction and MSB mantissa should be loaded in one step in the BRR2 register*/
  /* Set the fraction of UARTDIV  */
  BRR2_1 = (uint8_t)((uint8_t)(((BaudRate_Mantissa100 - (BaudRate_Mantissa * 100))
                                << 4) / 100) & (uint8_t)0x0F); 
  BRR2_2 = (uint8_t)((BaudRate_Mantissa >> 4) & (uint8_t)0xF0);
  
  UART4->BRR2 = (uint8_t)(BRR2_1 | BRR2_2);
  /* Set the LSB mantissa of UARTDIV  */
  UART4->BRR1 = (uint8_t)BaudRate_Mantissa;           
  
  /* Disable the Transmitter and Receiver before setting the LBCL, CPOL and CPHA bits */
  UART4->CR2 &= (uint8_t)~(UART4_CR2_TEN | UART4_CR2_REN);
  /* Clear the Clock Polarity, lock Phase, Last Bit Clock pulse */
  UART4->CR3 &= (uint8_t)~(UART4_CR3_CPOL | UART4_CR3_CPHA | UART4_CR3_LBCL);
  /* Set the Clock Polarity, lock Phase, Last Bit Clock pulse */
  UART4->CR3 |= (uint8_t)((uint8_t)SyncMode & (uint8_t)(UART4_CR3_CPOL | \
    UART4_CR3_CPHA | UART4_CR3_LBCL));
  
  if((uint8_t)(Mode & UART4_MODE_TX_ENABLE))
  {
    /* Set the Transmitter Enable bit */
    UART4->CR2 |= (uint8_t)UART4_CR2_TEN;
  }
  else
  {
    /* Clear the Transmitter Disable bit */
    UART4->CR2 &= (uint8_t)(~UART4_CR2_TEN);
  }
  if((uint8_t)(Mode & UART4_MODE_RX_ENABLE))
  {
    /* Set the Receiver Enable bit */
    UART4->CR2 |= (uint8_t)UART4_CR2_REN;
  }
  else
  {
    /* Clear the Receiver Disable bit */
    UART4->CR2 &= (uint8_t)(~UART4_CR2_REN);
  }
  /* Set the Clock Enable bit, lock Polarity, lock Phase and Last Bit Clock 
  pulse bits according to UART4_Mode value */
  if((uint8_t)(SyncMode & UART4_SYNCMODE_CLOCK_DISABLE))
  {
    /* Clear the Clock Enable bit */
    UART4->CR3 &= (uint8_t)(~UART4_CR3_CKEN); 
  }
  else
  {
    UART4->CR3 |= (uint8_t)((uint8_t)SyncMode & UART4_CR3_CKEN);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
