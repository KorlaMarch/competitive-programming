#include "stdio.h"
#include "algorithm"
#include "stdlib.h"

#define INF 100000000
//#define DEBUG

struct pos{
	int x,y;
};

int count = 0;
pos cu;
pos box[10];
int mxX,mxY,mnX,mnY;

void recal(){
	mxX = mxY = -INF;
	mnX = mnY = INF;
	for(int i = 0; i < 10; i++){
		mxX = std::max(mxX,box[i].x);
		mxY = std::max(mxY,box[i].y);
		mnX = std::min(mnX,box[i].x);
		mnY = std::min(mnY,box[i].y);
	}
}

void checkCol(int x, int y, char di){
	for(int i = 0; i < 10; i++){
		if(box[i].x==x&&box[i].y==y){
			switch(di){
				case 'U':
					checkCol(box[i].x,box[i].y+1,di);
					box[i].y++;
					break;
				case 'L':
					checkCol(box[i].x-1,box[i].y,di);
					box[i].x--;
					break;
				case 'R':
					checkCol(box[i].x+1,box[i].y,di);
					box[i].x++;
					break;
				case 'D':
					checkCol(box[i].x,box[i].y-1,di);
					box[i].y--;
					break;
			}
		}
	}
}

void move(char di){
	#ifndef DEBUG
	putchar(di);
	#endif
	if(count>10000) exit(-1);
	count++;
	switch(di){
		case 'U':
			checkCol(cu.x,cu.y+1,di);
			cu.y++;
			break;
		case 'L':
			checkCol(cu.x-1,cu.y,di);
			cu.x--;
			break;
		case 'R':
			checkCol(cu.x+1,cu.y,di);
			cu.x++;
			break;
		case 'D':
			checkCol(cu.x,cu.y-1,di);
			cu.y--;
			break;
		default:
			exit(-1);
	}
}

void repmove(char di, int x){
	if(x<0){
		switch(di){
			case 'U':
				di = 'D';
				break;
			case 'L':
				di = 'R';
				break;
			case 'R':
				di = 'L';
				break;
			case 'D':
				di = 'U';
				break;
		}
		x = -x;
	}
	for(int i = 0; i < x; i++){
		move(di);
	}
}

bool isBox(int x, int y){
	for(int i = 0; i < 10; i++){
		if(box[i].x==x&&box[i].y==y){
			return true;
		}
	}
	return false;
}

void print(){
	#ifdef DEBUG
	int pad = 1;
	printf("CU %d %d (%d)\n",cu.x,cu.y,count);
	recal();
	printf("MX %d %d %d %d\n",mxX,mnX,mxY,mnY);
	for(int j = mxY+pad; j >= mnY-pad; j--){
		for(int i = mnX-pad; i <= mxX+pad; i++){
			if(cu.x==i&&cu.y==j){
				putchar('O');
			}else if(isBox(i,j)){
				putchar('#');
			}else{
				putchar('.');
			}
		}
		putchar('\n');
	}
	putchar('\n');
	#endif
}

void checkIOI(){
	recal();
	for(int i = 0; i < 10; i++){
		box[i].x -= mnX;
		box[i].y -= mnY;
		//printf("%d %d\n",box[i].x,box[i].y);
	}
	if(!isBox(5,3)
		||!isBox(3,1)
		||!isBox(0,0)
		||!isBox(2,0)
		||!isBox(3,0)
		||!isBox(5,1)
		||!isBox(5,0)
		||!isBox(2,1)
		||!isBox(0,1)
		||!isBox(0,3)) exit(-1);
}

int main(){
	cu.x = 0;
	cu.y = 0;
	for(int i = 0; i < 10; i++){
		scanf("%d%d",&box[i].x,&box[i].y);
		if(box[i].x<-10||box[i].x>10||box[i].y<-10||box[i].y>10) exit(-1);
	}
	//get out of box zone
	print();
	repmove('D',11);
	move('L');
	repmove('D',12);
	move('R');
	repmove('U',12);

	//compact it
	repmove('L',10);
	while(cu.x<=10){
		repmove('U',20);
		repmove('D',20);
		move('R');
	}
	repmove('L',22);
	repmove('U',21);
	while(cu.y<20){
		repmove('R',20);
		repmove('L',20);
		move('U');
	}
	//make a line (10,10)->(19,10)
	repmove('R',20);
	repmove('D',9);
	print();
	recal();
	while(mxX<19){
		//push everything to mxX+1
		int ox=cu.x, oy=cu.y;
		while(cu.y<=mxY){
			repmove('R',mxX-ox);
			repmove('L',mxX-ox);
			move('U');
		}
		repmove('R',mxX-ox+1);
		
		recal();
		ox = cu.x-1;
		oy = cu.y;
		while(cu.x<=mxX){
			while(!isBox(cu.x,10)){
				move('D');
			}
			repmove('U',oy-cu.y);
			move('R');
		}
		repmove('L',cu.x-ox);
		repmove('D',cu.y-11);
		print();
		recal();
	}
	repmove('L',cu.x-10);
	print();
	//make IOI 
	repmove('D',3);
	repmove('U',3);
	
	repmove('R',2);
	repmove('D',3);
	repmove('U',3);

	repmove('R',1);
	repmove('D',3);
	repmove('U',3);

	repmove('R',2);
	repmove('D',3);
	repmove('U',3);

	repmove('R',5);
	repmove('D',1);
	repmove('L',4);
	repmove('U',1);

	repmove('L',1);
	repmove('D',2);
	repmove('U',2);

	repmove('L',2);
	repmove('D',2);
	repmove('U',2);

	repmove('L',1);
	repmove('D',2);
	repmove('U',2);

	repmove('L',2);
	repmove('D',2);
	repmove('U',2);

	//dot
	repmove('R',2);
	repmove('D',1);
	repmove('L',1);
	repmove('R',3);

	print();


	checkIOI();
}

