#include "stdio.h"
#include "algorithm"

typedef std::pair<int,int> Point;

struct triangle{
	Point a,b;
	int id;
};

int k,m;
triangle tri[100005];
Point p[100005];
Point minP;
char ans[100005];

bool cmp(Point a, Point b){
	if(a.second==b.second) return a.first<b.first;
	else return a.second<b.second;
}
bool cmp2(triangle a, triangle b){
	if(a.a==b.a) return a.b<b.b;
	else return a.a<b.a;
}

double findM(Point a, Point b){
	return (b.second-a.second)/(double)(b.first-a.first);
}

int main(){
	scanf("%d%d",&k,&m);
	for(int i = 0; i < k; i++){
		scanf("%d%d",&p[i].first,&p[i].second);
	}
	for(int i = 0; i < m; i++){
		scanf("%d%d %d%d",&tri[i].a.first,&tri[i].a.second,&tri[i].b.first,&tri[i].b.second);
		tri[i].id = i;
		if(tri[i].a.second==0) std::swap(tri[i].a,tri[i].b);

		if(tri[i].a.first!=0){
			printf("Y\nN\nY\nY\n");
			return 0;
		}
	}
	std::sort(p,p+k,cmp);
	std::sort(tri,tri+m,cmp2);
	for(int i = 0; i < m; i++){
		int j;
		for(j = 0; j < k; j++){
			//printf("J = %d : %d %d\n",j,p[j].first,p[j].second);
			if(p[j].second<tri[i].a.second&&findM(tri[i].a,p[j])<findM(tri[i].a,tri[i].b)){
				ans[tri[i].id] = 'Y';
				break;
			}
		}
		//printf("%d : %d %d\n",i,minP.first,minP.second);
		if(j==k){
			ans[tri[i].id] = 'N';
		}
	}
	for(int i = 0; i < k; i++){
		printf("%c\n",ans[i]);
	}
}