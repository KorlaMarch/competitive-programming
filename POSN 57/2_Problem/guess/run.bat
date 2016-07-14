@ECHO off
grader.exe < "grader.in.1" > out.txt
fc "out.txt" "grader.expect.1"
grader.exe < "grader.in.2" > out.txt
fc "out.txt" "grader.expect.2"
grader.exe < "grader.in.3" > out.txt
fc "out.txt" "grader.expect.3"
grader.exe < "grader.in.4" > out.txt
fc "out.txt" "grader.expect.4"
grader.exe < "grader.in.5" > out.txt
fc "out.txt" "grader.expect.5"
grader.exe < "grader.in.6" > out.txt
fc "out.txt" "grader.expect.6"
grader.exe < "grader.in.7" > out.txt
fc "out.txt" "grader.expect.7"
grader.exe < "grader.in.8" > out.txt
fc "out.txt" "grader.expect.8"
pause