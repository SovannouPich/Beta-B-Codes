#pragma config(Motor,  port2,           Rclaw,        tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
	{
		while (1 == 1) {
			//claw
			if(vexRT[Btn6U] == 1)       	//If Button 6U is pressed...
					{
						motor[Rclaw] = 127;  		//...close the gripper.
					}
					else if(vexRT[Btn5U] == 1)  	//Else, if button 6D is pressed...
					{
						motor[Rclaw] = -127; 		//...open the gripper.
					}
					else                      		//Else (neither button is pressed)...
					{
						motor[Rclaw] = 0;    		//...stop the gripper.

					}
			}
	}
