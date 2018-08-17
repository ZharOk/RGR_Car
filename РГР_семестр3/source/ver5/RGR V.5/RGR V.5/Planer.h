

#if !defined(__UMLClassDiagram_1_Planer_h)
#define __UMLClassDiagram_1_Planer_h
///@brief Class Timer, counting cycles of time.
class Timer;
///@brief Class Tour.
class Tour;
///@brief Class Roads.
class Roads;
///@brief Class of PossibleObstacle, generate
class PossibleObstacle;

///@brief Class Scane, planer of program.
class Planer
{
public:
	///@brief Constructor of Planer.
	Planer(Roads *someRoad, Timer *someTimer);
    ///@brief Destructor of Planer.
	~Planer();
	///@brief Start of Planer.
   void start(void);
   ///@brief Main Metod of Planer.
   void mainPlaner();

   ///@brief Finish of Planer.
   void finish(void);
   Roads* roads;
   Tour Tour;
   Timer* timer;

protected:
private:
inline void chekCarStatus();	

};

#endif
