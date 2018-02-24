/**
  ******************************************************************************
  * @file    stm8s_can_private.h
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains all the functions for the CAN peripheral.
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
#include "stm8s_can.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define CAN_IDLIST_IDMASK_MASK ((uint8_t) 0x55)
#define CAN_IDMASK_IDLIST_MASK ((uint8_t) 0xAA)
#define CAN_MODE_MASK ((uint8_t) 0x03)
#define CAN_ACKNOWLEDGE_TIMEOUT ((uint16_t)0xFFFF)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern __IO uint32_t _Id;
extern __IO uint8_t _IDE;
extern __IO uint8_t _RTR;
extern __IO uint8_t _DLC;
extern __IO uint8_t _Data[];
extern __IO uint8_t _FMI;
/* Private function prototypes -----------------------------------------------*/
ITStatus CheckITStatus(uint8_t CAN_Reg, uint8_t It_Bit);

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
