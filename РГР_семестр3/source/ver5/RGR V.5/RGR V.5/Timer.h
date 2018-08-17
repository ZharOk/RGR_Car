

#if !defined(__UMLClassDiagram_1_Timer_h)
#define __UMLClassDiagram_1_Timer_h

///@brief Class Timer.
class Timer
{
public:
	///@brief Constructor of Timer.
	Timer();
	///@brief Distructor of Timer.
	~Timer();
   void increaseTimer(void);
   ///@brief Get time, return Current time.
   int getTime(void) const;
   ///@brief Stop timer.
   void stopTimer(void);

protected:
private:
	int startTime;
    int currTime;


};

#endif
