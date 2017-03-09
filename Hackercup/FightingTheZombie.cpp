#include "stdio.h"
#include "algorithm"

int t,h,s;
double prob[21][21][405];
double mx;
char str[50];

int getNum(char str[], int& ptr){
	int num = 0;
	for(; str[ptr] >= '0' && str[ptr] <= '9'; ptr++){
		num *= 10;
		num += str[ptr]-'0';
	}
	return num;
}

int main(){
	//precompute
	for(int i = 1; i <= 20; i++){
		prob[i][0][0] = 1.0;
		for(int j = 1; j <= 20; j++){
			for(int x = 400; x >= 0; x--){
				prob[i][j][x] = 0;
				for(int y = 1; y <= i && x-y>=0; y++){
					prob[i][j][x] += prob[i][j-1][x-y]/i;
				}
			}
		}
	}
	//presum
	for(int i = 1; i <= 20; i++){
		for(int j = 1; j <= 20; j++){
			for(int x = 399; x >= 0; x--){
				prob[i][j][x] += prob[i][j][x+1];
			}
		}
	}

	scanf("%d",&t);
	for(int k = 1; k <= t; k++){
		scanf("%d%d",&h,&s);
		mx = 0.0;
		for(int i = 0; i < s; i++){
			scanf(" %s",str);
			int ti, di, zi=0, pt=0;
			ti = getNum(str,pt);
			pt++;
			di = getNum(str,pt);
			if(str[pt]=='+'){
				zi = getNum(str,++pt);
			}else if(str[pt]=='-'){
				zi = -getNum(str,++pt);
			}

			if(h-zi<=0) mx = 1.0;
			else if(h-zi<=400) mx = std::max(mx, prob[di][ti][h-zi]);
		}
		printf("Case #%d: %.6f\n",k,mx);
	}
}