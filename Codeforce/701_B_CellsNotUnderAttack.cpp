#include "stdio.h"

int n,m,x,y;
bool isR[100005];
bool isC[100005];
int ar,ac;
long long underAtt;
int main(){
	scanf("%d%d",&n,&m);
	ar = ac = n;
	for(int i = 0; i < m; i++){
		scanf("%d%d",&x,&y);
		if(!isR[x]){
			underAtt += ac;
			ar--;
			isR[x] = true;
		}
		if(!isC[y]){
			underAtt += ar;
			ac--;
			isC[y] = true;
		}
		printf("%I64d\n",(long long)n*n-underAtt);
	}

}