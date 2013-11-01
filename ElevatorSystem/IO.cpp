#include ".\IO.h"
#include <stdio.h>
#include <conio.h>

/*
I/O Program
Link to datapools, semaphores, open pipeline
install signal handler using intercept() primitive
*/
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
	int Lift1Floor, Lift2Floor;
	int Lift1Direction, Lift2Direction;
	int Lift1Status, Lift2Status;
	int Lift1DoorStatus, Lift2DoorStatus;

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
				pipe3.Write( &input, sizeof(input) );
			}
			else {
				printf( "Invalid inputs.\n" );
				continue;
			}
		}
		else if( input[0]=='e' && input[1] == 'e' ) {
			//trigger end simulation flag
			printf( "Request to end simulation.\n" );
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
		if( P1.Read() > 0 ) {
			//WAIT(PS1)
			P1.Wait();
			//read Lift1's datapool into local structure
			Lift1Floor = Lift1->CurrentFloor;
			Lift1Direction = Lift1->Direction;
			Lift1Status = Lift1->LiftStatus;
			Lift1DoorStatus = Lift1->DoorStatus;
			//Signal(CS1)
			C1.Signal();
			//Redraw Lift1 screen
		}
			
		if( P3.Read() > 0 ) {
			//WAIT(PS3)
			P3.Wait();
			//read Lift2's datapool into local structure
			Lift2Floor = Lift2->CurrentFloor;
			Lift2Direction = Lift2->Direction;
			Lift2Status = Lift2->LiftStatus;
			Lift2DoorStatus = Lift2->DoorStatus;
			//Signal(CS1)
			C3.Signal();
			//Redraw Lift2 screen
		}
	} while(end of simulation flag is not TRUE) /* do until end of simulation*/
	
	//end program
	return 0;
}


Signal_handler() /* installed with intercept primitive, dispatcher sends this process signals */
{
	if(signal means final end of simulation from dispatcher)
	set end of simulation flag
}