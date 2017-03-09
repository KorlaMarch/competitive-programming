#include "stdio.h"
#include "stdlib.h"

#define NODE_COUNT 300
#define INF 100000
int main(){
	srand(13434);
	printf("%d\n",NODE_COUNT);

	printf("%d\n",40);
	for(int j = 0; j < 40; j++){
		printf("%d %d ",rand()%NODE_COUNT,INF);
	}

	for(int i = 1; i < NODE_COUNT; i++){
		printf("%d\n",1);
		printf("%d %d ",i-1,1);
	}
	printf("%d\n",10);
	for(int i = 0; i < 10; i++) printf("%d %d\n",NODE_COUNT-1,0);
}