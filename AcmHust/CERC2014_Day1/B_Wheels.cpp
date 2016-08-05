#include "stdio.h"
#include "vector"
#include "math.h"

long long sq(long long x){
	return x*x;
}

int t,n,k;
int x[1005],y[1005],r[1005];
long long be[1005],di[1005];
char d[1005];
bool isV[1005];
std::vector<int> edge[1005];

long long _gcd(long long  x, long long y){
	long long t;
	if(x<y){
		t = x;
		x = y;
		y = t;
	}
	while(x%y){
		t = x%y;
		x = y;
		y = t;
	}
	return y;
}

void rotate(int x){
	isV[x] = true;

	const int inv = d[x]==1?2:1;
	long long gcd;
	for(int i : edge[x]){
		if(!isV[i]){
			be[i] = be[x]*r[x];
			di[i] = di[x]*r[i];
			gcd = _gcd(be[i],di[i]);
			be[i] /= gcd;
			di[i] /= gcd;
			
			d[i] = inv;
			rotate(i);
		}
	}
}

int main(){
	scanf("%d",&t);
	for(int k = 0; k < t; k++){
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			d[i] = 0;
			edge[i].clear();
			isV[i] = false;
		}
		for(int i = 0; i < n; i++){
			scanf("%d%d%d",&x[i],&y[i],&r[i]);
			for(int j = 0; j < i; j++){
				if( sq(r[i]+r[j]) == sq(x[i]-x[j])+sq(y[i]-y[j]) ){
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}
		be[0] = 1, di[0] = 1, d[0] = 1;
		rotate(0);
		for(int i = 0; i < n; i++){
			if(d[i]==0) printf("not moving\n");
			else{
				if(di[i]==1){
					printf("%lld ",be[i]);
				}else{
					printf("%lld/%lld ",be[i],di[i]);
				}
				if(d[i]==1){
					printf("clockwise\n");
				}else{
					printf("counterclockwise\n");
				}
			}

		}
	}
}