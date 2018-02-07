
/**
  ********************************************************************************
  * @file    stm8s_beep_Init.c
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
#include "stm8s_beep.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup BEEP_Public_Functions
  * @{
  */

/**
  * @brief  Initializes the BEEP function according to the specified parameters.
  * @param   BEEP_Frequency Frequency selection.
  * can be one of the values of @ref BEEP_Frequency_TypeDef.
  * @retval None
  * @par Required preconditions:
  * The LS RC calibration must be performed before calling this function.
  */
void BEEP_Init(BEEP_Frequency_TypeDef BEEP_Frequency)
{
  /* Check parameter */
  assert_param(IS_BEEP_FREQUENCY_OK(BEEP_Frequency));
  
  /* Set a default calibration value if no calibration is done */
  if ((BEEP->CSR & BEEP_CSR_BEEPDIV) == BEEP_CSR_BEEPDIV)
  {
    BEEP->CSR &= (uint8_t)(~BEEP_CSR_BEEPDIV); /* Clear bits */
    BEEP->CSR |= BEEP_CALIBRATION_DEFAULT;
  }
  
  /* Select the output frequency */
  BEEP->CSR &= (uint8_t)(~BEEP_CSR_BEEPSEL);
  BEEP->CSR |= (uint8_t)(BEEP_Frequency);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
