/*
Snake Game ""

*/

#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <queue>

using namespace std;

char buffer[80][24];
//0 = null
//1 = menu
//2 = play
//3 = high score
//4 = about
//5 = Game over
int score;
int scene = 0;
int currentMenu = 0;
int inGame = 0;
//0 = north
//1 = south
//2 = east
//3 = west
int direction = 0;
string Menulist[4] = {"> play <", "high_score", "about", "exit"};
struct snakeBody {
	int x;
	int y;
};
queue<snakeBody> snake;

void render(){
	string temp;
	system("cls");
	for(int y = 0; y <= 23; y++){
		for(int x = 0; x <= 79; x++){
			temp += buffer[x][y];
			//cout << buffer[x][y];
		}
	}
	cout << temp;

}

void drawBox(int x, int y, int hight, int width, char bg){
	//make border

	//head and bottom
	for(int n = x + 1; n <= x + width - 1; n++){
		buffer[n][y] = 205;
		buffer[n][y + hight] = 205;
	}
	buffer[x][y] = 201;
	buffer[x][y + hight] = 200;
	buffer[x + width][y] = 187;
	buffer[x + width][y + hight] = 188;

	//mid
	for(int n = y + 1; n <= y + hight - 1; n++){
		buffer[x][n] = 186;
		buffer[x + width][n] = 186;
	}
	//draw BG
	for(int n = y + 1; n <= y + hight - 1; n++){
		for(int n2 = x + 1; n2 <= x + width - 1; n2++){
			buffer[n2][n] = bg;
		}
	}

}

void intGraphic(){
	//draw box

	//head and bottom
	for(int n = 0; n <= 79; n++){
		buffer[n][0] = 223;
		buffer[n][23] = 220;
	}
	buffer[0][0] = 219;
	buffer[79][0] = 219;
	buffer[0][23] = 219;
	buffer[79][23] = 219;

	//mid
	for(int n = 1; n <= 22; n++){
			buffer[0][n] = 219;
			for(int n2 = 1; n2 <= 78; n2++){
				buffer[n2][n] = 250;
			}
			buffer[79][n] = 219;
	}
}

void drawMenu(){
	//make border

	//head and bottom
	for(int n = 23; n <= 55; n++){
		buffer[n][8] = 205;
		buffer[n][15] = 205;
	}
	buffer[23][8] = 201;
	buffer[23][15] = 200;
	buffer[56][8] = 187;
	buffer[56][15] = 188;

	//mid
	for(int n = 9; n <= 14; n++){
		buffer[23][n] = 186;
		buffer[56][n] = 186;
	}
	//drawbox 6*32
	for(int n = 9; n <= 14; n++){
		for(int n2 = 24; n2 <= 55; n2++){
			buffer[n2][n] = ' ';
		}
	}

	//find mid point & print menu
	for(int n = 10; n <= 13; n++){
		int mid = (int)((32 - Menulist[n-10].length()) / 2) + 24;
		for(int n2 = 0; n2 <= Menulist[n-10].length() - 1; n2++){
			buffer[mid + n2][n] = (Menulist[n-10])[n2];
		}
	}
}

void moveSnack(snakeBody nextMove, int addNew);

void update(){

	//menu update
	if(scene == 1){
		if(GetAsyncKeyState(VK_UP) != 1 && GetAsyncKeyState(VK_UP) != 0){
			//play sound
			cout << "\a";
			//scroll manu up
			if(currentMenu == 0){
				currentMenu = 3;
				Menulist[0] = "play";
				Menulist[3] = "> exit <";
			} else if(currentMenu == 1){
				currentMenu = 0;
				Menulist[1] = "high_score";
				Menulist[0] = "> play <";
			} else if(currentMenu == 2){
				currentMenu = 1;
				Menulist[2] = "about";
				Menulist[1] = "> high_score <";
			} else if(currentMenu == 3){
				currentMenu = 2;
				Menulist[3] = "exit";
				Menulist[2] = "> about <";
			}
			drawMenu();
		} else if(GetAsyncKeyState(VK_DOWN) != 1 && GetAsyncKeyState(VK_DOWN) != 0){
			//play sound
			cout << "\a";
			//scroll manu down
			if(currentMenu == 0){
				currentMenu = 1;
				Menulist[0] = "play";
				Menulist[1] = "> high_score <";
			} else if(currentMenu == 1){
				currentMenu = 2;
				Menulist[1] = "high_score";
				Menulist[2] = "> about <";
			} else if(currentMenu == 2){
				currentMenu = 3;
				Menulist[2] = "about";
				Menulist[3] = "> exit <";
			} else if(currentMenu == 3){
				currentMenu = 0;
				Menulist[3] = "exit";
				Menulist[0] = "> play <";
			}
			drawMenu();
		} else if(GetAsyncKeyState(VK_RETURN) != 1 && GetAsyncKeyState(VK_RETURN) != 0){
			//play sound
			cout << "\a";
			if(currentMenu == 0){
				scene = 2;
			}else if(currentMenu == 1){
				scene = 3;
			}else if(currentMenu == 2){
				scene = 4;
				return;
			}else if(currentMenu == 3){
				exit(1);
			}
		}
	}






	//play scene
	if(scene == 2 && inGame == 0){

		//clear screen
		intGraphic();
		for(int n = 1; n <= 22; n++){
			for(int n2 = 1; n2 <= 78; n2++){
				buffer[n2][n] = ' ';
			}
		}

		//clear score
		score = 0;
		string text = "Score : 0000";
		for(int n = 67; n <= 78; n++){
			buffer[n][0] = text[n-67];
		}
		buffer[66][0] = 35;

		//make starter snake
		snakeBody temp;
		for(int n = 35; n <= 38; n++){
			temp.x = n;
			temp.y = 13;
			snake.push(temp);
		}
		temp.x = 38;
		temp.y = 13;
		moveSnack(temp, 0);
		direction = 2;
		//random ball
		buffer[rand() % 78 + 1][rand() % 22 + 1] = 15;
		inGame = 1;

	}else if(scene == 2 && inGame == 1){
		snakeBody next;
		//check key
		if(GetAsyncKeyState(VK_UP) && direction != 1){
			direction = 0;
		}else if(GetAsyncKeyState(VK_DOWN) && direction != 0){
			direction = 1;
		}else if(GetAsyncKeyState(VK_RIGHT) && direction != 3){
			direction = 2;
		}else if(GetAsyncKeyState(VK_LEFT) && direction != 2){
			direction = 3;
		}

		//move snake
		if(direction == 0){
			next.x = snake.back().x;
			next.y = snake.back().y - 1;
			moveSnack(next, 0);
		}else if(direction == 1){
			next.x = snake.back().x;
			next.y = snake.back().y + 1;
			moveSnack(next, 0);
		}else if(direction == 2){
			next.x = snake.back().x + 1;
			next.y = snake.back().y;
			moveSnack(next, 0);
		}else if(direction == 3){
			next.x = snake.back().x - 1;
			next.y = snake.back().y;
			moveSnack(next, 0);
		}

	}





	//hight score scene
	if(scene == 3){

	}





	//about
	if(scene == 4){
		//clear screen
		intGraphic();

		//check key prass
		if(GetAsyncKeyState(VK_RETURN) != 1 && GetAsyncKeyState(VK_RETURN) != 0){
			scene = 1;
			currentMenu = 0;
			intGraphic();
			drawMenu();
			return;
		}

		//make border

		//head and bottom
		for(int n = 23; n <= 55; n++){
			buffer[n][7] = 205;
			buffer[n][16] = 205;
		}
		buffer[23][7] = 201;
		buffer[23][16] = 200;
		buffer[56][7] = 187;
		buffer[56][16] = 188;

		//mid
		for(int n = 8; n <= 15; n++){
			buffer[23][n] = 186;
			buffer[56][n] = 186;
		}
		//drawbox 6*32
		for(int n = 8; n <= 15; n++){
			for(int n2 = 24; n2 <= 55; n2++){
				buffer[n2][n] = ' ';
			}
		}

		//find mid point & print about
		string about[3] = {"Snakey", "By", "KorlaMarch"};
		for(int n = 10; n <= 12; n++){
			int mid = (int)((32 - about[n-10].length()) / 2) + 24;
			for(int n2 = 0; n2 <= about[n-10].length() - 1; n2++){
				buffer[mid + n2][n] = (about[n-10])[n2];
			}
		}
		buffer[35][10] = 273;
		buffer[44][10] = 272;
		buffer[33][12] = 270;
		buffer[46][12] = 270;
		string printtext = "Enter to back";
		for(int n2 = 0; n2 <= printtext.length() - 1; n2++){
			buffer[43 + n2][8] = printtext[n2];
		}



		if(scene == 5){



		}
	}
}

void snakeEatEvent(){
	//makeNewBall
	while(1){
		int x = rand() % 78 + 1;
		int y = rand() % 22 + 1;
		if(buffer[x][y] != 'O'){
			buffer[x][y] = 15;
			break;
		}
	}
	//update score
	score += 10;
	buffer[78][0] = score % 10 + 48;
	buffer[77][0] = ((score % 100) - (score % 10)) / 10 + 48;
	buffer[76][0] = ((score % 1000)- (score % 100) - (score % 10)) / 100 + 48;
	buffer[75][0] = ((score % 10000) - (score % 1000) - (score % 100) - (score % 10)) / 1000 + 48;

}

void moveSnack(snakeBody nextMove, int addNew){
	//front = tail
	//back = head
	queue<snakeBody> Tempsnack;
	snake.push(nextMove);
	//check death
	if(buffer[nextMove.x][nextMove.y] != ' '){
		if(buffer[nextMove.x][nextMove.y] != 15){
			scene = 5;
			return;
		}else{
			addNew = 1;
			//play sound
			cout << "\a";
			snakeEatEvent();
		}

	}

	//remove old snake tail
	if(addNew != 1){
		buffer[snake.front().x][snake.front().y] = ' ';
		snake.pop();
	}


	while(!snake.empty()){
		//pop out and render
		buffer[snake.front().x][snake.front().y] = 'O';
		Tempsnack.push(snake.front());
		snake.pop();
	}
	//return old snake value
	snake = Tempsnack;
}

int main(int argc, char *argv[]) {
	intGraphic();
	drawMenu();
	scene = 1;
	while(true){
		update();
		render();
		Sleep(100);
	}
	return 1;
}
