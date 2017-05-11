
// Credit : 
//////////////////////////////////////////////////////////////////
//  
//	TODO :
//		1. Document for function
//		2. <DONE> Generalize the constructor for data intake
//		3. Generalize the lib for Arduino too.
//		4. Check with float values between 0 and 1
//		5. Think of a use case i.e. an AGV, MAV
//			In -> /*UltraSonic, (<- might not be relevant)*/ 
//				IMU.Acc.(x1-x0,y1-y0,z1-z0), IMU.Gyr.(x1-x0,y1-y0,z1-z0), Encoder(X1-X1), Encoder(Y1-Y0)
//			Out-> PWMX, PWMY, Time or Vel, Angle, Time
//
//
//////////////////////////////////////////////////////////////////

#include "neuralnet1.h"

#if !defined(CHECK_FIXED_TRAINING)
#undef ACTIVATION_TEST_ONLY
#endif

#undef ACTIVATION_TEST_ONLY // Comment  for training to run // Separate function set can be called

#if defined(C_PRINT)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#endif


#include <math.h>


#if defined(C_PRINT)

static int random(int n)
{
    return (int)(rand() % n);
}
#endif

/*Neuralnet1::Neuralnet1(float ** Input_test, float ** Target_test
, int _PatternCount = 10
, int _InputNodes = 7, int _HiddenNodes = 8, int _OutputNodes = 4
, float _LearningRate = 0.3, float _Momentum = 0.9, float _InitialWeightMax = 0.5
, float _Success = 0.0004 )*/
Neuralnet1::Neuralnet1(float ** Input_test, float ** Target_test
, int _PatternCount
, int _InputNodes, int _HiddenNodes, int _OutputNodes
, float _LearningRate, float _Momentum, float _InitialWeightMax
, float _Success )
{
	PatternCount = _PatternCount ;//= 10;
	InputNodes = _InputNodes; //7;
	HiddenNodes = _HiddenNodes; //8;
	OutputNodes = _OutputNodes; //4;
	LearningRate = _LearningRate; //0.3;
	Momentum = _Momentum; //0.9;
	InitialWeightMax = _InitialWeightMax; //0.5;
	Success = _Success; //0.000004;
	
	// wild :P
	//float _ChangeHiddenWeights[InputNodes + 1][HiddenNodes];
	//ChangeHiddenWeights = (float**)_ChangeHiddenWeights;
	
	i = 0;
	j = 0;
	p = 0;
	q = 0;
	r = 0; 
	ReportEvery1000 = 0;
	TrainingCycle = 0;
	Rando = 0;
	Error = 0;
	Accum = 0;
	
	/*
	const float Input_test[PatternCount][InputNodes] = {
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
	
	const float Target_test[PatternCount][OutputNodes] = {
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
	*/
	
	if (( Input = ( float** )malloc( PatternCount*sizeof( float *))) == NULL )
	{  
		printf("ERROR: %d",__LINE__);
	}

	for ( i = 0; i < PatternCount; i++ )
	{ 
		if (( Input[i] = ( float *)malloc( sizeof( float ) * InputNodes )) == NULL )
		{  
			printf("ERROR: %d",__LINE__);
		}

		/* probably init the row here */
		 
		for ( j = 0 ; j < InputNodes ; j++ ) 
		{
			Input[i][j] = Input_test[i][j];
		}
	}
	
	
	if (( Target = ( float** )malloc( PatternCount*sizeof( float *))) == NULL )
	{  
		printf("ERROR: %d",__LINE__);
	}
	for ( i = 0; i < PatternCount; i++ )
	{ 
		if (( Target[i] = ( float *)malloc( sizeof( float ) * OutputNodes )) == NULL )
		{  
			printf("ERROR: %d",__LINE__);
		}

		/* probably init the row here */
		 
		for ( j = 0 ; j < OutputNodes ; j++ ) 
		{
			Target[i][j] = Target_test[i][j];
		}
	}
	
	if (( RandomizedIndex = ( int *)malloc( sizeof( int ) * PatternCount )) == NULL )
	{  
		printf("ERROR: %d",__LINE__);
	}
	  
	if (( Hidden = ( float *)malloc( sizeof( float ) * HiddenNodes )) == NULL )
	{  
		printf("ERROR: %d",__LINE__);
	}
	
	if (( Output = ( float *)malloc( sizeof( float ) * OutputNodes )) == NULL )
	{  
		printf("ERROR: %d",__LINE__);
	}
	
	//float HiddenWeights[InputNodes + 1][HiddenNodes];
	if (( HiddenWeights = ( float** )malloc( (InputNodes+1)*sizeof( float *))) == NULL )
	{  
		printf("ERROR: %d",__LINE__);
	}

	for ( i = 0; i < (InputNodes+1); i++ )
	{ 
		if (( HiddenWeights[i] = ( float *)malloc( sizeof( float ) * HiddenNodes )) == NULL )
		{  
			printf("ERROR: %d",__LINE__);
		}

		/* probably init the row here */
		 
		for ( j = 0 ; j < HiddenNodes ; j++ ) 
		{
			//Input[i][j] = Target_test[i][j];
		}
	}
	
	
	//float OutputWeights[HiddenNodes + 1][OutputNodes]; 
	if (( OutputWeights = ( float** )malloc( (HiddenNodes+1)*sizeof( float *))) == NULL )
	{  
		printf("ERROR: %d",__LINE__);
	}
	
	for ( i = 0; i < (HiddenNodes+1); i++ )
	{ 
		if (( OutputWeights[i] = ( float *)malloc( sizeof( float ) * OutputNodes )) == NULL )
		{  
			printf("ERROR: %d",__LINE__);
		}
		
		/* probably init the row here */
		 
		for ( j = 0 ; j < OutputNodes ; j++ ) 
		{
			//Input[i][j] = Target_test[i][j];
		}
	}
	
	if (( HiddenDelta = ( float *)malloc( sizeof( float ) * HiddenNodes )) == NULL )
	{  
		printf("ERROR: %d",__LINE__);
	}
	
	if (( OutputDelta = ( float *)malloc( sizeof( float ) * OutputNodes )) == NULL )
	{  
		printf("ERROR: %d",__LINE__);
	} 
	
	// float ChangeHiddenWeights[InputNodes + 1][HiddenNodes];
	
	if (( ChangeHiddenWeights = ( float** )malloc( (InputNodes+1)*sizeof( float *))) == NULL )
	{  
		printf("ERROR: %d",__LINE__);
	}
	
	for ( i = 0; i < (InputNodes+1); i++ ) // i <= InputNodes
	{ 
		if (( ChangeHiddenWeights[i] = ( float *)malloc( sizeof( float ) * HiddenNodes )) == NULL )
		{  
			printf("ERROR: %d",__LINE__);
		}
		 
		for ( j = 0 ; j < HiddenNodes ; j++ ) 
		{
			//Input[i][j] = Target_test[i][j];
			//printf(" [%d][%d] %f ",i,j,ChangeHiddenWeights[i][j]);
		}
		//printf("\r\n\r\n");
	}
	 
	//float ChangeOutputWeights[HiddenNodes + 1][OutputNodes];
	if (( ChangeOutputWeights = ( float** )malloc( (HiddenNodes+1)*sizeof( float *))) == NULL )
	{  
		printf("ERROR: %d",__LINE__);
	}
	
	for ( i = 0; i < (HiddenNodes+1); i++ )
	{ 
		if (( ChangeOutputWeights[i] = ( float *)malloc( sizeof( float ) * OutputNodes )) == NULL )
		{  
			printf("ERROR: %d",__LINE__);
		}

		/* probably init the row here */
		 
		for ( j = 0 ; j < OutputNodes ; j++ ) 
		{
			//Input[i][j] = Target_test[i][j];
		}
	}
 
}

Neuralnet1::~Neuralnet1()
{
	 // Free all
}

void Neuralnet1::initialize()
{
#if !defined(C_PRINT)
    Serial.begin(250000);
#else
    time_t t;
    srand((unsigned) time(&t));
#endif //C_PRINT


	/******************************************************************
      Initialize HiddenWeights and ChangeHiddenWeights
    ******************************************************************/

    for ( i = 0 ; i < HiddenNodes ; i++ ) {
        for ( j = 0 ; j <= InputNodes ; j++ ) {
            ChangeHiddenWeights[j][i] = 0.0;

            //float rr = float(random(100));
            // #if !defined(C_PRINT)
            //       //Serial.println("Initial/Untrained Outputs: ");
            // #else
            //       printf("\nRrrR %f", rr);
            // #endif
            Rando = float(random(100)) / 100.0;

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
}

void Neuralnet1::train()
{
	
	ReportEvery1000 = 1;
    for ( p = 0 ; p < PatternCount ; p++ ) {
        RandomizedIndex[p] = p ;
    }
	/******************************************************************
      Begin training
    ******************************************************************/

    for ( TrainingCycle = 1 ; TrainingCycle <  2147483647 ; TrainingCycle++) {

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
            Serial.println (Error, 14);
#else
            printf("\n\nTrainingCycle: %ld  Error = %2.9f\n", TrainingCycle, Error);
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
    printf("\n\nTrainingCycle: %ld  Error = %2.9f\n", TrainingCycle, Error );
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
}

void Neuralnet1::activate(float inarray[], int inlen, float outarray[], int outlen)
{
	int i = 0;
	    /******************************************************************
          Compute hidden layer activations
        ******************************************************************/

        for ( i = 0 ; i < HiddenNodes ; i++ ) {
            Accum = HiddenWeights[InputNodes][i] ;
            for ( j = 0 ; j < InputNodes ; j++ ) {
                Accum += inarray[j] * HiddenWeights[j][i] ;
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
            outarray[i] = 1.0 / (1.0 + exp(-Accum)) ;
        }
		/*
		for ( i = 0 ; i < OutputNodes ; i++ ) {
#if !defined(C_PRINT)
			Serial.print (outarray[i], 5);
            Serial.print (" ");
#else
            printf(" %5.5f ", outarray[i]);
#endif
        }
		 */
		printf("\r\n\r\n");
		
}


void Neuralnet1::toTerminal()
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
#if !defined(C_PRINT)
#else
//printf("\r\nYou can close it now. ");
    printf("\r\n");
#endif
}

void Neuralnet1::saveWeights(char *fileName)
{
	writeToaFile(fileName);
}

void Neuralnet1::loadWeights(char *fileName)
{
	loadWeightsFromFile(fileName);
}	
	
void Neuralnet1::loadWeightsFromFile(char *fileName)
{
    FILE *fp;
    char temp[128] = {0};
    /* read the values */ //"test.csv"
    if ((fp = fopen(fileName, "rb")) == NULL) {
        printf("Cannot open file.\n");
    }


    fscanf(fp, "%s\r\n", temp);
    printf("HiddenWeights(%s)=\r\n{\r\n",temp);

    for (i = 0; i < HiddenNodes; i++) {
        printf("{");
        for (j = 0; j < InputNodes+1; j++) {


            if (j + 1 == InputNodes+1)
                fscanf(fp, "%f,,\r\n", (&HiddenWeights[j][i]));
            else
                fscanf(fp, "%f,", (&HiddenWeights[j][i]));

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

    fscanf(fp, "%s\r\n", temp);
    printf("OutputWeights(%s)=\r\n{\r\n",temp);

    for (i = 0; i < OutputNodes; i++) {
        printf("{");
        for (j = 0; j < HiddenNodes+1; j++) {
			

            if (j + 1 == HiddenNodes+1)
                fscanf(fp, "%f,\r\n", (&OutputWeights[j][i]));
            else
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

    fclose(fp);

    printf("End\r\n");

    toTerminal();

    printf("\r\n");
}

void Neuralnet1::writeToaFile(char *fileName)
{
    FILE *fp;
    if ((fp = fopen("test.csv", "wb")) == NULL) {
        printf("Cannot open file.\n");
    }

    fprintf(fp, "HiddenWeights:");
    for (i = 0; i < HiddenNodes+1; i++) {
        fprintf(fp,",");
    }
    fprintf(fp, "\r\n");

    for ( i = 0 ; i < HiddenNodes ; i++ ) {
        for ( j = 0 ; j < InputNodes+1 ; j++ ) {
            fprintf(fp, "%f,", HiddenWeights[j][i]);
        }
        fprintf(fp, ",\r\n");
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


    printf("End\r\n");

    toTerminal();
#if !defined(C_PRINT)
#else
    printf("\r\nYou can close it now. ");
    printf("\r\n");
#endif

    return;
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
#if !defined(C_PRINT)
#else
    printf("\r\nYou can close it now. ");
    printf("\r\n");
#endif

}
