
/**
  ********************************************************************************
  * @file    stm8s_awu_Init.c
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
#include "stm8s_awu.h"
#include "private/stm8s_awu_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup AWU_Public_Functions
  * @{
  */

/**
  * @brief  Initializes the AWU peripheral according to the specified parameters.
  * @param   AWU_TimeBase : Time base selection (interval between AWU interrupts).
  * can be one of the values of @ref AWU_Timebase_TypeDef.
  * @retval None
  * @par Required preconditions:
  * The LS RC calibration must be performed before calling this function.
  */
void AWU_Init(AWU_Timebase_TypeDef AWU_TimeBase)
{
  /* Check parameter */
  assert_param(IS_AWU_TIMEBASE_OK(AWU_TimeBase));
  
  /* Enable the AWU peripheral */
  AWU->CSR |= AWU_CSR_AWUEN;
  
  /* Set the TimeBase */
  AWU->TBR &= (uint8_t)(~AWU_TBR_AWUTB);
  AWU->TBR |= TBR_Array[(uint8_t)AWU_TimeBase];
  
  /* Set the APR divider */
  AWU->APR &= (uint8_t)(~AWU_APR_APR);
  AWU->APR |= APR_Array[(uint8_t)AWU_TimeBase];
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
