#include "Tour.h"
#include "Planer.h"
#include "Roads.h"
#include "Timer.h"
#include "Car.h"
#include <time.h>
#include<stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include "PossibleObstacle.h"
using namespace std;

#define ESC 27
bool ekzit = false;
char ekzitch;
////////////////////////////////////////////////////////////////////////
// Name:       Planer::start()
// Purpose:    Implementation of Planer::start()
// Return:     void
////////////////////////////////////////////////////////////////////////
Planer::Planer(Roads* someRoad, Timer* someTimer): Tour()
{
	roads=someRoad;
	timer=someTimer;

	/*cout << "Planer was created" << endl;*/	
}

Planer::~Planer()
{
	/*cout << "Planer was destroyed" << endl;*/
}

void Planer::start(void)
{
 cout << "\n\nPlaner starts now.\n\n";
}

inline void Planer::chekCarStatus()
{
	if(roads->car->canMove()==2)				// 2-car problem
	{
		cout << "Breaking. Car can't move.\n\n";
		cout<< "You payed " << roads->car->getRepairCost() << " for repair\nCar is repaired.\n\n";
		roads->car->setCarStatus(10);
		Sleep(2000);
	}	
	if(roads->car->canMove()==1)			//1-Gasoline problem 
	{
		cout << "The fuel tank is empty. Car can't move.\n\n";
		int Gasoline;
		Gasoline=roads->car->chooseGasolineNeed();		// returns amount of chosen Gasoline
		roads->car->changeGasolineStatus(Gasoline, 2);
		cout << "You payed " << Gasoline*roads->car->getGasCost() << " for Gasoline.\n\n";	//shows money payed for that
		Sleep(2000);
	}
}

void YesOrNo()
{
cout<<"\nStop tour and exit?\ny/n? : ";
cin>>ekzitch;
	switch(ekzitch)
	{
		case 'y' : ekzit=true;break;
		case 'n' : ekzit=false;break;
	}
}

void Planer::mainPlaner()
{	
	do
		{
				chekCarStatus();

				if(Tour.getCurrSpeed()==0)
				{
					cout << "Car at a standstill, enter the speed you want to move with."<< endl;
					cout << "Speed limit here is " << roads->getSpeedLimit() << 
						" km/h\nMaximum car speed is "<< roads->car->getMaxSpeed() <<" km/h." << endl;
					Tour.changeSpeed(roads->car->getMaxSpeed()); //argument in func is for measurement of max speed
					system("cls");
				}
			cout << "=========================================\n";
			cout << "|Your current speed is " << Tour.getCurrSpeed() <<" km/h.\t\t|" << endl;
			cout << "|For now you have moved " << Tour.getTourLength()<< " kilometers.\t|\n";
			cout << "|Your Gasoline Status is " << roads->car->getGasolineStatus() << " litters.\t|\n";
			cout << "|You spent " << Tour.TourTime() << " minutes.\t\t|\n";
			cout << "=========================================\n\n";
			 PossibleObstacle PossibleObstacle;
				switch(PossibleObstacle.getObstacleType())
				{
					srand((unsigned) time(NULL));

				case 1: {	// if speed limit changes 
							roads->changeSpeedLimit();
							cout << "Speed limit changes. It is now " << roads->getSpeedLimit() << endl;
								Sleep(2000);
								if(roads->getSpeedLimit()<Tour.getCurrSpeed())
								{
									cout << "You are moving faster than speed limit.\nChange your speed.\n";
									Tour.changeSpeed(roads->car->getMaxSpeed());
									//system("cls");
									cout << "Your current speed is " << Tour.getCurrSpeed() << endl;
								}

						} break;
					
				case 2: {
							cout << "You are moving towards an obstacle.\n";
								if (Tour.getCurrSpeed()>100)
								{
									cout << "You are moving too fast to avoid crash.\n";
									Sleep(3000);
									cout << "You crashed.\n";
									roads->car->setCarStatus(roads->car->getCarStatus()-(rand()%5+4));
									chekCarStatus();
									int temp=(rand()%7+3)*10;
									cout << "You spent " << temp << " minutes to repair your car.\n\n";
									Tour.setTourTime(temp);
									cout << "\n*************************************************" << endl;
									YesOrNo();
								}
								else
								{
									cout << "Your speed is low enough to avoid crash.\nYou avoided crash.\n\n";
								}
						}break;
						case 3:{
									cout << "Traffic level is too high, you can't move fast.\n";
									Sleep(2000);
									setSpeed((rand()%3+1)*5, Tour);
									cout << "Moving now with " << Tour.getCurrSpeed() << " km/h\n";
									float temp=rand()%90+30;
									cout << "You spent "<< temp << " minutes in traffic jam\n";
									Tour.incrTourLength(Tour.getCurrSpeed()*(temp/60));
									Tour.setTourTime(temp);
									roads->car->changeGasolineStatus(roads->car->consumpedGasoline(Tour.getCurrSpeed()*(temp/60)) , 1);
									cout << "\nFrom now you can move freely with any speed.\n";
									cout << "Speed limit here is " << roads->getSpeedLimit() << 
										" km/h\nMaximum car speed is "<< roads->car->getMaxSpeed() <<" km/h." << endl;
									Tour.changeSpeed(roads->car->getMaxSpeed()); //argument in func is for measurement of max speed
							   }
							break;
				}

				
				if(roads->crash(roads->defineCrashLevel(Tour.getCurrSpeed())))
				{
					roads->car->setCarStatus(roads->car->getCarStatus()-(rand()%5+4));
					chekCarStatus();
					int temp=(rand()%7+3)*10;
					cout << "You spent " << temp << " minutes to repair your car.\n\n";
					Tour.setTourTime(temp);
					cout << "\n*************************************************" << endl;
					YesOrNo();
				}
				roads->car->changeGasolineStatus(roads->car->consumpedGasoline(1) ,1);
				Tour.incrTourLength(1);
				
				if (kbhit() && getch() == ESC)
					break;
			system("pause");
			system("cls");	
		} while (ekzit == false);
}
////////////////////////////////////////////////////////////////////////
// Name:       Planer::finish()
// Purpose:    Implementation of Planer::finish()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Planer::finish(void)
{
   cout << "\n*************************************************" << endl;
	cout << "End of Planer. Thank you for watching."<<endl;
	cout << "\n*************************************************" << endl;
}