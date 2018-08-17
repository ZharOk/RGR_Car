

#include "Car.h"
#include "Roads.h"
#include<time.h>
#include<stdlib.h>
////////////////////////////////////////////////////////////////////////
// Name:       Roads::crash()
// Purpose:    Implementation of Roads::crash()
// Return:     bool
////////////////////////////////////////////////////////////////////////

/*   int speedLimit;
   bool isWinter;
   int roadStatus;
   int traffic;
   int crashLevel;*/
   
Roads::Roads()
{
	int n;
	cout << "If you want to enter car values manually, press 1,\n if you want to generate them randomly, press 2.\n";
	cin >> n;
	car=new Car(n);

	srand((unsigned) time (NULL));
	speedLimit=(rand()%11+5)*10;
	roadStatus=rand()%10+1;
//===========================================================================	
	int tires;
	do{
	cout << "Enter current season(1 - Winter, 2 - Other season): ";
	cin >> tires;
	cout << endl << endl;
	}while(tires < 1 || tires > 2);

	if(tires==1)
		isWinter=true;
	else	
		isWinter=false;
//===========================================================================	
		
	/*cout << "Road was created" << endl;*/
	
}

Roads::~Roads()
{
	//delete []car;
	/*cout << "Road was destroyed" << endl;*/
}
   
bool Roads::crash(int level)
{
	srand((unsigned) time (NULL));
	bool flag=true;
	if(level<=2 && rand()%100<5 && flag)
	{
		flag=false;
		cout << "Crash because of road Status, weather conditions and moving speed.\n";
	}
	else
		if(level<=5 && rand()%100<10 && flag)
		{
			flag=false;
			cout << "Crash because of road Status, weather conditions and moving speed.\n";

		}
	else
		if(level<=10 && rand()%100<20 && flag)
		{
			flag=false;
			cout << "Crash because of road Status, weather conditions and moving speed.\n";

		}

	if(flag)
		return false;
	else
		return true;

}

int Roads::getSpeedLimit() const
{
	return speedLimit;
}
////////////////////////////////////////////////////////////////////////
// Name:       Roads::setCrashLevel()
// Purpose:    Implementation of Roads::setCrashLevel()
// Return:     void
////////////////////////////////////////////////////////////////////////

int Roads::defineCrashLevel(int currSpeed)
{
	int level=0;	//level the possibility of crash (0 - you can't get into crash, 10 - definitely get into crash)

	if(isWinter==true && car->isSummerTiers()==true)	//if it's winter and car without winter tiers
		level+=4;
	if(currSpeed>speedLimit)		//if car moves faster speed limit
		level+=4;
	if(roadStatus<4)				//if road Status is bad
		level+=2;

	return level;

}

////////////////////////////////////////////////////////////////////////
// Name:       Roads::changeSpeed()
// Purpose:    Implementation of Roads::changeSpeed()
// Return:     int
////////////////////////////////////////////////////////////////////////

void Roads::changeSpeedLimit(void)
{
	srand((unsigned) time (NULL));
	speedLimit=(rand()%11+4)*10;
}
