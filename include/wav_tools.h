#ifndef _WAV_TOOLS_H_
#define _WAV_TOOLS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct riff_chunk_s {
    char sig[4];
    uint32_t size;
    uint8_t *data;
};
typedef struct riff_chunk_s riff_chunk;

struct audio_samples_s {
    /* Sample types
     * 0 - unsigned 8 bit integer
     * 1 - signed 8 bit integer
     * 2 - unsigned 16 bit integer
     * 3 - signed 16 bit integer
     * 4 - unsigned 32 bit integer
     * 5 - signed 32 bit integer
     * 6 - 32 bit IEEE 754 floating point
     * 7 - 64 bit IEEE 754 floating point
     */
    uint8_t type;
    uint16_t length;
    void *samples;
};
typedef struct audio_samples_s audio_samples;

/*
 * swap_bytes(void *data, size_t length)
 * Function to swap byte order in data
 *      *data : pointer to memory with bytes to swap_bytes
 *      length: number of bytes to swap
 */
void swap_bytes(void *data_vp, size_t length);

riff_chunk *get_riff_chunk(FILE *file);

void free_riff_chunk(riff_chunk *chunk);

void print_riff_chunk(riff_chunk *chunk);

audio_samples get_samples(FILE *audio_file);
#endif
