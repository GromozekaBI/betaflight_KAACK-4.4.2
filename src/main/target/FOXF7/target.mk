RX_SRC = \
    rx/cc2500_common.c \
    rx/cc2500_frsky_shared.c \
    rx/cc2500_frsky_d.c \
    rx/cc2500_frsky_x.c \
    rx/cc2500_sfhss.c \
    rx/cc2500_redpine.c \
    rx/a7105_flysky.c \
    rx/cyrf6936_spektrum.c \
    drivers/rx/expresslrs_driver.c \
    rx/expresslrs.c \
    rx/expresslrs_common.c \
    rx/expresslrs_telemetry.c \
    drivers/rx/rx_cc2500.c \
    drivers/rx/rx_a7105.c \
    drivers/rx/rx_cyrf6936.c \
    drivers/rx/rx_sx127x.c \
    drivers/rx/rx_sx1280.c \


F7X2RE_TARGETS += $(TARGET)
FEATURES       += VCP SDCARD_SPI SDCARD_SDIO ONBOARDFLASH

TARGET_SRC = \
    $(addprefix drivers/accgyro/,$(notdir $(wildcard $(SRC_DIR)/drivers/accgyro/*.c))) \
	$(ROOT)/lib/main/BoschSensortec/BMI270-Sensor-API/bmi270_maximum_fifo.c \
	$(addprefix drivers/barometer/,$(notdir $(wildcard $(SRC_DIR)/drivers/barometer/*.c))) \
	$(addprefix drivers/compass/,$(notdir $(wildcard $(SRC_DIR)/drivers/compass/*.c))) \
            drivers/accgyro/accgyro_mpu6500.c \
            drivers/accgyro/accgyro_spi_mpu6000.c \
            drivers/accgyro/accgyro_spi_mpu6500.c \
            drivers/barometer/barometer_bmp280.c \
            drivers/barometer/barometer_ms5611.c \
            drivers/compass/compass_hmc5883l.c \
            drivers/compass/compass_lis3mdl.c \
            drivers/max7456.c \
	drivers/vtx_rtc6705.c \
	drivers/vtx_rtc6705_soft_spi.c \
	$(RX_SRC)
# TARGET_SRC = \
#     $(addprefix drivers/accgyro/,$(notdir $(wildcard $(SRC_DIR)/drivers/accgyro/*.c))) \
# 	$(ROOT)/lib/main/BoschSensortec/BMI270-Sensor-API/bmi270_maximum_fifo.c \
# 	$(addprefix drivers/barometer/,$(notdir $(wildcard $(SRC_DIR)/drivers/barometer/*.c))) \
# 	$(addprefix drivers/compass/,$(notdir $(wildcard $(SRC_DIR)/drivers/compass/*.c))) \
# 	drivers/max7456.c \
# 	drivers/vtx_rtc6705.c \
# 	drivers/vtx_rtc6705_soft_spi.c \
# 	$(RX_SRC)