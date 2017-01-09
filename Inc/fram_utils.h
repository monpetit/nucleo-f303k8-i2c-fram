#ifndef __FRAM_UTILS_H
#define __FRAM_UTILS_H

#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"

#define FRAM_ADDR           (0x50 << 1) /* 0b1010 (slave id) + 0b000(device select) */
#define STORAGE_BASE_ADDR   (0)

void fram_init(uint16_t addr);
void fram_deinit(void);
HAL_StatusTypeDef fram_is_ready(void);
HAL_StatusTypeDef fram_write_buffer(uint16_t offset, uint8_t* buffer, uint16_t size);
HAL_StatusTypeDef fram_write(uint16_t offset, uint8_t data);
HAL_StatusTypeDef fram_read_buffer(uint16_t offset, uint8_t* buffer, uint16_t size);
uint8_t fram_read(uint16_t offset);

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

#endif /* __FRAM_UTILS_H */
