#include <iostream>
using namespace std;
#include "Car.h"
#include "PossibleObstacle.h"
#include "Roads.h"
#include "Tour.h"
#include "Planer.h"
#include "Timer.h"

int main(int argc, char** argv) 
{
	{
	
		cout << "*************************************************" << endl;
		cout << "\"Car\" project, v.5.0" << endl << endl;
		cout << "Author:" << endl;
		cout << "Dmytro Bevz, student of group IS-41" << endl;
		cout << "FICT | ASOIU | NTUU \"KPI\"" << endl << endl;
		cout << "Contacts:" << endl;
		cout << "mail: dominusfortuna@gmail.com" << endl;
		cout << "tel: (063)27-94-073" << endl;
		cout << "*************************************************" << endl;



	Roads someRoad;
	Timer someTimer;
	Planer Planer(&someRoad, &someTimer);

	Planer.start();
	Planer.mainPlaner();
	Planer.finish();
	}
	system ("pause");
	return 0;
}
