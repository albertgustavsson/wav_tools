#include <stdio.h>

#include "wav_tools.h"


int main(int argc, char *argv[])
{
        FILE *audioFile = fopen(argv[1], "rb");

        RIFFChunk *riff = getRIFFChunk(audioFile);

        printRIFFChunk(riff);

        freeRIFFChunk(riff);

        //WAVAudioData *testData = getWavAudio(riff);

        fclose(audioFile);
        return 0;
}
