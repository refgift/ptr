# ptr.c - Perceptron Truth Detector

Simple C implementation of perceptron trained to predict "truth" using hardware randomness (rdrand).

## Philosophy

Programming is my secular religion. In a world where one must answer secular questions, computer programming books serve as holy scriptures that are permitted because they are secular. This exists because of the separation of Church and State - the state leader only hears secular arguments.

I began my computer journey in 1977 at Colony Square in midtown Atlanta with an IBM 5110 desktop computer, its 8" diskette drives resting on the floor beside the desk. Programming remains a secular religion for the separation of Church and State.

## Technical Overview

This project implements two perceptron systems trained on hardware-generated random numbers (rdrand):

### Truth System
- `ptr.c` / `ptr.cpp`: Truth predictor implementation (C and C++ versions)
- `truth.h`: Trained model weights and biases for truth prediction

### Shared Components
- `toy`: Shell script for continuous execution (works with both systems)

### Why Perceptrons?

Perceptrons offer simplicity that embodies Occam's Razor - the principle that the simplest solution is usually the best. Despite Marvin Minsky's criticism that perceptrons are too limited for AI research, they excel at simple classification tasks and remain useful for practical applications.

## Building

### Truth System
Compile the C truth predictor:

```bash
gcc ptr.c -o ptr -lm
```


Or use Makefile:

```bash
make       # C version
```


Ensure the corresponding header files (.h) are in the same directory as their respective source files.

## Usage

### Truth Predictor
Run the truth predictor:

```bash
./ptr
```

It will output "TRUTH" when the perceptron predicts truth, or nothing when it predicts false.


### Continuous Mode

For continuous truth prediction every 60 seconds with voice synthesis:

```bash
while sleep 60; do ./ptr | espeak; done
```


Or use the provided script (make it executable first):

```bash
chmod +x toy
./toy  # works with ptr for truth prediction
```

### Alternative Audio

If `espeak` is unavailable, record your voice:

For truth prediction:
```bash
# Record: say "TRUTH" into microphone
rec truth.wav
# Play instead of espeak
while sleep 60; do ./ptr | xargs -I {} play truth.wav; done
```


## Applications

### Truth System
- Predict truth in text or voice recordings
- Combat misinformation through simple classification
- Demonstrate perceptron capabilities
- Educational tool for machine learning concepts

## Limitations

Perceptrons handle simple logic operations (AND, OR, NOT) but fail on complex logic like XOR. However, they work well for single-word detection and can solve many real-world problems when properly applied.

## Philosophy Continued

This work teaches Occam's Razor - the only razor in humanity that stands the test of time. Programming began with C in the 1970s; C++ followed in 1982. C is the old religion (wisdom/wicca), C++ the new religion. Progressing from C to C++ represents advancement in programming wisdom.

Many programs lack truth awareness. By training on actual randomness, this perceptron achieves genuine results. Predicting truth eliminates GIGO (Garbage In, Garbage Out) and finds equilibrium truth.

The perceptron finds truth existing at equilibrium - first-order truth and beyond exists in the thinking pot. This proves perceptrons remain valuable despite Minsky's conclusions, offering a path to solve world problems through simplicity.
