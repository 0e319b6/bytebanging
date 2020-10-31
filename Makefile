CC = gcc
CPP = g++

all: play_sin play_saw play_string fir_filter bytebeat noise

play_sin: play_sin.c
	$(CC) -lm -o play_sin play_sin.c

play_saw: play_saw.c
	$(CC) -o play_saw play_saw.c

play_string: play_string.c
	$(CC) -lm -o play_string play_string.c

fir_filter: fir_filter.cc
	$(CPP) -lm -o fir_filter fir_filter.cc

bytebeat: bytebeat.c
	$(CC) -o bytebeat bytebeat.c

noise: noise.c
	$(CC) -o noise noise.c

.PHONY: clean all
clean:
	rm play_sin
	rm play_saw
	rm play_string
	rm fir_filter
	rm bytebeat
	rm noise
