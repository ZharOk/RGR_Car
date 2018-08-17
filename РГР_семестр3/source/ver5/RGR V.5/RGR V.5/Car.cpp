
#include "Car.h"
#include <time.h>
#include<stdlib.h>
////////////////////////////////////////////////////////////////////////
// Name:       Car::getGasolineStatus()
// Purpose:    Implementation of Car::getGasolineStatus()
// Return:     int
////////////////////////////////////////////////////////////////////////
Car::Car(int n)	// if n==1 enter values; if n==2 generate randomly
{
int tires;
///////////////////////////////////////////////////////////////////////////////////////////
if(n==1)
{
	do
	{
	cout << "Enter current Gasoline Status of the car(from 0 to "<< maxGasoline <<"): ";
	cin >> GasolineStatus;
	cout << endl << endl;
	}
	while(GasolineStatus<0 || GasolineStatus > maxGasoline);

	
//====================================================================================
	do{
		cout << "Enter current Status of the car(from 1 - can't move to 10 - best Status): ";
		cin >> carStatus;
		cout << endl << endl;}
	while(carStatus<0 || carStatus>10);
	
//====================================================================================
	do{
	cout << "Enter Gasoline consumtion of the car per 100 km (>0): ";
	cin >> 	GasolineConsumption;
	cout << endl << endl;}
	while(GasolineConsumption<=0);
//====================================================================================
	do{
	cout << "Enter current type of tires(1 - Winter Tiers, 2 - Summer Tiers): ";
	cin >> tires;
	cout << endl << endl;}
	while(tires < 1 || tires > 2);

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
	/*cout << "Car was created" << endl;*/
}

Car::~Car()
{
	/*cout << "Car was destroyed" << endl;*/
}

int Car::getGasolineStatus(void) const
{
	return GasolineStatus;
   // TODO : implement
}


////////////////////////////////////////////////////////////////////////
// Name:       Car::setGasolineStatus()
// Purpose:    Implementation of Car::setGasolineStatus()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Car::setGasolineStatus(int GasolineAmount)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Car::getCarStatus()
// Purpose:    Implementation of Car::getCarStatus()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Car::getCarStatus(void) const
{
	return carStatus;
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Car::setCarStatus()
// Purpose:    Implementation of Car::setCarStatus()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Car::setCarStatus(int Status)
{
   carStatus=Status;

}

////////////////////////////////////////////////////////////////////////
// Name:       Car::isSummerTiers()
// Purpose:    Implementation of Car::isSummerTiers()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Car::isSummerTiers(void)
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

int Car::chooseGasolineNeed(void)
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

void Car::changeGasolineStatus(int GasolineAmount, int key)
{
	if(key==1)
		GasolineStatus+=GasolineAmount;
	if(key==2)
		GasolineStatus+=GasolineAmount;
}
int Car::canMove()
{
	if(carStatus<=3)
		return 2;
	if(GasolineStatus<=0)
		return 1;
}
int Car::getRepairCost()
{
	srand((unsigned) time(NULL) );
	repairCost=rand()%50+50;
	repairLevel=10-carStatus;
	return repairCost*repairLevel;
}
int Car::getGasCost()
{
	srand((unsigned) time(NULL) );
	gasCost=rand()%9+5;
	return gasCost;
}
int Car::getMaxSpeed() const
{
	return maxSpeed;
}
int Car::consumpedGasoline(int SomeDist)
{
	return SomeDist*GasolineConsumption;
}

bool Car::operator==(const Car& car) const // Operator overloading of "=="
{
	if(this->getCarStatus()==car.carStatus && this->getGasolineStatus()==car.GasolineStatus)
		return true;
	else
		return false;
}

Car& Car::operator++() // Operator overloading of "++"
{
	++carStatus;
	return *this;
}
Car& Car::operator--() // Operator overloading of "--"
{
	--carStatus;
	return *this;
}
Car& Car::operator+=(const Car& car) // Operator overloading of "+="
{
	if(*this==car)
		++(this->GasolineStatus);
	return *this;
}