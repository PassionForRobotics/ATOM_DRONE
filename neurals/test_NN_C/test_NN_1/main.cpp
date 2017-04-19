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


 * 
 * 
 */

#define C_PRINT

#include <math.h>

/******************************************************************
   Network Configuration - customized per network
 ******************************************************************/

#if defined(C_PRINT)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#endif

const int PatternCount = 10;
const int InputNodes = 7;
const int HiddenNodes = 8;
const int OutputNodes = 4;
const float LearningRate = 0.13;
const float Momentum = 0.19;
const float InitialWeightMax = 0.5;
const float Success = 0.01;

const float Input[PatternCount][InputNodes] = {
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
};

const float Target[PatternCount][OutputNodes] = {
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
};

/******************************************************************
   End Network Configuration
 ******************************************************************/


int i, j, p, q, r;
int ReportEvery1000;
int RandomizedIndex[PatternCount];
long  TrainingCycle;
float Rando;
float Error;
float Accum;


float Hidden[HiddenNodes];
float Output[OutputNodes];
float HiddenWeights[InputNodes + 1][HiddenNodes];
float OutputWeights[HiddenNodes + 1][OutputNodes];
float HiddenDelta[HiddenNodes];
float OutputDelta[OutputNodes];
float ChangeHiddenWeights[InputNodes + 1][HiddenNodes];
float ChangeOutputWeights[HiddenNodes + 1][OutputNodes];

#if defined(C_PRINT)

void writeToaFile();

int random(int n)
{
  return (int)(rand() % n);
}
#endif

void toTerminal();

void setup() {

#if !defined(C_PRINT)
  Serial.begin(250000);
#else
  time_t t;
  srand((unsigned) time(&t));
#endif //C_PRINT

  //randomSeed(analogRead(3));
  ReportEvery1000 = 1;
  for ( p = 0 ; p < PatternCount ; p++ ) {
    RandomizedIndex[p] = p ;
  }
}

void loop () {


  /******************************************************************
    Initialize HiddenWeights and ChangeHiddenWeights
  ******************************************************************/

  for ( i = 0 ; i < HiddenNodes ; i++ ) {
    for ( j = 0 ; j <= InputNodes ; j++ ) {
      ChangeHiddenWeights[j][i] = 0.0 ;

      float rr = float(random(100));
      // #if !defined(C_PRINT)
      //       //Serial.println("Initial/Untrained Outputs: ");
      // #else
      //       printf("\nRrrR %f", rr);
      // #endif
      Rando = rr / 100;

      HiddenWeights[j][i] = 2.0 * ( Rando - 0.5 ) * InitialWeightMax ;

      //  #if !defined(C_PRINT)
      // //       //Serial.println("Initial/Untrained Outputs: ");
      //  #else
      //        printf("\nRrrR %f", HiddenWeights[j][i]);
      //  #endif

    }
  }
  /******************************************************************
    Initialize OutputWeights and ChangeOutputWeights
  ******************************************************************/

  for ( i = 0 ; i < OutputNodes ; i ++ ) {
    for ( j = 0 ; j <= HiddenNodes ; j++ ) {
      ChangeOutputWeights[j][i] = 0.0 ;
      Rando = float(random(100)) / 100;
      OutputWeights[j][i] = 2.0 * ( Rando - 0.5 ) * InitialWeightMax ;
    }
  }
#if !defined(C_PRINT)
  Serial.println("Initial/Untrained Outputs: ");
#else
  printf("Initial/Untrained Outputs: ");
#endif
  toTerminal();
  /******************************************************************
    Begin training
  ******************************************************************/

  for ( TrainingCycle = 1 ; TrainingCycle < 2147483647 ; TrainingCycle++) {

    /******************************************************************
      Randomize order of training patterns
    ******************************************************************/

    for ( p = 0 ; p < PatternCount ; p++) {
      q = random(PatternCount);
      r = RandomizedIndex[p] ;
      RandomizedIndex[p] = RandomizedIndex[q] ;
      RandomizedIndex[q] = r ;
    }
    Error = 0.0 ;
    /******************************************************************
      Cycle through each training pattern in the randomized order
    ******************************************************************/
    for ( q = 0 ; q < PatternCount ; q++ ) {
      p = RandomizedIndex[q];

      /******************************************************************
        Compute hidden layer activations
      ******************************************************************/

      for ( i = 0 ; i < HiddenNodes ; i++ ) {
        Accum = HiddenWeights[InputNodes][i] ;
        for ( j = 0 ; j < InputNodes ; j++ ) {
          Accum += Input[p][j] * HiddenWeights[j][i] ;
        }
        Hidden[i] = 1.0 / (1.0 + exp(-Accum)) ;
      }

      /******************************************************************
        Compute output layer activations and calculate errors
      ******************************************************************/

      for ( i = 0 ; i < OutputNodes ; i++ ) {
        Accum = OutputWeights[HiddenNodes][i] ;
        for ( j = 0 ; j < HiddenNodes ; j++ ) {
          Accum += Hidden[j] * OutputWeights[j][i] ;
        }
        Output[i] = 1.0 / (1.0 + exp(-Accum)) ;
        OutputDelta[i] = (Target[p][i] - Output[i]) * Output[i] * (1.0 - Output[i]) ;
        Error += 0.5 * (Target[p][i] - Output[i]) * (Target[p][i] - Output[i]) ;
      }

      /******************************************************************
        Backpropagate errors to hidden layer
      ******************************************************************/

      for ( i = 0 ; i < HiddenNodes ; i++ ) {
        Accum = 0.0 ;
        for ( j = 0 ; j < OutputNodes ; j++ ) {
          Accum += OutputWeights[i][j] * OutputDelta[j] ;
        }
        HiddenDelta[i] = Accum * Hidden[i] * (1.0 - Hidden[i]) ;
      }


      /******************************************************************
        Update Inner-->Hidden Weights
      ******************************************************************/


      for ( i = 0 ; i < HiddenNodes ; i++ ) {
        ChangeHiddenWeights[InputNodes][i] = LearningRate * HiddenDelta[i] + Momentum * ChangeHiddenWeights[InputNodes][i] ;
        HiddenWeights[InputNodes][i] += ChangeHiddenWeights[InputNodes][i] ;
        for ( j = 0 ; j < InputNodes ; j++ ) {
          ChangeHiddenWeights[j][i] = LearningRate * Input[p][j] * HiddenDelta[i] + Momentum * ChangeHiddenWeights[j][i];
          HiddenWeights[j][i] += ChangeHiddenWeights[j][i] ;
        }
      }

      /******************************************************************
        Update Hidden-->Output Weights
      ******************************************************************/

      for ( i = 0 ; i < OutputNodes ; i ++ ) {
        ChangeOutputWeights[HiddenNodes][i] = LearningRate * OutputDelta[i] + Momentum * ChangeOutputWeights[HiddenNodes][i] ;
        OutputWeights[HiddenNodes][i] += ChangeOutputWeights[HiddenNodes][i] ;
        for ( j = 0 ; j < HiddenNodes ; j++ ) {
          ChangeOutputWeights[j][i] = LearningRate * Hidden[j] * OutputDelta[i] + Momentum * ChangeOutputWeights[j][i] ;
          OutputWeights[j][i] += ChangeOutputWeights[j][i] ;
        }
      }
    }

    /******************************************************************
      Every 1000 cycles send data to terminal for display
    ******************************************************************/
    ReportEvery1000 = ReportEvery1000 - 1;
    if (ReportEvery1000 == 0)
    {
#if !defined(C_PRINT)
      Serial.println();
      Serial.println();
      Serial.print ("TrainingCycle: ");
      Serial.print (TrainingCycle);
      Serial.print ("  Error = ");
      Serial.println (Error, 5);
#else
      printf("\n\nTrainingCycle: %ld  Error = %5.5f\n", TrainingCycle, Error);
#endif
      toTerminal();

      if (TrainingCycle == 1)
      {
        ReportEvery1000 = 999;
      }
      else
      {
        ReportEvery1000 = 1000;
      }
    }


    /******************************************************************
      If error rate is less than pre-determined threshold then end
    ******************************************************************/

    if ( Error < Success ) break ;
  }
#if !defined(C_PRINT)
  Serial.println ();
  Serial.println();
  Serial.print ("TrainingCycle: ");
  Serial.print (TrainingCycle);
  Serial.print ("  Error = ");
  Serial.println (Error, 5);
#else
  printf("\n\nTrainingCycle: %ld  Error = %5.5f\n", TrainingCycle, Error );
#endif


  toTerminal();

#if !defined(C_PRINT)
  Serial.println ();
  Serial.println ();
  Serial.println ("Training Set Solved! ");
  Serial.println ("--------");
  Serial.println ();
  Serial.println ();
  ReportEvery1000 = 1;
#else
  printf("\n\nTraining Set Solved! \n--------\n\n");
#endif

  writeToaFile();


  while (1);

}

void writeToaFile()
{
  FILE *fp;
  if ((fp = fopen("test.csv", "wb")) == NULL) {
    printf("Cannot open file.\n");
  }

// bias implementation is remaining

  fprintf(fp, "HiddenWeights:");
  for (i = 0; i < HiddenNodes+1; i++) {
	fprintf(fp,",");
	  }
	  fprintf(fp, "\r\n");
  
  for ( i = 0 ; i < HiddenNodes ; i++ ) {
    for ( j = 0 ; j < InputNodes+1 ; j++ ) {
      fprintf(fp, "%f,", HiddenWeights[j][i]);
    }
    fprintf(fp, "\r\n");
  }

  fprintf(fp, "OutputWeights:");
  for (i = 0; i < HiddenNodes+1; i++) {
	fprintf(fp,",");
	  }
	fprintf(fp, "\r\n");
  for ( i = 0 ; i < OutputNodes ; i++ ) {
    for ( j = 0 ; j < HiddenNodes+1 ; j++ ) {
      fprintf(fp, "%f,", OutputWeights[j][i]);
    }
    fprintf(fp, "\r\n");
  }
  fprintf(fp, "End");
  for (i = 0; i < HiddenNodes+1; i++) {
	fprintf(fp,",");
	  }
  fprintf(fp, "\r\n");

  fclose(fp);

  /* read the values */
  if ((fp = fopen("test.csv", "rb")) == NULL) {
    printf("Cannot open file.\n");
  }

  printf("HiddenWeights=\r\n{\r\n");
  
  for (i = 0; i < HiddenNodes; i++) {
    printf("{");
    for (j = 0; j < InputNodes+1; j++) {
      fscanf(fp, "%f", (&HiddenWeights[j][i]));
      
	    if (j + 1 == InputNodes+1)
        printf("%f", HiddenWeights[j][i]);
      else
        printf("%f,", HiddenWeights[j][i]);

    }
	if (i + 1 == HiddenNodes)
		printf("}\r\n}\r\n");
	else
		printf("},\r\n");

  }

  printf("OutputWeights=\r\n{\r\n");
  for (i = 0; i < OutputNodes; i++) {
    printf("{");
    for (j = 0; j < HiddenNodes+1; j++) {
      fscanf(fp, "%f,", (&OutputWeights[j][i]));

      if (j + 1 == HiddenNodes+1)
        printf("%f", OutputWeights[j][i]);
      else
        printf("%f,", OutputWeights[j][i]);


    }
	if (i + 1 == OutputNodes)
		printf("}\r\n}\r\n");
	else
		printf("},\r\n");

  }
  printf("End\r\n");
  
  toTerminal();

}

void toTerminal()
{

  for ( p = 0 ; p < PatternCount ; p++ ) {
#if !defined(C_PRINT)
    Serial.println();
    Serial.print ("  Training Pattern: ");
    Serial.println (p);
    Serial.print ("  Input ");
#else
    printf("\n  Training Pattern: %d  Input ", p);
#endif
    for ( i = 0 ; i < InputNodes ; i++ ) {
#if !defined(C_PRINT)
      Serial.print (Input[p][i], DEC);
      Serial.print (" ");
#else
      printf(" %2.3f ", Input[p][i]);
#endif
    }
#if !defined(C_PRINT)
    Serial.print ("  Target ");
#else
    printf("  Target ");
#endif
    for ( i = 0 ; i < OutputNodes ; i++ ) {
#if !defined(C_PRINT)
      Serial.print (Target[p][i], DEC);
      Serial.print (" ");
#else
      printf(" %2.3f ", Target[p][i]);
#endif
    }
    /******************************************************************
      Compute hidden layer activations
    ******************************************************************/

    for ( i = 0 ; i < HiddenNodes ; i++ ) {
      Accum = HiddenWeights[InputNodes][i] ;
      for ( j = 0 ; j < InputNodes ; j++ ) {
        Accum += Input[p][j] * HiddenWeights[j][i] ;
      }
      Hidden[i] = 1.0 / (1.0 + exp(-Accum)) ;
    }

    /******************************************************************
      Compute output layer activations and calculate errors
    ******************************************************************/

    for ( i = 0 ; i < OutputNodes ; i++ ) {
      Accum = OutputWeights[HiddenNodes][i] ;
      for ( j = 0 ; j < HiddenNodes ; j++ ) {
        Accum += Hidden[j] * OutputWeights[j][i] ;
      }
      Output[i] = 1.0 / (1.0 + exp(-Accum)) ;
    }
#if !defined(C_PRINT)
    Serial.print ("  Output ");
#else
    printf("  Output ");
#endif
    for ( i = 0 ; i < OutputNodes ; i++ ) {
#if !defined(C_PRINT)
      Serial.print (Output[i], 5);
      Serial.print (" ");
#else
      printf(" %5.5f ", Output[i]);
#endif
    }
  }


}

#if defined(C_PRINT)
int  main ()
{
  setup();
  while (1)
  {
    loop();
  }
  return 0;
}
#endif
