@echo off
echo Grading...
FOR /L %%i IN (1,1,%1) DO ( 
	echo Test %%i
	o56_oct_am3class.exe < %%i.in
)