#include "stdio.h"
#include "stdlib.h"

#define NODE_COUNT 101

int main(){
	srand(13434);
	printf("%d\n",NODE_COUNT);
	for(int i = 0; i < NODE_COUNT; i++){
		printf("%d\n",0);
	}
	printf("%d\n%d %d\n",1,0,1);
}