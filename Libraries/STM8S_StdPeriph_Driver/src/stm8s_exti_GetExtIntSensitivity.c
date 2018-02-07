
/**
  ********************************************************************************
  * @file    stm8s_exti_GetExtIntSensitivity.c
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
#include "stm8s_exti.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup EXTI_Public_Functions
  * @{
  */

/**
  * @brief  Get the external interrupt sensitivity of the selected port.
  * @param   Port The port number to access.
  * @retval EXTI_Sensitivity_TypeDef The external interrupt sensitivity of the selected port.
  */
EXTI_Sensitivity_TypeDef EXTI_GetExtIntSensitivity(EXTI_Port_TypeDef Port)
{
  uint8_t value = 0;
  
  /* Check function parameters */
  assert_param(IS_EXTI_PORT_OK(Port));
  
  switch (Port)
  {
  case EXTI_PORT_GPIOA:
    value = (uint8_t)(EXTI->CR1 & EXTI_CR1_PAIS);
    break;
  case EXTI_PORT_GPIOB:
    value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_PBIS) >> 2);
    break;
  case EXTI_PORT_GPIOC:
    value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_PCIS) >> 4);
    break;
  case EXTI_PORT_GPIOD:
    value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_PDIS) >> 6);
    break;
  case EXTI_PORT_GPIOE:
    value = (uint8_t)(EXTI->CR2 & EXTI_CR2_PEIS);
    break;
  default:
    break;
  }
  
  return((EXTI_Sensitivity_TypeDef)value);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
