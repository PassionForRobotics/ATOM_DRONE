#ifndef NEURALNET1_H
#define NEURALNET1_H


#define C_PRINT // Not arduino environment
#define ACTIVATION_TEST_ONLY // no train and use trained data
#define CHECK_FIXED_TRAINING

class Neuralnet1
{
public:
    Neuralnet1(float ** Input_test, float ** Target_test
, int _PatternCount  
, int _InputNodes  , int _HiddenNodes, int _OutputNodes 
, float _LearningRate  , float _Momentum, float _InitialWeightMax 
, float _Success);
    ~Neuralnet1();
    void initialize(); // return as error
    void train();
    void toTerminal();
    void activate(float inarray[], int inlen, float outarray[], int outlen);
    void saveWeights(char* fileName);
    void loadWeights(char* fileName);

    Neuralnet1& SetInputNodes(int InputNodes)
    {
	this->InputNodes = InputNodes;
	return *this;
    }

    int GetInputNodes() const
    {
	return InputNodes;
    }

    Neuralnet1& SetOutputNodes(int OutputNodes)
    {
		this->OutputNodes = OutputNodes;
		return *this;
    }
	
    int GetOutputNodes() const
    {
		return OutputNodes;
    }

private:
    int PatternCount;
    int InputNodes;
    int HiddenNodes;
    int OutputNodes;
    float LearningRate;
    float Momentum;
    float InitialWeightMax;
    float Success;

    float** Input;
    float** Target;

    int i, j, p, q, r;
    int ReportEvery1000;
    int* RandomizedIndex; //[PatternCount];
    long TrainingCycle;
    float Rando;
    float Error;
    float Accum;

    float* Hidden;               //[HiddenNodes];
    float* Output;               //[OutputNodes];
    float** HiddenWeights;       //[InputNodes + 1][HiddenNodes];
    float** OutputWeights;       //[HiddenNodes + 1][OutputNodes];
    float* HiddenDelta;          //[HiddenNodes];
    float* OutputDelta;          //[OutputNodes];
    float** ChangeHiddenWeights; //[InputNodes + 1][HiddenNodes];
    float** ChangeOutputWeights; //[HiddenNodes + 1][OutputNodes];

    void writeToaFile(char* fileName);
    void loadWeightsFromFile(char* fileName);
};

#endif // NEURALNET1_H
