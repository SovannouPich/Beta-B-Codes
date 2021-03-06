#pragma config(Motor,  port2,           Rclaw,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           Rbar,          tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           LF,            tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           LB,            tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           RF,            tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           RB,            tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
	{
		  //claw
		  while (1 == 1) {
			if(vexRT[Btn6U] == 1)       	//If Button 6U is pressed...
					{
						motor[Rclaw] = 127;  		//...open the gripper.
					}
					else if(vexRT[Btn6D] == 1)  	//Else, if button 6D is pressed...
					{
						motor[Rclaw] = -127; 		//...close the gripper.
					}
					else                      		//Else (neither button is pressed)...
					{
						motor[Rclaw] = 0;    		//...stop the gripper.
					}

			//reverse bars
			if(vexRT[Btn5U] == 1)					//If Button 5U is pressed...
				{
					motor[Rbar] = 127;				//...lift the reverse bar.
				}
				else if(vexRT[Btn5D] == 1)	//If Button 5D is pressed...
				{
					motor[Rbar] = -127;				//...lower the reversse bar.
				}
				else
				{
					motor[Rbar] = 0;					//...stop the reverse bar.
				}

			//wheels
			motor[LF] = vexRT[Ch4] + vexRT[Ch3] + vexRT[Ch1];
			motor[LB] = (-vexRT[Ch4]) + vexRT[Ch3] + vexRT[Ch1];
			motor[RF] = vexRT[Ch4] - vexRT[Ch3] + vexRT[Ch1];
			motor[RB] = (-vexRT[Ch4]) -vexRT[Ch3] + vexRT[Ch1];

		}
	}
