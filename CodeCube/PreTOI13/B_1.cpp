#include "stdio.h"

int n,t,a,ans,sum;
int pc[100005][3];
bool canDo[20][20][20];
int minW[20][20][20];

void addTo(int a, int b, int c){
	if(!canDo[a][b][c]){
		for(int i = 0; i+a < 20; i++){
			for(int j = 0; j+b < 15; j++){
				for(int k = 0; k+c < 10; k++){
					if(canDo[i][j][k]){
						canDo[i+a][j+b][k+c] = true;
					}
				}
			}
		}
	}
}

void addTo2(int a, int b, int c, int ti){
	if(!canDo[a][b][c]||ti<minW[a][b][c]){
		canDo[a][b][c] = true;
		minW[a][b][c] = ti;
		for(int i = 0; i+a < 20; i++){
			for(int j = 0; j+b < 15; j++){
				for(int k = 0; k+c < 10; k++){
					if(canDo[i][j][k]&&(!canDo[i+a][j+b][k+c]||ti+minW[i][j][k]<minW[i+a][j+b][k+c])){
						canDo[i+a][j+b][k+c] = true;
						minW[i+a][j+b][k+c] = ti+minW[i][j][k];
					}
				}
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&t);
	canDo[0][0][0] = true;
	minW[0][0][0] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d",&a);
		while(a%2==0){
			a /= 2;
			pc[i][0]++;
		}
		while(a%3==0){
			a /= 3;
			pc[i][1]++;
		}
		while(a%5==0){
			a /= 5;
			pc[i][2]++;
		}

		if(canDo[pc[i][0]][pc[i][1]][pc[i][2]]){
			sum += minW[pc[i][0]][pc[i][1]][pc[i][2]];
			ans++;
		}

		if(pc[i][0]!=0||pc[i][1]!=0||pc[i][2]!=0){
			if(t==1){
				for(int mul = 1; pc[i][0]*mul<20&&pc[i][1]*mul<15&&pc[i][2]*mul<10; mul++){
					addTo(pc[i][0]*mul,pc[i][1]*mul,pc[i][2]*mul);
				}
			}else{
				for(int mul = 1; pc[i][0]*mul<20&&pc[i][1]*mul<15&&pc[i][2]*mul<10; mul++){
					addTo2(pc[i][0]*mul,pc[i][1]*mul,pc[i][2]*mul,mul);
				}
			}
		}
	}
	if(t==1){
		printf("%d\n",ans);
	}else{
		printf("%d %d\n",ans,sum);
	}
}