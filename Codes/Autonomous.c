//negative == open, positive == close;
		void grab(int speed, int val){
			SensorValue(grabEncoder)= 0;
			while(SensorValue(grabEncoder) == val){
				motor[grabMotor1]= speed;
				motor[grabMotor2]= speed;
			}
			motor[grabMotor1]= 0;
			motor[grabMotor2]= 0;
		}

		void lift(int speed, int time){

			motor[TrightMotor]= speed/2;
			motor[BrightMotor]= speed/2;
			motor[BleftMotor]= speed/2;
			motor[TleftMotor]= speed/2;
			wait1Msec(time);
		}

	//Moving the speed must be less than or = 105
		void move(int speed, int val) {

			resetMotorEncoder(leftMotor);
			resetMotorEncoder(rightMotor);

			while(getMotorEncoder(rightMotor) == val){
			    motor[rightMotor] = speed;
			    motor[leftMotor] = speed;
			}
			 motor[rightMotor] = 0;
 			 motor[leftMotor] = 0;
		}

	//Turning left
		void turnLeft(int speed, int val){
			resetMotorEncoder(leftMotor);
			resetMotorEncoder(rightMotor);
			while(getMotorEncoder(leftMotor) == val){
				motor[leftMotor]= speed * -1;
				motor[rightMotor]= speed;
			}
			motor[leftMotor]= 0;
			motor[rightMotor]= 0;

		}

		//Turning right
		void turnRight(int speed, int val){
			resetMotorEncoder(leftMotor);
			resetMotorEncoder(rightMotor);
			while(getMotorEncoder(rightMotor) == val){
				motor[leftMotor]= speed;
				motor[rightMotor]= speed * -1;
			}
			motor[leftMotor]= 0;
			motor[rightMotor]= 0;
		}

//Finished this at November 11, 2016

task main()
{
	if(vexRT(Btn7L) == 1){

		move(105, 2010); // Move forward
		grab(110, 250); // hole on to the cube, 279.287587mm 28 cm
		turnLeft(110, 35); // turn left if our robot is at the left side
		move(105, 2010); // move forward untile near the middle fence
		lift(100, 1500); // lift the cube up
		move(60, 5); // move a bit
		grab(-110, 200); // drop the cube
		// stay there to block
	}
	else if (vexRT(Btn7R) == 1){

		move(105, 2010); // Move forward
		grab(110, 250); // hole on to the cube, 279.287587mm 28 cm
		turnRight(110, 35); // turn right if our robot is at the left side
		move(105, 2010); // move forward untile near the middle fence
		lift(100, 1500); // lift the cube up
		move(60, 5); // move a bit
		grab(-110, 200); // drop the cube
		// stay there to block
	}
	else{
		motor[rightMotor]=0; //do nothing
		motor[leftMotor]=0; //do nothhing
	}
}
