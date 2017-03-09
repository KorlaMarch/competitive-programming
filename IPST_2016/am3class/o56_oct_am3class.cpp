#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int w,h,dc;
double contrast;
double sumA,sumB;
double avdA,avdB;
double avgR,avgG,avgB;
int r[105][105],g[105][105],b[105][105];

int sq(int n){
	return n*n;
}

int main(){
	scanf("%d%d",&w,&h);
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			scanf("%d%d%d",&r[i][j],&g[i][j],&b[i][j]);
			avgR += r[i][j];
			avgG += g[i][j];
			avgB += b[i][j];
		}
	}

	avgR /= w*h;
	avgG /= w*h;
	avgB /= w*h;
	
	for(int i = 1; i < h; i++){
		for(int j = 1; j < w; j++){
			int diff = 0;
			diff += abs(r[i][j]-r[i-1][j])+abs(g[i][j]-g[i-1][j])+abs(b[i][j]-b[i-1][j]);
			diff += abs(r[i][j]-r[i][j-1])+abs(g[i][j]-g[i][j-1])+abs(b[i][j]-b[i][j-1]);
			sumA += diff;
			if(diff<4) dc++;

			sumB += sqrt(sq(r[i][j]-r[i-1][j])+sq(g[i][j]-g[i-1][j])+sq(b[i][j]-b[i-1][j]));
			sumB += sqrt(sq(r[i][j]-r[i][j-1])+sq(g[i][j]-g[i][j-1])+sq(b[i][j]-b[i][j-1]));

			avdA += abs(r[i][j]-avgR)+abs(g[i][j]-avgG)+abs(b[i][j]-avgB);

			avdB += sqrt(sq(r[i][j]-avgR)+sq(g[i][j]-avgG)+sq(b[i][j]-avgB));
		}
	}
	//if(sqrt(avgR)+sq(avgG)+sq(avgB)>13000.0) printf("A\n");
	if(100.0*dc/(w*h)>12.0) printf("A\n");
	else if(sumA/(w*h)>=85.0) printf("3\n");
	else printf("M\n");
	// printf("A : %.6f\nB : %.6f\n",sumA/(w*h),sumB/(w*h));
	// printf("AD : %.6f\nBD : %.6f\n",avdA/(w*h),avdB/(w*h));
	// printf("BRIGHT : %.6f\n",sqrt(avgR)+sq(avgG)+sq(avgB));
	printf("DC : %.6f\n",100.0*dc/(w*h));
}