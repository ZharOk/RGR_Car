
#include "TransHelp.h"
#include <time.h>
#include<stdlib.h>

TransHelp::TransHelp(int n)	// if n==1 enter values; if n==2 generate randomly
{
	int tires;
	///////////////////////////////////////////////////////////////////////////////////////////
	if(n==1)
	{

		do{

			cout << "Enter current Gasoline Status of the car(from 0 to "<< maxGasoline <<"): ";
			cin >> GasolineStatus;
			cout << endl << endl;
		}while(GasolineStatus<0 || GasolineStatus > maxGasoline);
		//====================================================================================
		do{
			cout << "Enter current Status of the car(from 1 - can't move to 10 - best Status): ";
			cin >> carStatus;
			cout << endl << endl;
		}while(carStatus<0 || carStatus>10);
		//====================================================================================
		do{
			cout << "Enter Gasoline consumt of the car per 100 km (>0): ";
			cin >> 	GasolineConsumption;
			cout << endl << endl;
		}while(GasolineConsumption<=0);
		//====================================================================================
		do{
			cout << "Enter current type of tires(1 - Winter Tiers, 2 - Summer Tiers): ";
			cin >> tires;
			cout << endl << endl;
		}while(tires < 1 || tires > 2);
		//==========================================================================
		if(tires==1)
			areSummerTiers=false;
		else	
			areSummerTiers=true;
	}
	///////////////////////////////////////////////////////////////////////////////////////////	
	if(n==2)
	{
		srand((unsigned) time(NULL));

		GasolineStatus=rand()%(maxGasoline+1);
		carStatus=rand()%10+1;
		GasolineConsumption=rand()%10;
		areSummerTiers=rand()%2;

	}	
	//maxGasoline=80;
	//maxSpeed=200;

	/*cout << "Car was created" << endl;*/
}

TransHelp::~TransHelp()
{
	/*cout << "Car was destroyed" << endl;*/
}

int TransHelp::getGasolineStatus(void) const
{
	return GasolineStatus;
	// TODO : implement
}


////////////////////////////////////////////////////////////////////////
// Name:       Car::setGasolineStatus()
// Purpose:    Implementation of Car::setGasolineStatus()
// Return:     void
////////////////////////////////////////////////////////////////////////

void TransHelp::setGasolineStatus(int GasolineAmount)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Car::getCarStatus()
// Purpose:    Implementation of Car::getCarStatus()
// Return:     int
////////////////////////////////////////////////////////////////////////

int TransHelp::getCarStatus(void) const
{
	return carStatus;
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Car::setCarStatus()
// Purpose:    Implementation of Car::setCarStatus()
// Return:     void
////////////////////////////////////////////////////////////////////////

void TransHelp::setCarStatus(int Status)
{
	carStatus=Status;

}

////////////////////////////////////////////////////////////////////////
// Name:       Car::isSummerTiers()
// Purpose:    Implementation of Car::isSummerTiers()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool TransHelp::isSummerTiers(void)
{
	if (areSummerTiers==1)
		return true;
	else 
		return false;
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Car::chooseGasolineNeed()
// Purpose:    Implementation of Car::chooseGasolineNeed()
// Return:     int
////////////////////////////////////////////////////////////////////////

int TransHelp::chooseGasolineNeed(void)
{	
	do
	{
		cout << "Enter amount of Gasoline needed(>0 and <"<< maxGasoline <<"): ";
		cin >> GasolineNeed;
		cout << endl << endl;
	}
	while(GasolineNeed<=0 || GasolineNeed>maxGasoline);

	return GasolineNeed;

	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Car::getGasCost()
// Purpose:    Implementation of Car::getGasCost()
// Return:     int
////////////////////////////////////////////////////////////////////////

void TransHelp::changeGasolineStatus(int GasolineAmount, int key)
{
	if(key==1)
		GasolineStatus+=GasolineAmount;
	if(key==2)
		GasolineStatus+=GasolineAmount;
}
int TransHelp::canMove()
{
	if(carStatus<=3)
		return 2;
	if(GasolineStatus<=0)
		return 1;
}
int TransHelp::getRepairCost()
{
	srand((unsigned) time(NULL) );
	repairCost=rand()%50+50;
	repairLevel=10-carStatus;
	return repairCost*repairLevel;
}
int TransHelp::getGasCost()
{
	srand((unsigned) time(NULL) );
	gasCost=rand()%9+5;
	return gasCost;
}
int TransHelp::getMaxSpeed() const
{
	return maxSpeed;
}
int TransHelp::consumpedGasoline(int SomeDist)
{
	return SomeDist*GasolineConsumption;
}

