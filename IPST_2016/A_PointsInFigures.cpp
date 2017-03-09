#include "stdio.h"
#include "math.h"

int n;
char ft[100000];
double fi[100000][6];
double x,y;

double cross(double x1, double y1, double x2, double y2, double x3, double y3){
	return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}

bool isContained(int i, double x, double y){
	if(ft[i]=='r'){
		return x<fi[i][2]&&x>fi[i][0]&&y<fi[i][1]&&y>fi[i][3];
	}else if(ft[i]=='c'){
		return sqrt( (fi[i][0]-x)*(fi[i][0]-x) + (fi[i][1]-y)*(fi[i][1]-y) ) < fi[i][2];
	}else{
		double a = cross(fi[i][0],fi[i][1],fi[i][2],fi[i][3],x,y);
		double b = cross(fi[i][2],fi[i][3],fi[i][4],fi[i][5],x,y);
		double c = cross(fi[i][4],fi[i][5],fi[i][0],fi[i][1],x,y);
		return a!=0.0&&b!=0.0&&c!=0.0&&(a<0.0)==(b<0.0)&&(b<0.0)==(c<0.0);
	}
}

int main(){
	for(n = 0; ; n++){
		scanf(" %c",&ft[n]);
		if(ft[n]=='*') break;
		else{
			if(ft[n]=='r'){
				scanf("%lf%lf%lf%lf",&fi[n][0],&fi[n][1],&fi[n][2],&fi[n][3]);
			}else if(ft[n]=='c'){
				scanf("%lf%lf%lf",&fi[n][0],&fi[n][1],&fi[n][2]);
			}else{
				scanf("%lf%lf%lf%lf%lf%lf",&fi[n][0],&fi[n][1],&fi[n][2],&fi[n][3],&fi[n][4],&fi[n][5]);
			}
		}
	}

	for(int i = 1; ; i++){
		scanf("%lf %lf",&x,&y);
		if(x==9999.9&&y==9999.9){
			break;
		}else{

			bool isP = false;
			for(int j = 0; j < n; j++){
				if(isContained(j,x,y)){
					printf("Point %d is contained in figure %d\n",i,j+1);
					isP = true;
				}
			}
			if(!isP){
				printf("Point %d is not contained in any figure\n",i);
			}
		}
	}
}