
#if !defined(__UMLClassDiagram_1_Tour_h)
#define __UMLClassDiagram_1_Tour_h

///@brief Class Tour.
class Tour
{
public:
	///@brief Constructor of Tour.
	Tour();
	///@brief Distructor of Tour.
	~Tour();
	///@brief Time of Tour.
	float TourTime();
	///@brief Change speed 
    void changeSpeed(int maxSpeed);
	///@brief Get current speed.
	float getCurrSpeed(void) const;
	///@brief Tour Lenght.
	void incrTourLength(int length);
	///@brief Get Tour Length.
	int getTourLength() const;
	///@brief Set Tour Time.
	void setTourTime(int someTime);
	///@brief Set Speed.
	void setSpeed(int speed);
	
protected:
private:
   friend float TourTime(Tour &);
   float currSpeed;
   int TourLength;
   float timeSpent;
   friend void setSpeed(int speed, Tour & );

};

#endif
