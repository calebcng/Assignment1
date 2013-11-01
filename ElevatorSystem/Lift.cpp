#include "Lift.h"

struct LiftDataPool
{
	int CurrentFloor;
	int Direction;
	int LiftStatus;
	int DoorStatus;
};

int main()
{
	if( liftnum == 1 ) {
		//Create datapools
		CDataPool dp("Lift1", sizeof(struct LiftDataPool));
		struct LiftDataPool* Lift = (struct LiftDataPool*)(dp1.LinkDataPool);
		//Create pipelines
		CPipe p1( "Lift1Pipe" );
		//Create Semaphores
		CSemaphore P1( "Producer1", 0, 1 );
		CSemaphore C1( "Consumer1", 0, 1 );
		CSemaphore P2( "Producer1", 0, 1 );
		CSemaphore C2( "Consumer1", 0, 1 );
	}
	else if( liftnum == 2 ) {
		//Create
		CDataPool dp("Lift2", sizeof(struct LiftDataPool));
		struct LiftDataPool* Lift = (struct LiftDataPool*)(dp2.LinkDataPool);
		//Create 
		
		CSemaphore P3( "Producer2", 0, 1 );
		CSemaphore C3( "Consumer2", 0, 1 );
		CSemaphore P4( "Producer2", 0, 1 );
		CSemaphore C4( "Consumer2", 0, 1 );
	}
	
	
	
	CPipe p1("Lift1Pipe");