#ifndef _WAV_TOOLS_H_
#define _WAV_TOOLS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct RIFFChunk_s {
        char sig[4];
        uint32_t size;
        uint8_t *data;
};
typedef struct RIFFChunk_s RIFFChunk;

/*
 * swap_bytes(void *data, size_t length)
 * Function to swap byte order in data
 *      *data : pointer to memory with bytes to swap_bytes
 *      length: number of bytes to swap
 */
void swap_bytes(void *data_vp, size_t length);

#endif
