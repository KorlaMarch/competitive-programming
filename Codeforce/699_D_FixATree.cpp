#include "stdio.h"

int n,co,rc,frc;
int a[200005];
int isV[200005];
void fixCy(int x, int o){
	isV[x] = o;
	if(x!=a[x]){
		if(isV[a[x]]==o){
			//printf("FIND CY %d\n",x);
			a[x] = -1;
		}else if(!isV[a[x]]){
			fixCy(a[x],o);
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		if(i==a[i]){
			rc++;
			frc = i;
		}
	}
	//get rid of cycle
	for(int i = 1; i <= n; i++){
		if(!isV[i]){
			fixCy(i,i);
		}
	}

	if(rc==0){
		frc = 0;
		for(int i = 1; i <= n; i++){
			if(a[i]==-1){
				if(frc==0){
					frc = i;
				}
				a[i] = frc;
				co++;
			}
		}
	}else{
		for(int i = 1; i <= n; i++){
			if(i!=frc){
				if(i==a[i]||a[i]==-1){
					co++;
					a[i] = frc;
				}
			}
		}
	}
	printf("%d\n",co);
	for(int i = 1; i <= n; i++){
		printf("%d ",a[i]);
	}
}