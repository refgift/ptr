Many programs have no idea of truth. By training on rdrand results the perceptron biases and wieghts are written in truth.c; the predictor ptr.c uses the 
wieghts and biases to predict truth in reality. Training it on actual randomness is a funny way to get actual perceptron results.
predicting truth is a way to get rid of GIGO. You can use it in the real world or predict truth of a line of text or a recording of voice. 
truth.h and ptr.c compile with a simple gcc ptr.c -o ptr -lm if and only if you place the truth.h in the same project directory. 
If you run as it stands, It will use rdrand, random number from your computer as input. It should be easily changed to some other input.

This ptr finds the truth existing at equilibrium. Truth at 1st order and beyond is in the thinking pot. To play with it, try this, assumming Linux usig bash shell:

while sleep 60; do ./ptr | espeak; done

This is proof that perceptrons still have a use depite Minsky concluding that they are too limited for AI research. 
I understand his point, They fail to solve certain complex logics. For example, they solve simple logic 
like [and|or|not] but fail on [xor] level of complexity. That is exclusive or logic that they fail on. 
Fortunately, perceptron does fine with 1 word detectors and that is path to a world of simple world problems to 
solve like misinformation.
