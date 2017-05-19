#include "stdio.h"

int h,w,q,r1,c1,r2,c2;
int g;
char mp[305][305];
bool isV[305][305];

void count(int x, int y, char c){
	if(x<r1||x>r2||y<c1||y>c2||isV[x][y]||mp[x][y]!=c) return;
	isV[x][y] = true;
	//printf("Set %d %d %c\n",x,y,c);
	count(x-1,y,c);
	count(x+1,y,c);
	count(x,y-1,c);
	count(x,y+1,c);
}

int main(){
	scanf("%d%d%d",&h,&w,&q);
	for(int i = 1; i <= h; i++){
		scanf(" %s",mp[i]+1);
	}
	for(int i = 0; i < q; i++){
		g = 0;
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		for(int x = r1; x <= r2; x++){
			for(int y = c1; y <= c2; y++){
				isV[x][y] = false;
			}
		}
		for(int x = r1; x <= r2; x++){
			for(int y = c1; y <= c2; y++){
				if(!isV[x][y]){
					g++;
					//printf("get %d %d\n",x,y);
					count(x,y,mp[x][y]);
				}
			}
		}
		printf("%d\n",g);
	}
}