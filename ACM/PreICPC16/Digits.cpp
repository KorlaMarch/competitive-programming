#include "stdio.h"
#include "string.h"

char s[1005],ans[1005];
int y,di,maxF,minF,len;
bool isF[11];

int main(){
	scanf(" %s %d",s,&y);
	len = strlen(s);
	for(int i = 0; i < y; i++){
		scanf("%d",&di);
		isF[di] = true;
	}
	minF = -1;
	maxF = -1;
	for(int i = 0; i < 10; i++){
		if(!isF[i]){
			if(minF==-1) minF = i;
			maxF = i;
		}
	}

	if(minF==-1){
		printf("impossible\n");
		printf("impossible\n");
		return 0;
	}

	//max
	bool isC = false;
	bool isE = false;
	for(int i = 0; s[i]; i++){
		if(isC){
			ans[i] = maxF+'0';
		}else if(isF[s[i]-'0']){
			int j;
			isE = true;
			for(j = s[i]-'0'; j >= 0; j--){
				if(!isF[j]){
					ans[i] = j+'0';
					break;
				}
			}
			if((i==0&&ans[i]=='0')||j<0){
				break;
			}
			
			isC = true;
		}else{
			ans[i] = s[i];
		}
	}
	ans[len] = '\0';
	if(isC||!isE){
		printf("%s\n",ans);
	}else{

		if(len==1||maxF<=0){
			printf("impossible\n");
		}else{
			for(int i = 1; i < len; i++){
				printf("%d",maxF);
			}
			printf("\n");
		}
	}


	//min
	isC = false;
	isE = false;
	for(int i = 0; s[i]; i++){
		if(isC){
			ans[i] = minF+'0';
		}else if(isF[s[i]-'0']){
			int j;
			isE = true;
			for(j = s[i]-'0'; j < 10; j++){
				if(!isF[j]){
					ans[i] = j+'0';
					break;
				}
			}
			if(j>=10){
				break;
			}
			isC = true;
		}else{
			ans[i] = s[i];
		}
	}

	ans[len] = '\0';

	if(isC||!isE){
		printf("%s\n",ans);
	}else{
		int minF1 = 0;
		for(int i = 1; i < 10; i++){
			if(!isF[i]){
				minF1 = i;
				break;
			}
		}
		if(minF1<=0){
			printf("impossible\n");
		}else{
			printf("%d",minF1);
			for(int i = 0; i < len; i++){
				printf("%d",minF);
			}
			printf("\n");
		}
	}

}