#include "stdio.h"
#include "stdlib.h"

#define V 71
#define E 1501
int main(){
	srand(13434);
	printf("%d %d\n",V,E);

	int c = 0;
	for(int i = 0; i < V && c < E; i++){
		for(int j = i+1; j < V && c < E; j++){
			printf("%d %d\n",i,j);
			c++;
		}
	}
}