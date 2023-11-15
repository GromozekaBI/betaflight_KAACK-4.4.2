/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define TARGET_BOARD_IDENTIFIER "S7X2FoxV4"

#define USBD_PRODUCT_STRING     "FooxV4 STM32F7x2"


#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

#define USE_I2C_DEVICE_1
#define USE_I2C_DEVICE_2
#define USE_I2C_DEVICE_3

#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_UART4
#define USE_UART5
#define USE_UART6

#define SERIAL_PORT_COUNT       (UNIFIED_SERIAL_PORT_COUNT + 6)

#define USE_SPI_DEVICE_1
#define USE_SPI_DEVICE_2
#define USE_SPI_DEVICE_3

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff
#define TARGET_IO_PORTF 0xffff

#define USE_I2C
#define I2C_FULL_RECONFIGURABILITY

#define USE_BEEPER

#ifdef USE_SDCARD
#define USE_SDCARD_SPI
#define USE_SDCARD_SDIO
#endif

#define USE_SPI
#define SPI_FULL_RECONFIGURABILITY

#define USE_VCP
#define USE_SOFTSERIAL1
#define USE_SOFTSERIAL2

#define UNIFIED_SERIAL_PORT_COUNT       3

#define USE_USB_DETECT

#define USE_ESCSERIAL

#define USE_ADC

#define USE_CUSTOM_DEFAULTS

#define BEEPER_PIN           PA4
#define MOTOR1_PIN           PA9
#define MOTOR2_PIN           PA8
#define MOTOR3_PIN           PC9
#define MOTOR4_PIN           PC8
#define RX_PPM_PIN           PB7
#define LED_STRIP_PIN        PA15
#define UART1_TX_PIN         PB6
#define UART2_TX_PIN         PA2
#define UART3_TX_PIN         PB10
#define UART4_TX_PIN         PA0
#define UART5_TX_PIN         PC12
#define UART6_TX_PIN         PC6
#define UART1_RX_PIN         PB7
#define UART2_RX_PIN         PA3
#define UART3_RX_PIN         PB11
#define UART4_RX_PIN         PA1
#define UART5_RX_PIN         PD2
#define UART6_RX_PIN         PC7
#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9
#define LED0_PIN             PC15
//#define SPI1_SCK_PIN         PA5
//#define SPI2_SCK_PIN         PB13
//#define SPI3_SCK_PIN         PC10
//#define SPI1_SDI_PIN         PA6
//#define SPI2_SDI_PIN         PB14
//#define SPI3_SDI_PIN         PC11
//#define SPI1_SDO_PIN         PA7
//#define SPI2_SDO_PIN         PB15
//#define SPI3_SDO_PIN         PB5
#define CAMERA_CONTROL_PIN   PB3
#define ADC_VBAT_PIN         PC0
#define ADC_RSSI_PIN         PA0
#define ADC_CURR_PIN         PC2
#define FLASH_CS_PIN         PB12
#define MAX7456_SPI_CS_PIN   PC3
#define GYRO_1_EXTI_PIN      PC4

#define GYRO_1_CS_PIN        PB2

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PB7 , 1,  0) \
    TIMER_PIN_MAP( 1, PA9 , 1,  0) \
    TIMER_PIN_MAP( 2, PA8 , 1,  0) \
    TIMER_PIN_MAP( 3, PC9 , 2,  0) \
    TIMER_PIN_MAP( 4, PC8 , 2,  0) \
    TIMER_PIN_MAP( 5, PC6 , 2,  0) \
    TIMER_PIN_MAP( 6, PC7 , 2,  0) \
    TIMER_PIN_MAP( 7, PA15, 1,  0) \
    TIMER_PIN_MAP( 8, PB3 , 1,  0)


#define ADC3_DMA_OPT        0

#define MAG_I2C_INSTANCE (I2CDEV_1)
#define BARO_I2C_INSTANCE (I2CDEV_1)
#define USE_ADC
#define ADC_INSTANCE ADC3
#define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT
//#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BURST DSHOT_DMAR_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define BEEPER_INVERTED
#define MAX7456_SPI_INSTANCE SPI3
#define FLASH_SPI_INSTANCE SPI2
#define USE_SPI_GYRO
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN CW270_DEG