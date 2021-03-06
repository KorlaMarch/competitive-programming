#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  mobile_in,      sensorTouch)
#pragma config(Sensor, dgtl2,  mobile_out,     sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_5,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_6,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           rwheel,        tmotorVex393_HBridge, openLoop, reversed, encoderPort, I2C_5)
#pragma config(Motor,  port2,           mcone,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           lmobile,       tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_4)
#pragma config(Motor,  port4,           rmobile,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           slift_tb,      tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_3)
#pragma config(Motor,  port6,           slift_tl,      tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port7,           slift_br,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rgrabber,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           lgrabber,      tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port10,          lwheel,        tmotorVex393_HBridge, openLoop, encoderPort, I2C_6)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int liftPow = 100;
bool isMobileIn = true;
bool isConeIn = true;

task main()
{
	//while(bSoundActive);
	//PlaySoundFile("allhuman.wav");
	nMotorEncoder[lgrabber] = 0;
	nMotorEncoder[slift_tb] = 0;
	nMotorEncoder[slift_tl] = 0;

	while(1){
		motor[lwheel] = vexRT[Ch3];
		motor[rwheel] = vexRT[Ch2]*0.70;

		if(vexRT[Btn6U]){
			motor[slift_tb] = liftPow;
			motor[slift_tl] = liftPow;
			motor[slift_br] = liftPow;
		}else if(vexRT[Btn6D]){
			motor[slift_tb] = -liftPow;
			motor[slift_tl] = -liftPow;
			motor[slift_br] = -liftPow;
		}else{
			motor[slift_tb] = 0;
			motor[slift_tl] = 0;
			motor[slift_br] = 0;
		}

		//cone picker (automatic version)
		if(vexRT[Btn5D]){
			if(isConeIn){
				//push out
				motor[mcone] = -80;
				motor[rgrabber] = 128;
				motor[lgrabber] = 128;
				wait(0.5);
				motor[rgrabber] = 0;
				motor[lgrabber] = 0;
			}else{
				//pull in
				motor[rgrabber] = -128;
				motor[lgrabber] = -128;
				wait(0.5);
				motor[rgrabber] = 0;
				motor[lgrabber] = 0;
				wait(1.5);
				motor[mcone] = 80;
				wait(1);
				motor[mcone] = 0;
			}
			isConeIn = !isConeIn;
		}

		if(vexRT[Btn7R]){
			motor[mcone] = 0;
		}

		//cone picker
		if(vexRT[Btn8L]){
			motor[mcone] = 100;
		}else if(vexRT[Btn8R]){
			motor[mcone] = -100;
		}else{
			//motor[mcone] = 0;
		}

		//grapper
		if(vexRT[Btn8U]){
			motor[rgrabber] = 128*0.6;
			motor[lgrabber] = 128*0.6;
		}else if(vexRT[Btn8D]){
			motor[rgrabber] = -127*0.6;
			motor[lgrabber] = -127*0.6;
		}else{
			motor[rgrabber] = 0;
			motor[lgrabber] = 0;
		}

		if(vexRT[Btn7L]&&!bSoundActive){
			PlaySoundFile("kill.wav");
		}

		//mobile goal lift control (automatic version)
		if(vexRT[Btn5U]){
			if(isMobileIn){
				while(!SensorValue[mobile_out]&&!vexRT[Btn7L]){
					motor[lmobile] = 100;
					motor[rmobile] = 100;
				}
			}else{
				while(!SensorValue[mobile_in]&&!vexRT[Btn7L]){
					motor[lmobile] = -100;
					motor[rmobile] = -100;
				}
			}
			motor[lmobile] = 0;
			motor[rmobile] = 0;
			isMobileIn = !isMobileIn;
		}

		//mobile goal lift control (manual version)
		if(vexRT[Btn7U]&&!SensorValue[mobile_in]){
			motor[lmobile] = -100;
			motor[rmobile] = -100;
		}else if(vexRT[Btn7D]&&!SensorValue[mobile_out]){
			motor[lmobile] = 100;
			motor[rmobile] = 100;
		}else{
			motor[lmobile] = 0;
			motor[rmobile] = 0;
		}
	}
}
