//#ifndef CRC32_H
//#define CRC32_H
#include "Main_Form.h"
static uint32_t crc32_table[256];
static uint32_t crc32r_table[256];

#define CRC32_POLY   0x04C11DB7
#define CRC32_POLY_R 0xEDB88320

static void crc32_init(void)
{
        int i, j;
        uint32_t c, cr;
        for (i = 0; i < 256; ++i) {
                cr = i;
                c = i << 24;
                for (j = 8; j > 0; --j) {
                        c = c & 0x80000000 ? (c << 1) ^ CRC32_POLY : (c << 1);
                        cr = cr & 0x00000001 ? (cr >> 1) ^ CRC32_POLY_R : (cr >> 1);
                        }
                crc32_table[i] = c;
                crc32r_table[i] = cr;
                //printf("f[%02X]=%08X\t", i, crc32_table[i]);
                //printf("r[%02X]=%08X\t", i, crc32r_table[i]);
        }
        //printf("\n");
}


uint32_t crc32_stm32(uint32_t init_crc, uint32_t *buf, int len)
{
		crc32_init();

        uint32_t v;
        uint32_t crc;
        crc = ~init_crc;
        while(len >= 4) {
                v = htonl(*buf++);
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v ) )];
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v >> 8) )];
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v >> 16) )];
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v >> 24) )];
                len -= 4;
        }
        if(len) {
                switch(len) {
                        case 1: v = 0xFF000000 & htonl(*buf++); break;
                        case 2: v = 0xFFFF0000 & htonl(*buf++); break;
                        case 3: v = 0xFFFFFF00 & htonl(*buf++); break;
                }
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v ) )];
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v >> 8) )];
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v >> 16) )];
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v >> 24) )];
        }
        return ~crc;
}

//-------------------------------------------------------------------------

uint32_t sw_calculate_soft_crc(uint32_t *pinput, uint32_t length)
{
	uint32_t initial_crc = 0xFFFFFFFF;                   // начальное значение контрольной суммы
	uint32_t* input_data = pinput;
	uint32_t polynom     = 0x4C11DB7 ;                   // полином
	uint32_t crc         = 0         ;                   // контрольная сумма
	uint32_t index       = 0;
	uint32_t bindex      = 0;

    while( index<length )
    {
    if(index==0){   crc = initial_crc ^ input_data[index];}
    else        {   crc = crc ^ input_data[index];        }

        while(   bindex<(sizeof(input_data[index])*8)   )
        {	// if MSB of CRC = 1
            if((crc>>31)==1){crc=(crc<<1)^polynom;}
            else            {crc=(crc<<1);        }
            bindex++;
        }

    bindex=0;
    index++;
    }

    return crc;
}

