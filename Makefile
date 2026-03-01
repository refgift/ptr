# Makefile for ptr.c perceptron predictor. 
# Makes ./ptr, a Linux terminal application.
# Windows can run Linux as a subsystem.
# Remember Occam\'s Razor for programming miracles.

.c.o:
	cc -c $< -o $@

ptr: 	ptr.o
	cc $< -o $@
