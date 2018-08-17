

#include "PossibleObstacle.h"
#include <time.h>
#include<stdlib.h>
#include <iostream>
////////////////////////////////////////////////////////////////////////
// Name:       PossibleObstacle::defineObstacle()
// Purpose:    Implementation of PossibleObstacle::defineObstacle()
// Return:     int
////////////////////////////////////////////////////////////////////////
PossibleObstacle::PossibleObstacle()
{
	//std::cout <<"PossibleObstacle created\n";
	defineObstacle();	
}

PossibleObstacle::~PossibleObstacle()
{
		//std::cout << "PossibleObstacle destroyed \n";
}

void PossibleObstacle::defineObstacle(void)		//TODO: define number of obstacle types  
{	
	srand((unsigned) time (NULL));
		obstacleType=rand()%7+1; 
}

////////////////////////////////////////////////////////////////////////
// Name:       PossibleObstacle::getObstacleType()
// Purpose:    Implementation of PossibleObstacle::getObstacleType()
// Return:     int
////////////////////////////////////////////////////////////////////////

int PossibleObstacle::getObstacleType(void) const
{
   return obstacleType;
}
