/******************************************************************
   ArduinoANN - An artificial neural network for the Arduino
   All basic settings can be controlled via the Network Configuration
   section.
   See robotics.hobbizine.com/arduinoann.html for details.
 ******************************************************************/

/*
 *
 *
 * TrainingCycle: 41076119  Error = 0.00001

  Training Pattern: 0  Input  1.000  1.000  1.000  1.000  1.000  1.000  0.000   Target  0.000  0.000  0.000  0.000   Output  0.00083  0.00083  0.00070  0.00075
  Training Pattern: 1  Input  0.000  1.000  1.000  0.000  0.000  0.000  0.000   Target  0.000  0.000  0.000  1.000   Output  0.00012  0.00100  0.00083  0.99921
  Training Pattern: 2  Input  1.000  1.000  0.000  1.000  1.000  0.000  1.000   Target  0.000  0.000  1.000  0.000   Output  0.00092  0.00021  1.00000  0.00098
  Training Pattern: 3  Input  1.000  1.000  1.000  1.000  0.000  0.000  1.000   Target  0.000  0.000  1.000  1.000   Output  0.00072  0.00088  0.99910  0.99914
  Training Pattern: 4  Input  0.000  1.000  1.000  0.000  0.000  1.000  1.000   Target  0.000  1.000  0.000  0.000   Output  0.00041  0.99958  0.00063  0.00040
  Training Pattern: 5  Input  1.000  0.000  1.000  1.000  0.000  1.000  1.000   Target  0.000  1.000  0.000  1.000   Output  0.00049  0.99929  0.00120  0.99963
  Training Pattern: 6  Input  0.000  0.000  1.000  1.000  1.000  1.000  1.000   Target  0.000  1.000  1.000  0.000   Output  0.00000  0.99927  0.99897  0.00000
  Training Pattern: 7  Input  1.000  1.000  1.000  0.000  0.000  0.000  0.000   Target  0.000  1.000  1.000  1.000   Output  0.00000  0.99881  0.99893  0.99999
  Training Pattern: 8  Input  1.000  1.000  1.000  1.000  1.000  1.000  1.000   Target  1.000  0.000  0.000  0.000   Output  0.99865  0.00000  0.00026  0.00050
  Training Pattern: 9  Input  1.000  1.000  1.000  0.000  0.000  1.000  1.000   Target  1.000  0.000  0.000  1.000   Output  0.99918  0.00032  0.00000  0.99950

Training Set Solved!
--------

HiddenWeights=
{
	{-3.477440,2.678823,-1.890451,2.429075,3.062039,1.466780,2.143420,-1.253443},
	{3.451729,-1.536530,2.251330,-2.000000,-4.438273,-3.531740,-0.390288,2.000000},
	{-7.402481,-4.062773,-0.383367,0.508765,-1.143037,4.611711,3.496842,-0.500000},
	{6.316988,0.294654,-2.064504,0.522832,-1.623320,-6.124825,-0.999999,-1.043041},
	{-3.069669,1.063713,0.579201,4.000000,1.547853,-4.861787,-0.886345,0.756814},
	{-3.460141,7.405190,-2.352268,0.362883,-3.933047,7.064098,0.502063,-3.572501},
	{-8.000000,3.792803,2.497474,2.618558,2.000000,-1.462113,-8.000000,4.000000},
	{-1.241549,-1.496270,3.196710,1.404968,-4.564205,1.130443,-4.667371,2.569994}
}
OutputWeights=
{
	{1.113935,2.028543,-6.833564,-6.460591,-2.128460,8.088761,-8.002007,-7.486404,-0.167645},
	{-5.905791,-1.830506,15.132903,4.980490,-6.816560,-5.292979,3.814512,4.001953,-0.495854},
	{-1.790511,-1.877855,5.375463,11.635944,4.783153,-8.250873,4.000000,-6.212863,-0.873748},
	{-7.472363,9.438042,-3.881657,1.045659,-0.090821,0.841093,-4.455671,5.905634,-0.830129}
}
End

  Training Pattern: 0  Input  1.000  1.000  1.000  1.000  1.000  1.000  0.000   Target  0.000  0.000  0.000  0.000   Output  0.00083  0.00083  0.00070  0.00075
  Training Pattern: 1  Input  0.000  1.000  1.000  0.000  0.000  0.000  0.000   Target  0.000  0.000  0.000  1.000   Output  0.00012  0.00100  0.00083  0.99921
  Training Pattern: 2  Input  1.000  1.000  0.000  1.000  1.000  0.000  1.000   Target  0.000  0.000  1.000  0.000   Output  0.00092  0.00021  1.00000  0.00098
  Training Pattern: 3  Input  1.000  1.000  1.000  1.000  0.000  0.000  1.000   Target  0.000  0.000  1.000  1.000   Output  0.00072  0.00088  0.99910  0.99914
  Training Pattern: 4  Input  0.000  1.000  1.000  0.000  0.000  1.000  1.000   Target  0.000  1.000  0.000  0.000   Output  0.00041  0.99958  0.00063  0.00040
  Training Pattern: 5  Input  1.000  0.000  1.000  1.000  0.000  1.000  1.000   Target  0.000  1.000  0.000  1.000   Output  0.00049  0.99929  0.00120  0.99963
  Training Pattern: 6  Input  0.000  0.000  1.000  1.000  1.000  1.000  1.000   Target  0.000  1.000  1.000  0.000   Output  0.00000  0.99927  0.99897  0.00000
  Training Pattern: 7  Input  1.000  1.000  1.000  0.000  0.000  0.000  0.000   Target  0.000  1.000  1.000  1.000   Output  0.00000  0.99881  0.99893  0.99999
  Training Pattern: 8  Input  1.000  1.000  1.000  1.000  1.000  1.000  1.000   Target  1.000  0.000  0.000  0.000   Output  0.99865  0.00000  0.00026  0.00050

 */
 


#include "neuralnet1.h"
 
#if defined(C_PRINT)
#include <stdio.h>
#endif 

int main ()
{
	int i = 0 ;
	int PatternCount = 10;
	int InputNodes = 7;
	int HiddenNodes = 8;
	int OutputNodes = 4;
	float LearningRate = 0.3;
	float Momentum = 0.9;
	float InitialWeightMax = 0.5;
	float Success = 0.000004;
	
	float Input_test[PatternCount][InputNodes] = {
		{ 1, 1, 1, 1, 1, 1, 0 },  // 0
		{ 0, 1, 1, 0, 0, 0, 0 },  // 1
		{ 1, 1, 0, 1, 1, 0, 1 },  // 2
		{ 1, 1, 1, 1, 0, 0, 1 },  // 3
		{ 0, 1, 1, 0, 0, 1, 1 },  // 4
		{ 1, 0, 1, 1, 0, 1, 1 },  // 5
		{ 0, 0, 1, 1, 1, 1, 1 },  // 6
		{ 1, 1, 1, 0, 0, 0, 0 },  // 7
		{ 1, 1, 1, 1, 1, 1, 1 },  // 8
		{ 1, 1, 1, 0, 0, 1, 1 }   // 9
		//{ 0, 0, 0, 0, 0, 0, 0 }   // none
	};
	
	float Target_test[PatternCount][OutputNodes] = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 1 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 1 },
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 1 }
		//{ 0, 0, 0, 0 }
	};
	
	//////////////////////
	// Manual work here ////////////|
	//////////////////////         \||/
	//								 .  
	
	float * input_test_rows[PatternCount] = { 
		Input_test[0]
		, Input_test[1]
		, Input_test[2]
		, Input_test[3]
		, Input_test[4]
		, Input_test[5]
		, Input_test[6]
		, Input_test[7]
		, Input_test[8]
		, Input_test[9] 
		};
		
	float * target_test_rows[PatternCount] = { 
		Target_test[0]
		, Target_test[1]
		, Target_test[2]
		, Target_test[3]
		, Target_test[4]
		, Target_test[5]
		, Target_test[6]
		, Target_test[7]
		, Target_test[8]
		, Target_test[9] 
		} ;
	
	float ** input_test = input_test_rows;
	float ** target_test = target_test_rows;
	
	// Comman part
	Neuralnet1 nnet1(input_test, target_test
	, PatternCount, InputNodes, HiddenNodes, OutputNodes
	, LearningRate, Momentum, InitialWeightMax, Success);
	
	nnet1.initialize();
	
	float outarray[nnet1.GetOutputNodes()] = {0};
	float inarray[nnet1.GetInputNodes()] = {0,0,0,0,0,0,0}; // is misclasifying as 7, Target[7]
	
	// Example 1
	////////////////////////////////////////////////////////////////////
	nnet1.train();
	
	nnet1.activate(inarray, nnet1.GetInputNodes(), outarray, nnet1.GetOutputNodes());
	
	for ( i = 0 ; i < nnet1.GetOutputNodes() ; i++ ) 
	{
		printf(" %5.5f ", outarray[i]);
	}
	
	printf("\r\n\r\n");
	nnet1.saveWeights("test1.csv"); // if all fine save it.
	////////////////////////////////////////////////////////////////////
	
	// Example 2
	////////////////////////////////////////////////////////////////////
	nnet1.loadWeights("test.csv");
	
	nnet1.activate(inarray, nnet1.GetInputNodes(), outarray, nnet1.GetOutputNodes());
	
	for ( i = 0 ; i < nnet1.GetOutputNodes() ; i++ ) 
	{
		printf(" %5.5f ", outarray[i]);
	}
	
	printf("\r\n\r\n"); 
	////////////////////////////////////////////////////////////////////
	 
	//while(1); 
	return 0;
}
