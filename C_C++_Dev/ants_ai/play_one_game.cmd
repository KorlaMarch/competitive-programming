@echo off
cls
cd submission_test/
mingw32-make clean
mingw32-make
cd ..
python "%~dp0playgame.py" --engine_seed 42 --player_seed 42 --end_wait=0.25 --verbose -e --log_dir game_logs --turns 500 --map_file "%~dp0maps\random_walk\random_walk_03p_01.map" %* "python ""%~dp0sample_bots\python\LeftyBot.py""" "python ""%~dp0sample_bots\python\HunterBot.py""" """%~dp0submission_test\MyBot.exe"""

