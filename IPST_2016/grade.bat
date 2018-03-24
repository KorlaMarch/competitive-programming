@echo off
echo Grading...
echo Result: >result.txt
echo. >>result.txt
FOR /L %%i IN (1,1,10) DO ( 
	%1 < ski.%%i.in > %%i.out
	echo TESTCASE %%i: >>result.txt
	echo TESTCASE %%i
	fc ski.%%i.out %%i.out >>result.txt
	DEL %%i.out
)
result.txt
pause