#include <stdio.h>

#include "wav_tools.h"


int main(int argc, char *argv[])
{
        FILE *audio_file = fopen(argv[1], "rb");

        audio_samples samples = get_samples(audio_file);
        printf("Number of samples: %d\n", samples.length);

        fclose(audio_file);
        return 0;
}
