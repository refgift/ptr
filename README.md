# ptr.c - Adjusting on the fly / Micro-changes keep us true / Never losing course

Simple C implementation of perceptron trained to predict "truth" using hardware randomness (rdrand).
- Running this using the "toy" script is a level 2 AI operating the principle: "The truth will set you free"
- See licensetest.ai for the 10 levels of AI.

## Philosophy

The AI is simple intellence with the advantage that it runs continuously and operates a principle, a software, a robot, a vehicle, etc. depending
on how intelligent and computable it is.

## Technical Overview

This project implements 1 perceptron system trained on hardware-generated random numbers (rdrand instruction opcode): The perceptron has been
pretrained by me. My theory is that reality is at equilibrium, the computer entropy is a measure of equilibrium  thus reality. I train
on randomness instead of cats, dogs, numbers, letters, just random numbers from the hardware rdrand opcode. 
It works for "truth" but fails for "perfect". 
 
### Truth System
- `ptr.c` : Truth predictor implementation
- `truth.h`: Trained model weights and biases for truth prediction

### Shared Components
- `toy`: Shell script for continuous execution (operating a principle)

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

Perceptrons handle simple logic operations (AND, OR, NOT) but fail on complex logic like XOR. 









