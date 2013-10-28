#include ".\Dispatcher.h"



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

int main()
{
	CDataPool dp1("Lift1", sizeof(struct LiftDataPool));
	CDataPool dp2("Lift2", sizeof(struct LiftDataPool));

	struct LiftDataPool* Lift1 = (struct LiftDataPool*)(dp1.LinkDataPool);
	struct LiftDataPool* Lift2 = (struct LiftDataPool*)(dp2.LinkDataPool);

	CPipe p1("Lift1Pipe");
	CPipe p2("Lift2Pipe");
	CPipe p3("IOPipe");


do {
test pipeline for presence of 2 character command from IO process
if (/* 2 character command present:*/ p3.) {
	if (command for lift1) {
		signal command to lift 1
	}
	if (command for lift2) {
		signal command to lift 2
	}
	if(command for either lift) {
 		/* such as up or down request */
		/* simple algorithm */
		signal command to both lifts
		/* complex algorithm with more marks */
		look at status of both lifts
		signal the most appropriate lift
	}
	if(command is ‘ee’ for exit) {
		Signal end of simulation to child process car1 and car2
		do{
			test status of each lift (in datapool)
		} while( lifts are not on ground floor and not idle)
		set flagto TRUE indicate exit simulation
	}
}
if(read semaphore(PS1) > 0) /* indicates car1 has produced data */
	Wait(PS1)
	copy contents of car*’s datapool into local structure
	Signal (CS1)
}
if(read semaphore(PS2) > 0) /* indicates car2 has produced data */
	wait(PS2
	copy contents of car*’s datapool into local structure
	Signal (CS2)
}
} while( exit flag is not TRUE)
	Signal three child processes telling them to exit Now (they should wait for this before exiting)
	Delete datapools, semaphores, empty pipeline
	end program

