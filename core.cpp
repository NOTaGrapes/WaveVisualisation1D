//core.cpp
//
// writed by NOTaGrape. 

#include"core.h"
#include <string.h>
#include <math.h>

core::core()// empty constructor, values seth for ziro
{
	a_=0;
	stepCord_=0;
	stepTime_=0;
	lambda_=0;
	for (int i=0;i!=201;i++)
	{
		layerUpper_[i]=0;
		layerMiddle_[i]=0;
		layerLower_[i]=0;
		alfa_[i]=0;
		beta_[i]=0;
		A_[i]=0;
		B_[i]=0;
		C_[i]=0;
	}
	iterationClock_=0;
}
void core::makeReset()//values seth for ziro
{
	a_=0;
	stepCord_=0;
	stepTime_=0;
	lambda_=0;
	for (int i=0;i!=201;i++)
	{
		layerUpper_[i]=0;
		layerMiddle_[i]=0;
		layerLower_[i]=0;
		alfa_[i]=0;
		beta_[i]=0;
		A_[i]=0;
		B_[i]=0;
		C_[i]=0;
	}
	iterationClock_=0;
}
core::~core()
{
	//nothing )))
}
void core::setValue(double Double,char* charName)//  charName shows name of value to change for 
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//       variety of charName for input:
	//
	//     u1 - setup value for layerLower_[0]
	//	   u2 - setup value for layerLower_[200]
	//      a - setup value for a_
	//     dx - setup value for stepCord_
	//     dt - setup value for stepTime_
	//
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (stricmp(charName,"u1")==0)
	{
		layerLower_[0]=Double;
		layerMiddle_[0]=Double;
	}
	if (stricmp(charName,"u2")==0)
	{
		layerLower_[200]=Double;
		layerMiddle_[200]=Double;
	}
	if (stricmp(charName,"a")==0)
	{
		a_=Double;

	}
	if (stricmp(charName,"dx")==0)
	{
		stepCord_=Double;

	}
	if(stricmp(charName,"dt")==0)
	{
		stepTime_=Double;

	}
}
void core::computeLambda(char* charName)//calculation of lambda
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//       variety of charName for input:
	//
	//   expl - setup lambda_ value for Explicit method
	//	 impl - setup lambda_ value for Implicit method
	//  cross - setup lambda_ value for Cross method
	//
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	if(stricmp(charName,"impl")==0)
	{
		lambda_=(pow(a_,2)*pow(stepTime_,2))/pow(stepCord_,2);
	}
	if(stricmp(charName,"cross")==0 || stricmp(charName,"expl")==0 )
	{
		lambda_=(pow(a_,2)*pow(stepTime_,2))/pow(stepCord_,2);
	}
}
void core::computeAndMoveLayer(char* charName)
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//       variety of charName for input:
	//
	//   expl - setup lambda_ value for Explicit method
	//   impl - setup lambda_ value for Implicit method
	//  cross - setup lambda_ value for Cross method
	//
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	if(stricmp(charName,"expl")==0) //explicit method
	{
		//compute
		layerUpper_[0]=layerLower_[0];
		for(int i=1;i!=200;i++)
		{
			layerUpper_[i]=2*(1-lambda_)*layerMiddle_[i]+lambda_*(layerMiddle_[i+1]+layerMiddle_[i-1])-layerLower_[i];;
		}
		layerUpper_[200]=layerLower_[200];
		//click
		iterationClock_++;
		//move 
		for(int i=0;i!=201;i++)
		{
			layerLower_[i]=layerMiddle_[i];
			layerMiddle_[i]=layerUpper_[i];
			layerUpper_[i]=0;
		}
	}
	if(stricmp(charName,"impl")==0) //implicit method
	{ 
		//compute
		layerHelper_[0]=layerLower_[0];
		for (int i=1;i!=200;i++)
		{
			layerHelper_[i]=(1+2*lambda_)*layerLower_[i]-lambda_*(layerLower_[i-1]+layerLower_[i+1])-2*layerMiddle_[i];
		}
		layerHelper_[200]=layerLower_[200];

		A_[0]=0;
		B_[0]=0;
		C_[0]=1;
		for (int i=1;i!=200;i++)
		{
			A_[i]=lambda_;
			B_[i]=lambda_;
			C_[i]=-(1+2*lambda_);
		}
		A_[200]=0;
		B_[200]=0;
		C_[200]=1;
		//compute (Alfa & Beta)
		alfa_[1]=0;
		beta_[1]=layerLower_[0];
		for (int i=2;i!=201;i++)
		{
			alfa_[i]=(-B_[i-1])/(C_[i-1]+A_[i-1]*alfa_[i-1]);
			beta_[i]=(layerHelper_[i-1]-A_[i-1]*beta_[i-1])/(C_[i-1]+A_[i-1]*alfa_[i-1]);
		}
		//compute(layers)
		layerUpper_[200]=(layerHelper_[200]-A_[200]*beta_[200])/(C_[200]+A_[200]*alfa_[200]);
		for (int i=199;i>=0;i--)
		{
			layerUpper_[i]=layerUpper_[i+1]*alfa_[i+1]+beta_[i+1];
		}
		//click
		iterationClock_++;
		//mov
		for (int i=0;i!=201;i++)
		{
			layerLower_[i]=layerMiddle_[i];
			layerMiddle_[i]=layerUpper_[i];
			layerUpper_[i]=0;
		}
	}
	if(stricmp(charName,"cross")==0)
	{
		//compute (middle layer by explicit method)
		if (iterationClock_==0)
		{
			computeLambda("expl");
			layerMiddle_[0]=layerLower_[0];
			layerUpper_[0]=layerLower_[0];
			for(int i=1;i!=200;i++)
			{

				layerMiddle_[i]=layerLower_[i]+(lambda_)*(layerLower_[i-1]+layerLower_[i+1]-2*layerLower_[i]);
				layerUpper_[i]=layerMiddle_[i];
			}
			layerMiddle_[200]=layerLower_[200];
			layerUpper_[200]=layerLower_[200];
			computeLambda("cross");
		}
		//compute (upper layer by cross method)
		else
		{
			layerUpper_[0]=layerMiddle_[0];
			for(int i=1;i!=200;i++)
			{
				layerUpper_[i]=(layerMiddle_[i-1]*lambda_+layerLower_[i]*(1-lambda_)+layerMiddle_[i+1]*lambda_)/(1+lambda_);
			}
			layerUpper_[200]=layerMiddle_[200];
		}
		//click
		iterationClock_++;
		//move
		for(int i=0;i!=201;i++)
		{
			layerLower_[i]=layerMiddle_[i];
			layerMiddle_[i]=layerUpper_[i];
			layerUpper_[i]=0;
		}
	}
}
double core::showValue(char* charName)
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//       variety of charName for input:
	//
	//     u1 - show value for layerLower_[0]
	//	   u2 - show value for layerLower_[200]
	//      a - show value for a_
	//     dx - show value for stepCord_
	//     dt - show value for stepTime_
	// lambda - show value for lambda_
	//  clock - show value for iterationClock_
	//
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (stricmp(charName,"u1")==0)
	{
		return layerLower_[0];
	}
	if (stricmp(charName,"u2")==0)
	{
		return layerLower_[200];
	}
	if (stricmp(charName,"a")==0)
	{
		return a_;

	}
	if (stricmp(charName,"dx")==0)
	{
		return stepCord_;

	}
	if(stricmp(charName,"dt")==0)
	{
		return stepTime_;

	}
	if(stricmp(charName,"lambda")==0)
	{
		return lambda_;
	}
	if(stricmp(charName,"clock")==0)
	{
		return iterationClock_;

	}
	return 0;
}
void core::computeBasicWave()
{
	for (int i=70;i!=131;i++)
	{
		layerLower_[i]=exp(-stepCord_*stepCord_*(i-100)*(i-100));
		layerMiddle_[i]=layerLower_[i];
	}
}


