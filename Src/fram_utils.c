#include "fram_utils.h"

#define TRIAL_COUNT     (3)
#define COMM_TIMEOUT    (1000)

static volatile bool fram_i2c_initialized = false;
static uint16_t fram_addr;


void fram_init(uint16_t addr)
{
    if (!fram_i2c_initialized) {
        MX_I2C1_Init();
        fram_addr = addr;
        fram_i2c_initialized = true;
    }
}


void fram_deinit(void)
{
    if (fram_i2c_initialized) {
        HAL_I2C_DeInit(&hi2c1);
        fram_i2c_initialized = false;
    }
}


HAL_StatusTypeDef fram_is_ready(void)
{
    return HAL_I2C_IsDeviceReady(&hi2c1, fram_addr, TRIAL_COUNT, COMM_TIMEOUT);
}


HAL_StatusTypeDef fram_write_buffer(uint16_t offset, uint8_t* buffer, uint16_t size)
{
    HAL_StatusTypeDef status = fram_is_ready();
    if (status == HAL_OK)
        status = HAL_I2C_Mem_Write(&hi2c1,
                                   fram_addr,
                                   (STORAGE_BASE_ADDR + offset),
                                   I2C_MEMADD_SIZE_16BIT,
                                   buffer,
                                   size,
                                   COMM_TIMEOUT);

    return status;
}


HAL_StatusTypeDef fram_write(uint16_t offset, uint8_t data)
{
    return fram_write_buffer(offset, &data, 1);
}


HAL_StatusTypeDef fram_read_buffer(uint16_t offset, uint8_t* buffer, uint16_t size)
{
    HAL_StatusTypeDef status = fram_is_ready();
    if (status == HAL_OK)
        status = HAL_I2C_Mem_Read(&hi2c1,
                                  fram_addr,
                                  (STORAGE_BASE_ADDR + offset),
                                  I2C_MEMADD_SIZE_16BIT,
                                  buffer,
                                  size,
                                  COMM_TIMEOUT);

    return status;
}


uint8_t fram_read(uint16_t offset)
{
    uint8_t data = 0xff;
    fram_read_buffer(offset, &data, 1);
    return data;
}
