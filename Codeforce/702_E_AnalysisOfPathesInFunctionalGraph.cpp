#include "stdio.h"
#include "algorithm"

int n;
int f[100005];
int w[100005];
int jmp[100005][41];
int min[100005][41];
long long sum[100005][41];
long long k;
long long si;
int mi;

int main(){
	scanf("%d %I64d",&n,&k);
	for(int i = 0; i < n; i++){
		scanf("%d",&f[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&w[i]);
		jmp[i][0] = f[i];
		sum[i][0] = w[i];
		min[i][0] = w[i];
	}
	long long dis = 2;
	for(int i = 1; dis <= k; dis = (dis<<1), i++){
		for(int j = 0; j < n; j++){
			jmp[j][i] = jmp[ jmp[j][i-1] ][i-1];
			sum[j][i] = sum[j][i-1]+sum[ jmp[j][i-1] ][i-1];
			min[j][i] = std::min(min[j][i-1],min[ jmp[j][i-1] ][i-1]);
		}
	}
	for(int i = 0; i < n; i++){
		long long tk = k;
		si = 0;
		mi = 1<<30;
		int cp = i;
		for(int j = 0; tk; tk = (tk>>1), j++){
			if(tk%2==1){
				si += sum[cp][j];
				mi = std::min(mi,min[cp][j]);
				cp = jmp[cp][j];
			}
		}
		printf("%I64d %d\n",si,mi);
	}

}