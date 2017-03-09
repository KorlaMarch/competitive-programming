#include "stdio.h"
#include "algorithm"
#include "math.h"

struct point{
	int x,y;
};

int cross(point a, point b, point c){
	//printf("%d %d , %d %d , %d %d (%d - %d)\n",a.x,a.y,b.x,b.y,c.x,c.y,(b.x-a.x)*(c.y-a.y),(c.x-a.x)*(b.y-a.y));
	return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

point p[1000];
point st[1000];
int n,k,minP,stP;

bool cmp(point a, point b){
	const double at1 = atan2(a.y-p[0].y,a.x-p[0].x);
	const double at2 = atan2(b.y-p[0].y,b.x-p[0].x);
	if(at1==at2) return (a.x-p[0].x)*(a.x-p[0].x)+(a.y-p[0].y)*(a.y-p[0].y) < (b.x-p[0].x)*(b.x-p[0].x)+(b.y-p[0].y)*(b.y-p[0].y);
	else return at1<at2;
}

int main(){
	scanf("%d",&k);
	printf("%d\n",k);
	for(int i = 0; i < k; i++){
		scanf("%d",&n);
		minP = -1;
		stP = 0;
		for(int j = 0; j < n; j++){
			scanf("%d%d",&p[j].x,&p[j].y);
			if(minP==-1||p[j].y<p[minP].y||(p[j].y==p[minP].y&&p[j].x<p[minP].x)){
				minP = j;
			}
		}
		n--;
		std::swap(p[minP],p[0]);
		std::sort(p+1,p+n,cmp);

		st[stP++] = p[0];
		st[stP++] = p[1];
		for(int j = 2; j != 1; j = (j+1)%n){
			while(stP>=2&&cross(st[stP-2],st[stP-1],p[j])<=0){
				stP--;
				//printf("POP %d : (%d %d) %d %d (%d %d): %d)\n",stP, st[stP-1].x, st[stP-1].y, 
				//st[stP].x, st[stP].y, p[j].x, p[j].y, cross(st[stP-1],st[stP],p[j]));
			}
			//printf("PUSH %d : %d %d\n",stP, p[j].x, p[j].y);
			st[stP++] = p[j];
		}

		printf("%d\n",stP);
		for(int j = 0; j < stP; j++){
			printf("%d %d\n",st[j].x,st[j].y);
		}

		if(i+1!=k){
			scanf("%d",&n);
			printf("-1\n");
		}
	}
}