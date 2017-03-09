#include "stdio.h"

struct point{
	int x,y;
};

int cross(point a, point b, point c){
	return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

bool isIntersect(point a1, point a2, point b1, point b2){
	return (cross(a1,a2,b1)>0)!=(cross(a1,a2,b2)>0)&&(cross(b1,b2,a1)>0)!=(cross(b1,b2,a2)>0);
}
 
int n,co;
point p[2000];
point in,far;

int main(){
	far.x = 50000;
	far.y = 1;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		for(int i = 0; i < n; i++){
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		scanf("%d%d",&in.x,&in.y);
		co = 0;
		for(int i = 1; i < n; i++){
			if(isIntersect(p[i-1],p[i],in,far)){
				co++;
			}
		}
		if(isIntersect(p[n-1],p[0],in,far)) co++;

		if(co%2) printf("T\n");
		else printf("F\n");
	}
}