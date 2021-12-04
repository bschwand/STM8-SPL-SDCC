/**
  ******************************************************************************
  * @file    Project/main.c 
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   Main program body
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
#include "stm8s.h"
#include "stm8s_it.h"    /* SDCC patch: required by SDCC for interrupts */
#include "stdio.h"
#include "stm8s_it.h"    // SDCC requires ISR declaration to be included here


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#ifdef _RAISONANCE_
  #define PUTCHAR_PROTOTYPE int putchar (char c)
  #define GETCHAR_PROTOTYPE int getchar (void)
#elif defined (_COSMIC_)
  #define PUTCHAR_PROTOTYPE char putchar (char c)
  #define GETCHAR_PROTOTYPE char getchar (void)
#elif defined (_SDCC_)                    /* SDCC patch: same types as stdio.h */
  #if SDCC_VERSION >= 30700               // declaration changed in sdcc 3.7.0 (see sdccman.pdf)
    #define PUTCHAR_PROTOTYPE int putchar (int c)
    #define GETCHAR_PROTOTYPE int getchar (void)
  #else
    #define PUTCHAR_PROTOTYPE void putchar (char c)
    #define GETCHAR_PROTOTYPE unsigned char getchar (void)
  #endif 
#else /* _IAR_ */
  #define PUTCHAR_PROTOTYPE int putchar (int c)
  #define GETCHAR_PROTOTYPE int getchar (void)
#endif /* _RAISONANCE_ */
/* Private macro -------------------------------------------------------------*/


/* Public variables ---------------------------------------------------------*/
uint8_t     g_flag1ms=0;    // flag for 1ms interrupt (for TIM4 ISR)
uint32_t    g_count1ms=0;   // 1ms counter (for TIM4 ISR)

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


void main(void)
{
  uint8_t  val  = 0x00;
  //uint32_t addr = 0x40A5;   // address for flash read/write
  //uint32_t i;

  /* init High speed internal clock prescaler: 1 */
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);

  /* Enable TIM4 CLK */
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, ENABLE);

  /* Initialize LED pins in Output Mode */
  #if defined(STM8S103)    // 1$ STM8 board, see https://www.cnx-software.com/2015/01/18/one-dollar-development-board/
    GPIO_Init(GPIOD, (GPIO_Pin_TypeDef)GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);
    GPIO_WriteHigh(GPIOD, (GPIO_Pin_TypeDef)GPIO_PIN_3);
  #elif defined(STM8S208)  // muBoard, see https://frosch.piandmore.de//de/pam9/call/public-media/event_media/160611_Vortrag_Interpreter.pdf
    GPIO_Init(GPIOH, (GPIO_Pin_TypeDef)(GPIO_PIN_2 | GPIO_PIN_3), GPIO_MODE_OUT_PP_LOW_FAST);
    GPIO_WriteHigh(GPIOH, (GPIO_Pin_TypeDef)(GPIO_PIN_2 | GPIO_PIN_3));
  #else
    #error STM8 board not supported!
  #endif
  
  // config 1ms clock
  TIM4_DeInit();
  TIM4_TimeBaseInit(TIM4_PRESCALER_128, 124);
  TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
  TIM4_Cmd(ENABLE);
  
  // init UART1 to 115.2kBaud, 1/8/1, no parity, no clock
  UART1_DeInit();
  UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
              UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);

  /* Define FLASH programming time */
  //FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);

  /* Unlock Data memory */
  //FLASH_Unlock(FLASH_MEMTYPE_DATA);

  // enable interrupts
  enableInterrupts();

  // main loop
  while (1)
  {
    // if key pressed, send echo and store to flash
    if (UART1_GetFlagStatus(UART1_FLAG_RXNE))
    {
      val = getchar();
      printf("read %c%c%c", val,10,13);
      
      //FLASH_ProgramByte(addr, val);
    }

    // every 1ms
    if (g_flag1ms)
    { 
      g_flag1ms=0;
    
      if ((g_count1ms % 500) == 0)
      {
        // toogle LED
        #if defined(STM8S103)
          GPIO_WriteReverse(GPIOD, (GPIO_Pin_TypeDef)GPIO_PIN_3);
        #elif defined(STM8S208)  // muBoard, see https://frosch.piandmore.de//de/pam9/call/public-media/event_media/160611_Vortrag_Interpreter.pdf
          GPIO_WriteReverse(GPIOH, (GPIO_Pin_TypeDef)GPIO_PIN_2);
        #else
          #error STM8 board not supported!
        #endif
        
        // print time
        printf("time %ld%c%c", g_count1ms,10,13);

        /*
        // Read byte from flash
        val = FLASH_ReadByte(addr);

        // Program value+1 at address + 1
        FLASH_ProgramByte(addr+1, val+1);

        // check flash content
        printf("write: ");
        val = FLASH_ReadByte(addr);
        printf("%c ", val);
        val = FLASH_ReadByte(addr+1);
        printf("%c ", val);
        
        
        // erase both bytes in flash
        FLASH_EraseByte(addr);
        FLASH_EraseByte((addr + 1));

        // check flash content
        printf("erase: ");
        val = FLASH_ReadByte(addr);
        printf("%d ", (int) val);
        val = FLASH_ReadByte(addr+1);
        printf("%d ", (int) val);
        
        // print LF+CR
        printf("%c%c", 10,13);
        */

      } // every 500ms
    
    } // every 1ms
    
  } // main loop

} // main()


/**
  * @brief Retargets the C library printf function to the UART.
  * @param c Character to send
  * @retval char Character sent
  */
PUTCHAR_PROTOTYPE
{
  /* Write a character to the UART1 */
  UART1_SendData8(c);
  /* Loop until the end of transmission */
  while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);

  // non SDCC or newer SDCC version
  #if !defined(__SDCC) || (SDCC_VERSION >= 30605)
    return (c);
  #endif
}


/**
  * @brief Retargets the C library scanf function to the USART.
  * @param None
  * @retval char Character to Read
  */
GETCHAR_PROTOTYPE
{
#ifdef _COSMIC_
  char c = 0;
#else
  int c = 0;
#endif
  /* Loop until the Read data register flag is SET */
  while (UART1_GetFlagStatus(UART1_FLAG_RXNE) == RESET);
    c = UART1_ReceiveData8();
  return (c);
}


#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  // avoid compiler warnings
  (void) file;
  (void) line;
  
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
