#ifndef TRANSHELP
#define TRANSHELP

#include <iostream>
using namespace std;

///@brief Class Trailer.
class Trailer;

///@brief Class TransHelp.
class TransHelp
{
	public:
    ///@brief Constructor of TransHelp.
	TransHelp(int n);
	///@brief Contructor of copy TransHelp.
	TransHelp(TransHelp& TransHelpCopy);
	///@brief Distructor of TransHelp.
	~TransHelp();
	///@brief Get Gasoline Status.
	int getGasolineStatus(void) const;
	///@brief Set Gasoline station.
	void setGasolineStatus(int GasolineAmount);
	///@brief Change Gasoline Station.
	void changeGasolineStatus(int GasolineAmount, int key);
	///@brief Get Car Status.
	int getCarStatus(void) const;
	///@brief Get Car Status.
	void setCarStatus(int Status);
	///@brief Set sumer tires on the TransHelp
	bool isSummerTiers(void);
	///@brief Choose Gasoline need.
	int chooseGasolineNeed(void);
	///@brief Get gas prise
	int getGasCost(void);
	///@brief Get repair Cost.
	int getRepairCost();
	///@brief Metod return can car move or no.
	int canMove();
	///@brief Get max speed.
	int getMaxSpeed() const;
	///@brief Consumped Gasoline.
	int consumpedGasoline(int SomeDist);
   
protected:
	int maxSpeed;
	int maxGasoline;
private:
	int GasolineStatus;
	int carStatus;
	bool areSummerTiers;
	int GasolineConsumption;
	int GasolineNeed;
	int repairCost;
	int repairLevel;
	int gasCost;


};


#endif