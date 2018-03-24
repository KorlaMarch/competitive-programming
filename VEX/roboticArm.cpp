#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  arm_enleft,     sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  arm_enright,    sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  ien1,           sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ien2,           sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           arm_bleft,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           arm_tleft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           arm_bright,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           arm_tright,    tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int target = 0;
int armMax = 40;

int kp=50,ki=45,kd=60;
float lastE;
float lastI;
float pidout;

int min(int a, int b){
	return a<b?a:b;
}

int max(int a, int b){
	return a>b?a:b;
}

int bound(int x, int a, int b){
	return max(a,min(x,b));
}

float getNextPID(float v, float targetV){
	float cp, ci, cd;
	if(time1[T1]!=0){
		cp = target-v;
		//normalization
		cp /= armMax;
		ci = lastI + (lastE+et)/2.0*time1[T1];
		cd = (et-lastE)/time1[T1];

		lastE = cp;
		lastI = ci;
		pidout = kp*cp + ki*ci + kd*cd;
		ClearTimer(T1);
	}
	return pidout;
}

void reset(){
	//reset the arm to the resting position
	motor[arm_bleft] = -10;
	motor[arm_tleft] = -10;
	motor[arm_bright] = -10;
	motor[arm_tright] = -10;
	wait(0.5);
	motor[arm_bleft] = 0;
	motor[arm_tleft] = 0;
	motor[arm_bright] = 0;
	motor[arm_tright] = 0;

	SensorValue[arm_enleft] = 0;
	SensorValue[arm_enright] = 0;
	lastE = 0.0;
	lastI = 0.0;
	pidout = 0.0;
	target = 0;
	ClearTimer(T1);
}

task main()
{
	int pwn, newTarget;
	/*
	while(1){
		pwn = vexRT[Ch3]/2;
		motor[arm_bleft] = pwn;
		motor[arm_tleft] = pwn;
		motor[arm_bright] = pwn;
		motor[arm_tright] = pwn;
		writeDebugStreamLine("Encoder (LR) %d:%d", SensorValue[arm_enleft],SensorValue[arm_enright]);
	}
	*/
	reset();
	for(int x = 0; ; x++)
		if(x>5){
			newTarget = target + vexRT[Ch3]/60;
			if(newTarget >= 0 && newTarget < armMax){
				target = newTarget;
			}
			x = 0;
		}
		float avgV = (SensorValue[arm_enleft]+SensorValue[arm_enright])/2.0;
		//left motor
		pwn = bound((int)getNextPID(avgV,target),-127,127);
		motor[arm_bleft] = pwn;
		motor[arm_tleft] = pwn;
		motor[arm_bright] = pwn;
		motor[arm_tright] = pwn;
		writeDebugStreamLine("Encoder (LR) %d %d,%d", avgV,target,pwn);
		wait(0.01);
	}
}
