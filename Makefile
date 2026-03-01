# Makefile for ptr.c and ptr.cpp perceptron predictors.
# Makes ./ptr (C version) and ./ptr_cpp (C++ version), Linux terminal applications.
# Windows can run Linux as a subsystem.
# Remember Occam\'s Razor for programming miracles.

.c.o:
	cc -c $< -o $@

ptr: 	ptr.o
	cc $< -o $@ -lm

.cpp.o:
	g++ -c $< -o $@

ptr_cpp:	ptr.cpp
	g++ $< -o $@ -lm

ppr_cpp:	ppr.cpp
	g++ $< -o $@ -lm
