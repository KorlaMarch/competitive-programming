#include "stdio.h"
#include "algorithm"

struct point{
	int x,y;
	point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

int cross(point a, point b, point c){
	return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

bool checkBoundingBox(point a1, point a2, point b1, point b2){
	return std::max(std::min(a1.x,a2.x),std::min(b1.x,b2.x))<=std::min(std::max(a1.x,a2.x),std::max(b1.x,b2.x))
		&& std::max(std::min(a1.y,a2.y),std::min(b1.y,b2.y))<=std::min(std::max(a1.y,a2.y),std::max(b1.y,b2.y));
}

bool isIntersect(point a1, point a2, point b1, point b2){
	return (((cross(a1,a2,b1)>0)!=(cross(a1,a2,b2)>0)&&(cross(b1,b2,a1)>0)!=(cross(b1,b2,a2)>0))
		||(cross(a1,a2,b1)==0&&cross(a1,a2,b2)==0)||(cross(b1,b2,a1)==0&&cross(b1,b2,a2)==0) )
		&& checkBoundingBox(a1,a2,b1,b2);
}

int n;
point rec[4];
point ls,le;

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d%d %d%d %d%d %d%d",&ls.x,&ls.y,&le.x,&le.y,&rec[0].x,&rec[0].y,&rec[2].x,&rec[2].y);
		
		rec[1].x = rec[0].x;
		rec[1].y = rec[2].y;
		rec[3].x = rec[2].x;
		rec[3].y = rec[0].y;

		int j;
		if(checkBoundingBox(ls,ls,rec[0],rec[2])||checkBoundingBox(le,le,rec[0],rec[2])) printf("T\n");
		else{
			for(j = 0; j < 4; j++){
				if(isIntersect(rec[j],rec[(j+1)%4],ls,le)){
					printf("T\n");
					break;
				}
			}

			if(j==4) printf("F\n");
		}
	}
}