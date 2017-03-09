#include "cliclib.h"
#include "algorithm"
#include "vector"
//#include "stdio.h"

int n;
std::vector<int> num;
std::vector<std::vector<bool> > isWin;

void genNum3(int x, int lim){
	while(x<=lim){
		//printf("NUM %d\n",x);
		num.push_back(x);
		x *= 3;
	}
}

void genNum2(int x, int lim){
	while(x<=lim){
		genNum3(x,lim);
		x = (x<<1);
	}
}

bool checkW(int x, int y){
	if(x+y>=n) return false;
	else return isWin[x][std::lower_bound(num.begin(),num.end(),y)-num.begin()];
}

int main(){
	n = inicjuj();
	//scanf("%d",&n);
	genNum2(1,n);
	std::sort(num.begin(),num.end());
	isWin.assign(n,std::vector<bool>(num.size(),false));

	for(int i = n-1; i >= 0; i--){
		for(int j = num.size()-1; j >= 0; j--){
			if(i+num[j]<n){
				if(!checkW(i,2*num[j])||!checkW(i,3*num[j])||!checkW(i+num[j],1)){
					isWin[i][j] = true;
				}
			}
		}
	}

	//fprintf(stderr, "isWin : %s\n",isWin[0][0]?"yes":"no");

	int x = 0, y = 1, m;
	for(int i = 0; ; i++){
		if(i%2==0){
			//our move
			//fprintf(stderr, "Current Winning State : %s\n",checkW(x,y)?"yes":"no");
			if(!checkW(x+y,1)||x+y>=n){
				m = 1;
			}else if(!checkW(x,2*y)){
				m = 2;
			}else{
				m = 3;
			}
			alojzy(m);
			//if(x+y>=n) fprintf(stderr, "Our Program is forced to pass\n");
		}else{
			//bot move
			m = bajtazar();
		}
		if(m==1){
			x += y;
			y = 1;
		}else if(m==2){
			y *= 2;
		}else{
			y *= 3;
		}

		if(x>=n) break;
	}

}