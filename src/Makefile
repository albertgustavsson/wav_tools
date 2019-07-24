INCLUDEPATH = ../include
OPTS = -std=c99 -Wall -I $(INCLUDEPATH)
DEBUGOPTS = -std=c99 -g -I $(INCLUDEPATH)

all: wav_read_example

wav_read_example: wav_read_example.c wav_tools.o
	gcc $(DEBUGOPTS) -o $@ $< wav_tools.o

wav_tools.o: wav_tools.c
	gcc $(DEBUGOPTS) -c -o $@ $<

test: test.c wav_tools.o
	gcc $(DEBUGOPTS) -o $@ $< wav_tools.o
	./test

clean:
	-rm ./wav_tools.o
	-rm ./wav_read_example.exe
	-rm ./test

run: all
	./wav_read_example

memtest: all
	valgrind --leak-check=full --show-reachable=yes ./wav_read_example
