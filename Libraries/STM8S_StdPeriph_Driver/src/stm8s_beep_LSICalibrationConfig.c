
/**
  ********************************************************************************
  * @file    stm8s_beep_LSICalibrationConfig.c
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
  * @brief  Update CSR register with the measured LSI frequency.
  * @par Note on the APR calculation:
  * A is the integer part of LSIFreqkHz/4 and x the decimal part.
  * x <= A/(1+2A) is equivalent to A >= x(1+2A) and also to 4A >= 4x(1+2A) [F1]
  * but we know that A + x = LSIFreqkHz/4 ==> 4x = LSIFreqkHz-4A
  * so [F1] can be written :
  * 4A >= (LSIFreqkHz-4A)(1+2A)
  * @param   LSIFreqHz Low Speed RC frequency measured by timer (in Hz).
  * @retval None
  * @par Required preconditions:
  * - BEEP must be disabled to avoid unwanted interrupts.
  */
void BEEP_LSICalibrationConfig(uint32_t LSIFreqHz)
{
  uint16_t lsifreqkhz;
  uint16_t A;
  
  /* Check parameter */
  assert_param(IS_LSI_FREQUENCY_OK(LSIFreqHz));
  
  lsifreqkhz = (uint16_t)(LSIFreqHz / 1000); /* Converts value in kHz */
  
  /* Calculation of BEEPER calibration value */
  
  BEEP->CSR &= (uint8_t)(~BEEP_CSR_BEEPDIV); /* Clear bits */
  
  A = (uint16_t)(lsifreqkhz >> 3U); /* Division by 8, keep integer part only */
  
  if ((8U * A) >= ((lsifreqkhz - (8U * A)) * (1U + (2U * A))))
  {
    BEEP->CSR |= (uint8_t)(A - 2U);
  }
  else
  {
    BEEP->CSR |= (uint8_t)(A - 1U);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
