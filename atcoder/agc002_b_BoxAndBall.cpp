#include "stdio.h"

int n,m,x,y;
int ball[100005];
bool isRed[100005];
int c;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		ball[i] = 1;
	}
	isRed[1] = true;
	for(int i = 0; i < m; i++){
		scanf("%d%d",&x,&y);
		if(isRed[x]) isRed[y] = true;
		ball[x]--,ball[y]++;
		if(ball[x]==0) isRed[x] = false;
	}
	for(int i = 1; i <= n; i++){
		if(isRed[i]) c++;
	}
	printf("%d\n",c);
}