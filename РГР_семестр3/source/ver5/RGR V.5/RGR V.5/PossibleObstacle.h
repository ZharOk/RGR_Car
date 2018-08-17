

#if !defined(__UMLClassDiagram_1_PossibleObstacle_h)
#define __UMLClassDiagram_1_PossibleObstacle_h
///@brief Obstacle on the Road;
class PossibleObstacle
{
	
public:
	///@brief Constructor of PossibleObstacle
	PossibleObstacle();
	///@brief Destructor of Road Obstacle
	~PossibleObstacle();
	///@brief Define Obstacle.
   void defineObstacle(void);
   ///@brief Get obstacle type on the road;
   int getObstacleType(void) const;
   
	
private:
   int obstacleType;


};

#endif
