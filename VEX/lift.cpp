#pragma config(Motor,  port2,            ,             tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,            ,             tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,            ,             tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int pwn;
	while(1){
		pwn = vexRT[Ch3];
		motor[port2] = pwn;
		motor[port3] = pwn;
		motor[port4] = pwn;
		motor[port5] = pwn;
	}


}
