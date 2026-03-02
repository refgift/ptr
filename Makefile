# Makefile for ptr.c perceptron predictor.
# Makes ./ptr (C version)  Linux terminal applications.
# Windows can run Linux as a subsystem.
# Remember Occam\'s Razor for programming miracles.

.c.o:
	cc -c $< -o $@

ptr: 	ptr.o
	cc $< -o $@ -lm

clean: 
	rm *.o
