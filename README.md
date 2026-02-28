Many programs have no idea of truth. By training on rdrand results the preceptron biases and wieghts are written in truth.c; the predictor ptr.c uses the 
wieghts and biases to predict truth in reality. Training it on actual randomness is a funny way to get actual perceptron results.
predicting truth is a way to get rid of GIGO. You can use it in the real world or predict truth of a line of text or a recording of voice. 
truth.h and ptr.c compile with a simple gcc ptr.c -o ptr -lm if and only if you place the truth.h in the same project directory. 
If you run as it stands, It will use rdrand, random number from your computer as input. It should be easily changed to some other input.
