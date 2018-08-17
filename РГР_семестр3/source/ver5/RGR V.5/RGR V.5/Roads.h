

#if !defined(__UMLClassDiagram_1_Roads_h)
#define __UMLClassDiagram_1_Roads_h


class Car;
///@brief Class Roads.
class Roads
{
public:
	///@brief Constructor of Roads.
	Roads();
	///@brief Destructor of Roads.
	~Roads();
	///@brief Crashing on the Road.
   bool crash(int level);
   ///@brief Define crash level.
   int defineCrashLevel(int currSpeed);
   ///@brief Change Speed LImit, by random.
   void changeSpeedLimit();
   ///@brief Get speed Limit. @return Speed Limit.
   int getSpeedLimit() const;

   Car* car;

protected:
private:
   int speedLimit;
   bool isWinter;
   int roadStatus;
   int crashLevel;


};

#endif
