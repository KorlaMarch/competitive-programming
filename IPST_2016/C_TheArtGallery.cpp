#include "stdio.h"

struct point{
	int x,y;
	point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

int n;
point p[100];

int cross(point a, point b, point c){
	return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

int main(){
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		for(int i = 0; i < n; i++){
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		int i;
		if(cross(p[0],p[1],p[2])>0){
			for(i = 0; i < n; i++){
				if(cross(p[i],p[(i+1)%n],p[(i+2)%n])<0){
					break;
				}
			}
		}else{
			for(i = 0; i < n; i++){
				if(cross(p[i],p[(i+1)%n],p[(i+2)%n])>0){
					break;
				}
			}
		}
		if(i==n){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}
}