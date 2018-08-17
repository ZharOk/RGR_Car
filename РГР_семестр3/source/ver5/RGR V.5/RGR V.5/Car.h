

#if !defined(__UMLClassDiagram_1_Car_h)
#define __UMLClassDiagram_1_Car_h
#include <iostream>
using namespace std;
///@brief class Car
class Car
{
public:
	///@brief Constructor of CAR
	Car(int n);
	//Car(int petrSt, int carSt, int petrCons, bool tires);
	///@brief Copy constructor of Car
	Car(Car& CarCopy);
	///@brief Destructor of Car
	~Car();
	///@brief Return Gasoline Status
	int getGasolineStatus(void) const;
	///@brief Change Gasoline Status
   void setGasolineStatus(int GasolineAmount);
   ///@brief Change Gasoline Status @return nothing
   void changeGasolineStatus(int GasolineAmount, int key);
   ///@brief Return Car Status 
   int getCarStatus(void) const;
   ///@brief Change Car Status
   void setCarStatus(int Status);
   ///@brief Set summer tiers
   bool isSummerTiers(void);
   ///@brief Choose Gasoline need
   int chooseGasolineNeed(void);
   ///@brief Get gas Cost
   int getGasCost(void);
   ///@brief Get repair Cost
   int getRepairCost();
   ///@brief Can movor no?
   int canMove();
   ///@brief Get max speed
   int getMaxSpeed() const;
   ///@brief Consumpted during Gasoline
   int consumpedGasoline(int SomeDist);
   ///@brief Static integer constant variable max speed
   static const  int maxSpeed=150;
   ///@brief Static integer constant variable max Gasoline
   static const int maxGasoline=90;
   ///@brief Operator == overload.
   bool Car::operator==(const Car& car) const;
   ///@brief Operator ++ overload.
   Car& Car::operator++();
   ///@brief Operator -- overload.
   Car& Car::operator--();
   ///@brief Operator += overload.
   Car& Car::operator +=(const Car& car);

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
