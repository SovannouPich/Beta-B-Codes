task main()
{
		 while(1 == 1)
		 {
		 motor[leftMotor] = vexRT[Ch3] / 2;
		 motor[rightMotor] = vexRT[Ch2] / 2;
		 if(vexRT[Btn6U] == 1)
		 {
		 	motor[armMotor] = 40;
		 }
		 else if (vexRT[Btn6D] == 1)
		 {
		 	motor[armMotor] = -40;
		 }
		 else
		 {
		 	motor[armMotor] = 0;
		}
	}
}
