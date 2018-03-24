@echo off
cls

echo ====Subtask1====
sub1.exe > tasksauthor.out1.1
node countElement.js tasksauthor.out1.1 107
echo Run A
ModifiedDijkstra.exe < tasksauthor.out1.1
echo Run B
FloydWarshall.exe < tasksauthor.out1.1
echo.

echo ====Subtask2====
sub2.exe > tasksauthor.out2.1
node countElement.js tasksauthor.out2.1 2222
echo Run A
FloydWarshall.exe < tasksauthor.out2.1
echo Run B
OptimizedBellmanFord.exe < tasksauthor.out2.1
echo.

echo ====Subtask3====
sub3.exe > tasksauthor.out3.1
node countElement.js tasksauthor.out3.1 105
echo Run A
OptimizedBellmanFord.exe < tasksauthor.out3.1
echo Run B
FloydWarshall.exe < tasksauthor.out3.1
echo.

echo ====Subtask4====
sub4.exe > tasksauthor.out4.1
node countElement.js tasksauthor.out4.1 157
echo Run A
FloydWarshall.exe < tasksauthor.out4.1
echo Run B
ModifiedDijkstra.exe < tasksauthor.out4.1
echo.

echo ====Subtask5====
sub5.exe > tasksauthor.out5.1
node countElement.js tasksauthor.out5.1 1016
echo Run A
ModifiedDijkstra.exe < tasksauthor.out5.1
echo Run B
OptimizedBellmanFord.exe < tasksauthor.out5.1
echo.

echo ====Subtask6====
sub6.exe > tasksauthor.out6.1
node countElement.js tasksauthor.out6.1 143
echo Run A
OptimizedBellmanFord.exe < tasksauthor.out6.1
echo Run B
ModifiedDijkstra.exe < tasksauthor.out6.1
echo.

echo ====Subtask7====
sub7.exe > tasksauthor.out7.1
node countElement.js tasksauthor.out7.1 3004
echo Run A
Gamble1.exe < tasksauthor.out7.1
echo Run B
RecursiveBacktracking.exe < tasksauthor.out7.1
echo.

echo ====Subtask8====
sub8.exe > tasksauthor.out8.1
node countElement.js tasksauthor.out8.1 3004
echo Run A
RecursiveBacktracking.exe < tasksauthor.out8.1
echo Run B
Gamble2.exe < tasksauthor.out8.1
echo.