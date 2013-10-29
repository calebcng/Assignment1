#include ".\IO.h"
#include ".\rt.h"
#include <stdio.h>
#include <conio.h>

/*
I/O Program
Link to datapools, semaphores, open pipeline
install signal handler using intercept() primitive
*/

//Testing

struct LiftDataPool
{
	int CurrentFloor;
	int Direction;
	int LiftStatus;
	int DoorStatus;
};

int main()
{
	//Create and Link DataPools
	CDataPool dp1("Lift1", sizeof(struct LiftDataPool));
	CDataPool dp2("Lift2", sizeof(struct LiftDataPool));

	struct LiftDataPool* Lift1 = (struct LiftDataPool*)(dp1.LinkDataPool);
	struct LiftDataPool* Lift2 = (struct LiftDataPool*)(dp2.LinkDataPool);

	//Create Pipeline
	CPipe pipe3("IOPipe");

	//Create Semaphores
	CSemaphore P1( "Producer1", 0, 1 );
	CSemaphore C1( "Consumer1", 0, 1 );
	CSemaphore P3( "Producer2", 0, 1 );
	CSemaphore C3( "Consumer2", 0, 1 );

	//Install signal handler using intercept() primitive

	//Initialize variables
	char input[2];

do {
	//test keyboard for 2 characters
	input[0] = getch();
	input[1] = getch();

//	if(2 characters present) {
//		read them,
//		check they make sense and if so write them to the pipeline
//	}

	//Check inputs to make sure they are valid
	if( input[0]=='U' || input[0]=='D' || input[0]=='1' || input[0]=='2' ) {
		if( input[1]=='0' || input[1]=='1' || input[1]=='2' || input[1]=='3' || input[1]=='4' || input[1]=='5' || input[1]=='6' ||
			input[1]=='7' || input[1]=='8' || input[1]=='9' )
		{
			//Input characters make sense. Proceed to send to Dispatcher.
			printf( "Input characters make sense. Proceeding to Dispatcher.\n" );
		}
		else {
			printf( "Invalid inputs.\n" );
			continue;
		}
	}
	else {
		printf( "Invalid inputs.\n" );
		continue;
	}

/*	
	if(read_semaphore(PS3) > 0) car1 produced data 
		WAIT(PS3) ;
		read car1’s datapool into local structure
		SIGNAL(CS3) ;
		Redraw Lift1 screen
	} 
*/
	if( P1 > 0 ) {
		P1.Wait(); 
		int Lift1Floor = Lift1;
		int Lift1Direction;
		int Lift1Status;
		int Lift1DoorStatus;
	}
		

	if(read_semaphore(PS4) > 0) /* car2 produced data */
		WAIT(PS4) ;
		read car2’s datapool into local structure
		SIGNAL(CS4) ;
		Redraw Car2 screen
	}
} while(end of simulation flag is not TRUE) /* do until end of simulation*/
end program


Signal_handler() /* installed with intercept primitive, dispatcher sends this process signals */
{
	if(signal means final end of simulation from dispatcher)
	set end of simulation flag
}