@echo off
echo Grading...
echo Result: >result.txt
echo. >>result.txt
FOR /L %%i IN (1,1,20) DO ( 
	%1 < %%i.in > %%i.out
	echo TESTCASE %%i: >>result.txt
	echo TESTCASE %%i
	fc /W %%i.sol %%i.out >>result.txt
	DEL %%i.out
)
result.txt