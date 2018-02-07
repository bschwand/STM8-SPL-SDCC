
/**
  ********************************************************************************
  * @file    stm8s_itc_GetSoftwarePriority.c
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
#include "stm8s_itc.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup ITC_Public_Functions
  * @{
  */

/**
  * @brief  Gets the software priority of the specified interrupt source.
  * @param  IrqNum : Specifies the peripheral interrupt source.
  * @retval ITC_PriorityLevel_TypeDef : Specifies the software priority of the interrupt source.
  */
ITC_PriorityLevel_TypeDef ITC_GetSoftwarePriority(ITC_Irq_TypeDef IrqNum)
{
  uint8_t Value = 0;
  uint8_t Mask = 0;
  
  /* Check function parameters */
  assert_param(IS_ITC_IRQ_OK((uint8_t)IrqNum));
  
  /* Define the mask corresponding to the bits position in the SPR register */
  Mask = (uint8_t)(0x03U << (((uint8_t)IrqNum % 4U) * 2U));
  
  switch (IrqNum)
  {
  case ITC_IRQ_TLI: /* TLI software priority can be read but has no meaning */
  case ITC_IRQ_AWU:
  case ITC_IRQ_CLK:
  case ITC_IRQ_PORTA:
    Value = (uint8_t)(ITC->ISPR1 & Mask); /* Read software priority */
    break;

  case ITC_IRQ_PORTB:
  case ITC_IRQ_PORTC:
  case ITC_IRQ_PORTD:
  case ITC_IRQ_PORTE:
    Value = (uint8_t)(ITC->ISPR2 & Mask); /* Read software priority */
    break;

#if defined(STM8S208) || defined(STM8AF52Ax)
  case ITC_IRQ_CAN_RX:
  case ITC_IRQ_CAN_TX:
#endif /*STM8S208 or STM8AF52Ax */
#if defined(STM8S903) || defined(STM8AF622x)
  case ITC_IRQ_PORTF:
#endif /*STM8S903 or STM8AF622x */
  case ITC_IRQ_SPI:
  case ITC_IRQ_TIM1_OVF:
    Value = (uint8_t)(ITC->ISPR3 & Mask); /* Read software priority */
    break;

  case ITC_IRQ_TIM1_CAPCOM:
#if defined (STM8S903) || defined (STM8AF622x)
  case ITC_IRQ_TIM5_OVFTRI:
  case ITC_IRQ_TIM5_CAPCOM:
#else
  case ITC_IRQ_TIM2_OVF:
  case ITC_IRQ_TIM2_CAPCOM:
#endif /* STM8S903 or STM8AF622x*/
  case ITC_IRQ_TIM3_OVF:
    Value = (uint8_t)(ITC->ISPR4 & Mask); /* Read software priority */
    break;

  case ITC_IRQ_TIM3_CAPCOM:
#if defined(STM8S208) ||defined(STM8S207) || defined (STM8S007) || defined(STM8S103) || \
    defined(STM8S003) ||defined(STM8S903) || defined (STM8AF52Ax) || defined (STM8AF62Ax)
  case ITC_IRQ_UART1_TX:
  case ITC_IRQ_UART1_RX:
#endif /*STM8S208 or STM8S207 or STM8S007 or STM8S103 or STM8S003 or STM8S903 or STM8AF52Ax or STM8AF62Ax */ 
#if defined(STM8AF622x)
  case ITC_IRQ_UART4_TX:
  case ITC_IRQ_UART4_RX:
#endif /*STM8AF622x */
  case ITC_IRQ_I2C:
    Value = (uint8_t)(ITC->ISPR5 & Mask); /* Read software priority */
    break;

#if defined(STM8S105) || defined(STM8S005) || defined(STM8AF626x)
  case ITC_IRQ_UART2_TX:
  case ITC_IRQ_UART2_RX:
#endif /*STM8S105 or STM8AF626x*/
#if defined(STM8S208) || defined(STM8S207) || defined(STM8S007) || defined(STM8AF52Ax) || \
    defined(STM8AF62Ax)
  case ITC_IRQ_UART3_TX:
  case ITC_IRQ_UART3_RX:
  case ITC_IRQ_ADC2:
#endif /*STM8S208 or STM8S207 or STM8AF52Ax or STM8AF62Ax */
#if defined(STM8S105) || defined(STM8S005) || defined(STM8S103) || defined(STM8S003) || \
    defined(STM8S903) || defined(STM8AF626x) || defined(STM8AF622x)
  case ITC_IRQ_ADC1:
#endif /*STM8S105, STM8S005, STM8S103 or STM8S003 or STM8S903 or STM8AF626x or STM8AF622x */
#if defined (STM8S903) || defined (STM8AF622x)
  case ITC_IRQ_TIM6_OVFTRI:
#else
  case ITC_IRQ_TIM4_OVF:
#endif /*STM8S903 or STM8AF622x */
    Value = (uint8_t)(ITC->ISPR6 & Mask); /* Read software priority */
    break;

  case ITC_IRQ_EEPROM_EEC:
    Value = (uint8_t)(ITC->ISPR7 & Mask); /* Read software priority */
    break;

  default:
    break;
  }
  
  Value >>= (uint8_t)(((uint8_t)IrqNum % 4u) * 2u);
  
  return((ITC_PriorityLevel_TypeDef)Value);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
