
/**
  ********************************************************************************
  * @file    stm8s_uart2_GetFlagStatus.c
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
#include "stm8s_uart2.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup UART2_Public_Functions
  * @{
  */

/**
  * @brief  Checks whether the specified UART2 flag is set or not.
  * @param  UART2_FLAG specifies the flag to check.
  *         This parameter can be any of the @ref UART2_Flag_TypeDef enumeration.
  * @retval FlagStatus (SET or RESET)
  */
FlagStatus UART2_GetFlagStatus(UART2_Flag_TypeDef UART2_FLAG)
{
  FlagStatus status = RESET;
  
  /* Check parameters */
  assert_param(IS_UART2_FLAG_OK(UART2_FLAG));
  
  /* Check the status of the specified UART2 flag*/
  if (UART2_FLAG == UART2_FLAG_LBDF)
  {
    if ((UART2->CR4 & (uint8_t)UART2_FLAG) != (uint8_t)0x00)
    {
      /* UART2_FLAG is set*/
      status = SET;
    }
    else
    {
      /* UART2_FLAG is reset*/
      status = RESET;
    }
  }
  else if (UART2_FLAG == UART2_FLAG_SBK)
  {
    if ((UART2->CR2 & (uint8_t)UART2_FLAG) != (uint8_t)0x00)
    {
      /* UART2_FLAG is set*/
      status = SET;
    }
    else
    {
      /* UART2_FLAG is reset*/
      status = RESET;
    }
  }
  else if ((UART2_FLAG == UART2_FLAG_LHDF) || (UART2_FLAG == UART2_FLAG_LSF))
  {
    if ((UART2->CR6 & (uint8_t)UART2_FLAG) != (uint8_t)0x00)
    {
      /* UART2_FLAG is set*/
      status = SET;
    }
    else
    {
      /* UART2_FLAG is reset*/
      status = RESET;
    }
  }
  else
  {
    if ((UART2->SR & (uint8_t)UART2_FLAG) != (uint8_t)0x00)
    {
      /* UART2_FLAG is set*/
      status = SET;
    }
    else
    {
      /* UART2_FLAG is reset*/
      status = RESET;
    }
  }
  
  /* Return the UART2_FLAG status*/
  return  status;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
