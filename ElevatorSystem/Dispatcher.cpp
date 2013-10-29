#include "Dispatcher.h"

/*Dispatcher Program
Makes the Datapools/pipelines/semaphores,
Links to the datapools
Links to the 4 semaphores it uses
Opens the pipeline for reading
Fork the other three programs
*/
struct LiftDataPool
{
	int CurrentFloor;
	int Direction;
	int LiftStatus;
	int DoorStatus;
};

char input [2];



int main()
{
	int tempCurrentFloor; //local variables to store datapool data
	int tempDirection;
	int tempLiftStatus;
	int tempDoorStatus;

	int tempCurrentFloor2;
	int tempDirection2;
	int tempLiftStatus2;
	int tempDoorStatus2;

	CDataPool dp1("Lift1", sizeof(struct LiftDataPool)); // creating and linking datapools
	CDataPool dp2("Lift2", sizeof(struct LiftDataPool));

	struct LiftDataPool* Lift1 = (struct LiftDataPool*)(dp1.LinkDataPool);
	struct LiftDataPool* Lift2 = (struct LiftDataPool*)(dp2.LinkDataPool);

	CPipe pipe1("Lift1Pipe"); // creating pipelines
	CPipe pipe2("Lift2Pipe");
	CPipe pipe3("IOPipe");

	CSemaphore P2("Producer2", 0, 1); // creating semaphonres (for mutual exclusion of the datapool)
	CSemaphore P4("Producer4", 0, 1);
	CSemaphore C2("Consumer2", 1, 1);
	CSemaphore C4("Consumer4", 1, 1);



do {
//test pipeline for presence of 2 character command from IO process
if ((p3.TestForData()) == sizeof(input))
 {
	p3.Read(&input, sizeof(input));

	if (input[0] == 1) // Implies that a user is inside elevator #1
	{
		switch(input[1])
		{
	    
			case 0
				pipe1.Write(); // Command for elevator #1 to go to the 10th floor
				break;

			case 1
				pipe1.Write(); // and so on....
				break;

			case 2
				pipe1.Write();
				break;

			case 3
				pipe1.Write();
				break;

			case 4
				pipe1.Write();
				break;

			case 5
				pipe1.Write();
				break;

			case 6
				pipe1.Write();
				break;

			case 7
				pipe1.Write();
				break;

			case 8
				pipe1.Write();
				break;

			case 9
				pipe1.Write();
				break;
			default
				break();
		}

	
	}
	if (input[0] == 2) 
	{
		switch(input[1])
		{
	    
			case 0
				pipe2.Write(); // Command for elevator #1 to go to the 10th floor
				break;

			case 1
				pipe2.Write(); // and so on....
				break;

			case 2
				pipe2.Write();
				break;

			case 3
				pipe2.Write();
				break;

			case 4
				pipe2.Write();
				break;

			case 5
				pipe2.Write();
				break;

			case 6
				pipe2.Write();
				break;

			case 7
				pipe2.Write();
				break;

			case 8
				pipe2.Write();
				break;

			case 9
				pipe2.Write();
				break;
			default
				break();
		}

	}
	if(input[0] == 'U') // The passenger pressed "UP" from outside the elevators
	{

 		/* such as up or down request */
		/* simple algorithm */
		signal command to both lifts
		/* complex algorithm with more marks */
		look at status of both lifts
		signal the most appropriate lift
	}

	if(input[0] == 'D') // The passenger pressed "DOWN" from outside the elevators
	{

 		/* such as up or down request */
		/* simple algorithm */
		signal command to both lifts
		/* complex algorithm with more marks */
		look at status of both lifts
		signal the most appropriate lift
	}

	if(input == "ee")
	{
		Signal end of simulation to child process car1 and car2

		do{
			test status of each lift (in datapool)
		} while( lifts are not on ground floor and not idle)

		set flagto TRUE indicate exit simulation
	}
}
if((P2.Read()) > 0) /* indicates car1 has produced data */
{
	P2.Wait();

	tempCurrentFloor = Lift1->CurrentFloor; //copy contents of car*’s datapool into local structure
	tempDirection = Lift1->Direction;
	tempLiftStatus = Lift1->LiftStatus;
	tempDoorStatus = Lift1->DoorStatus;

	C2.Signal();
}

if((P4.Read()) > 0) /* indicates car1 has produced data */
{
	P4.Wait();

	tempCurrentFloor2 = Lift2->CurrentFloor; //copy contents of car*’s datapool into local structure
	tempDirection2 = Lift2->Direction;
	tempLiftStatus2 = Lift2->LiftStatus;
	tempDoorStatus2 = Lift2->DoorStatus;

	C4.Signal();
}

} while( exit flag is not TRUE)
	Signal three child processes telling them to exit Now (they should wait for this before exiting)
	Delete datapools, semaphores, empty pipeline
	end program

