//---------------------------------------------------------------------------

#ifndef CRC32H
#define CRC32H
#include "Main_Form.h"
//---------------------------------------------------------------------------
void crc32_init(void);
uint32_t crc32_stm32(uint32_t init_crc, uint32_t *buf, int len);
uint32_t sw_calculate_soft_crc(uint32_t *pinput, uint32_t length);
#endif
