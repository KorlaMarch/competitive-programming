#include "stdio.h"
#include "string.h"
#include "algorithm"

#define MOD 1000000009

int t,k,n;
char s[3][1000005];
int len[3];
long long dyn[2][4][4][30];

long long getDyn(int i, int x, int y, int p){
	if(x>y) return 1;
	else return dyn[i][x][y][p];
}

int main(){
	scanf("%d",&t);
	for(k = 0; k < t; k++){
		scanf(" %s %s %s",s[0],s[1],s[2]);
		len[0] = strlen(s[0]);
		len[1] = strlen(s[1]);
		len[2] = strlen(s[2]);
		n = std::max(len[0],std::max(len[1],len[2]));
		for(int i = 0; i < 3; i++){
			for(int j = len[i]; j <= n; j++){
				s[i][j] = 0;
			}
		}

		//reset dyn
		for(int x = 0; x < 3; x++){
			for(int y = x; y < 3; y++){
				for(int p = 0; p < 26; p++){
					dyn[n%2][x][y][p] = 0;
				}
			}
			dyn[n%2][x][x][0] = 1;
		}

		for(int i = n-1; i >= 0; i--){
			for(int x = 2; x >= 0; x--){
				for(int y = x; y < 3; y++){
					for(int p = 26; p > 0; p--){
						dyn[i%2][x][y][p] = dyn[i%2][x][y][p+1];
						for(int j = x; j <= y; j++){
							if(s[j][i]=='?'||s[j][i]=='a'+p-1){
								dyn[i%2][x][y][p] = (dyn[i%2][x][y][p] + dyn[(i+1)%2][x][j][0]*getDyn(i%2,j+1,y,p+1))%MOD;
							}else{
								break;
							}
						}
					}
					//p = 0
					dyn[i%2][x][y][0] = dyn[i%2][x][y][1];
					for(int j = x; j <= y; j++){
						if(s[j][i]==0){
							dyn[i%2][x][y][0] = (dyn[i%2][x][y][0] + dyn[(i+1)%2][x][j][0]*getDyn(i%2,j+1,y,1))%MOD;
						}else{
							break;
						}
					}
				}
			}
		}
		printf("%lld\n",dyn[0][0][2][0]);                                                            
	}
}