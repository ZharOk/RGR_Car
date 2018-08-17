

#include "Roads.h"
#include "Timer.h"
#include "Tour.h"
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       Tour::TourTime()
// Purpose:    Implementation of Tour::TourTime()
// Return:     int
////////////////////////////////////////////////////////////////////////
Tour::Tour()
{
	currSpeed=0;
	TourLength=0;
	timeSpent=0;
	/*cout << "Tour was created" << endl;*/
}

Tour::~Tour()
{
	
	/*cout << "Tour was destroyed" << endl;	*/
}

float Tour::TourTime()
{
	timeSpent+=60/currSpeed;
	return timeSpent;
}

void Tour::setTourTime(int someTime)
{
	timeSpent+=someTime;
}
float Tour::getCurrSpeed(void) const
{
	return currSpeed;
}

float TourTime(Tour& Tour)
{
	Tour.timeSpent+=60/Tour.currSpeed;
	return Tour.timeSpent;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tour::changeSpeed()
// Purpose:    Implementation of Tour::changeSpeed()
// Return:     int
////////////////////////////////////////////////////////////////////////
void Tour::incrTourLength(int length)
{
	TourLength+=length;
}

int Tour::getTourLength() const
{
	return TourLength;
}

void Tour::setSpeed(int speed)
{
		currSpeed=speed;
}


void Tour::changeSpeed(int maxSpeed)
{
	int speed;
	do 
	{
		cout << "Enter speed you want to move with: ";
		cin >> speed;
	} while (speed<=0 || speed>maxSpeed);

	currSpeed=speed;
	
}

void setSpeed(int speed, Tour &Tour)
{
	Tour.currSpeed=speed;
}