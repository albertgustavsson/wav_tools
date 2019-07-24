#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#include "wav_tools.h"


/*
 * swap_bytes
 * Function to swap byte order in data
 */
void swap_bytes(void *data_vp, size_t length)
{
        uint8_t *data_ui8 = data_vp;
        uint8_t *newdata = malloc(length);
        for(int i = 0; i < length; i++) {
                newdata[i] = data_ui8[length-1-i];
        }

        memcpy(data_ui8, newdata, length);
        for(int i = 0; i < length; i++) {
                data_ui8[i] = newdata[i];
        }
        free(newdata);
}


/*
 * Get RIFF chunk from file. RIFF chunk must be free'd with freeRIFFChunk()
 */
riff_chunk *get_riff_chunk(FILE *file)
{
        riff_chunk *rc = malloc(sizeof(riff_chunk));

        if(fread((void *)rc->sig, 1, 4, file) != 4) {
                fprintf(stderr, "Couldn't read RIFF signature\n");
                free(rc);
                return NULL;
        }

        if(fread(&(rc->size), 4, 1, file) != 1) {
                fprintf(stderr, "Couldn't read RIFF chunk size\n");
                free(rc);
                return NULL;
        }

        rc->data = malloc(rc->size);

        if(fread((void *)rc->data, 1, rc->size, file) != rc->size) {
                fprintf(stderr, "Couldn't read RIFF chunk data\n");
                free(rc);
                return NULL;
        }

        return rc;
}

/*
 * Frees RIFFChunk memory
 */
void free_riff_chunk(riff_chunk *rc)
{
        free(rc->data);
        free(rc);
}

/*
 * png_print_chunk_data
 * Function to print length and type of a chunk
 */
void print_riff_chunk(riff_chunk *rc)
{
        char *s = rc->sig;
        printf("Chunk signature: %c%c%c%c\n", s[0], s[1], s[2], s[3]);
        printf("Chunk size: %u\n", rc->size);
        printf("Chunk data: ");

        for(uint32_t i = 0; i < rc->size; i++) {
                printf("%2x\n", rc->data[i]);
        }
}
