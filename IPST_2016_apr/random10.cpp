#include "stdlib.h"
#include "time.h"
#include "stdio.h"

struct pos{
	int x,y;
};

int n;
pos box[10];

bool isBox(int x, int y){
	for(int i = 0; i < n; i++){
		if(box[i].x==x&&box[i].y==y){
			return true;
		}
	}
	return false;
}

int main(){
	srand(time(NULL));
	for(n = 0; n < 10; n++){
		do{
			box[n].x = rand()%21-10;
			box[n].y = rand()%21-10;
		}while(isBox(box[n].x,box[n].y));
		printf("%d %d\n",box[n].x,box[n].y);
	}
}