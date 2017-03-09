#include "stdio.h"
#include "vector"
#include "algorithm"

struct point{
	double x,y;
	point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

bool cmp(point a, point b){
	if(a.x!=b.x){
		return a.x < b.x;
	}else{
		return a.y < b.y;
	}
}

double cross(point a, point b, point c){
	return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}


bool isIntersect(point a1, point a2, point b1, point b2){
	return (cross(a1,a2,b1)>0)!=(cross(a1,a2,b2)>0)&&(cross(b1,b2,a1)>0)!=(cross(b1,b2,a2)>0);
}


point findIntersect(point a1, point a2, point b1, point b2){
	double m1 = (a2.y-a1.y)/(a2.x-a1.x);
	double m2 = (b2.y-b1.y)/(b2.x-b1.x);
	point p;

	p.x = (b1.y-a1.y+m1*a1.x-m2*b1.x)/(m1-m2);
	p.y = m1*(p.x-a1.x)+a1.y;
	//printf("RE %.2f %.2f, %.2f %.2f, %.2f %.2f, %.2f %.2f : %.2f %.2f\n",a1.x,a1.y,a2.x,a2.y,b1.x,b1.y,b2.x,b2.y,p.x,p.y);
	return p;
}

point findIntersectX(double x, point a1, point a2){
	double m1 = (a2.y-a1.y)/(a2.x-a1.x);
	point p;
	p.x = x;
	p.y = m1*(p.x-a1.x)+a1.y;

	return p;
}

int n,m;
point conA[1000];
point conB[1000];
point far;
std::vector<point> ans,ans2;

int main(){
	far.x = 50000;
	far.y = 1;
	while(1){
		scanf("%d",&n);
		if(n<3) break;
		for(int i = 0; i < n; i++){
			scanf("%lf %lf",&conA[i].x,&conA[i].y);
		}

		scanf("%d",&m);
		if(m<3) break;
		for(int i = 0; i < m; i++){
			scanf("%lf %lf",&conB[i].x,&conB[i].y);
		}

		ans.clear();

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				point p;
				if(conA[i].x==conA[(i+1)%n].x&&conB[j].x==conB[(j+1)%m].x){
				}else if(conA[i].x==conA[(i+1)%n].x){
					p = findIntersectX(conA[i].x,conB[j],conB[(j+1)%m]);
					if(std::min(conA[i].y,conA[(i+1)%n].y)<=p.y&&p.y<=std::max(conA[i].y,conA[(i+1)%n].y)
						&&std::min(conB[j].y,conB[(j+1)%m].y)<=p.y&&p.y<=std::max(conB[j].y,conB[(j+1)%m].y)){
						//printf("P1 %d %d\n",i,j);
						ans.push_back(p);
					}
				}else if(conB[j].x==conB[(j+1)%m].x){
					p = findIntersectX(conB[j].x,conA[i],conA[(i+1)%n]);
					if(std::min(conB[j].y,conB[(j+1)%m].y)<=p.y&&p.y<=std::max(conB[j].y,conB[(j+1)%m].y)
						&&std::min(conA[i].y,conA[(i+1)%n].y)<=p.y&&p.y<=std::max(conA[i].y,conA[(i+1)%n].y)){
						//printf("P2 %d %d\n",i,j);
						ans.push_back(p);
					}
				}else{
					p = findIntersect(conA[i],conA[(i+1)%n],conB[j],conB[(j+1)%m]);
					if(std::min(conA[i].y,conA[(i+1)%n].y)<=p.y&&p.y<=std::max(conA[i].y,conA[(i+1)%n].y)
						&&std::min(conB[j].y,conB[(j+1)%m].y)<=p.y&&p.y<=std::max(conB[j].y,conB[(j+1)%m].y)){
						//printf("P3 %d %d\n",i,j);
						ans.push_back(p);
					}
				}
			}
		}

		for(int i = 0; i < n; i++){
			int co = 0;
			for(int j = 0; j < m; j++){
				if(isIntersect(conB[j],conB[(j+1)%m],conA[i],far)){
					co++;
				}
			}
			if(co%2){
				ans.push_back(conA[i]);
			}
		}

		for(int i = 0; i < m; i++){
			int co = 0;
			for(int j = 0; j < n; j++){
				if(isIntersect(conA[j],conA[(j+1)%n],conB[i],far)){
					co++;
				}
			}
			if(co%2){
				ans.push_back(conB[i]);
			}
		}

		std::sort(ans.begin(),ans.end(),cmp);

		if(ans.size()==0) printf("0\n");
		else{
			ans2.clear();
			ans2.push_back(ans[0]);
			for(int i = 1; i < ans.size(); i++){
				if(ans[i].x!=ans[i-1].x||ans[i].y!=ans[i-1].y){
					ans2.push_back(ans[i]);
				}
			}

			printf("%d\n",ans2.size());
			for(point p : ans2){
				printf("%.2f %.2f\n",p.x,p.y);
			}
		}
	}

}