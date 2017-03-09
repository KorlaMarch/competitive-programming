#include "stdio.h"
#include "stdlib.h"

#define NODE_COUNT 100
#define INF 100000
int main(){
	srand(13434);
	printf("%d\n",NODE_COUNT);

	printf("%d\n",50);
	for(int j = 0; j < 50; j++){
		printf("%d %d ",rand()%NODE_COUNT,INF);
	}

	for(int i = 1; i < NODE_COUNT; i++){
		printf("%d\n",10);
		printf("%d %d ",i-1,1);

		for(int j = 1; j < 10; j++){
			printf("%d %d ",rand()%NODE_COUNT,INF);
		}

	}
	printf("%d\n",10);
	for(int i = 0; i < 10; i++) printf("%d %d\n",NODE_COUNT-1,0);
}