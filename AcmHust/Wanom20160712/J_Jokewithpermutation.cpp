#include "stdio.h"
#include "string.h"
#include "vector"

char s[105];
bool isCut[105];
bool isUse[105];
bool isH[105];
int len,n;
std::vector<int> numpos[10];
int stk[105];
int ptr; 

bool selectOne(int num){
	bool h[6] = {};
	if(num==0){
		for(int i = 0; i <= n; i++) isH[i] = false;
		ptr = 0;
		if(isCut[0]) isH[s[0]-'0'] = true;
		//check
		int i;
		/*printf("    %s\nCut:",s);
		for(i = 0; i < len; i++){
			printf("%d",isCut[i]);
		}
		printf("\nUSE:%d",isUse[0]);*/
		for(i = 1; i < len; i++){
			int nu = 10*(s[i-1]-'0')+(s[i]-'0');
			//printf("%d",isUse[i]);
			if(!isUse[i]&&(!isUse[i-1]||(i+1>=len||isUse[i+1]))){
				stk[ptr++] = i;
				isUse[i] = true;
				isCut[i] = true;
			}
			if(isCut[i]){
				if(isCut[i-1]) nu = s[i]-'0';
				if(isH[nu]){
					break;
				}else{
					isH[nu] = true;
				}
			}
		}
		//printf("\n");
		if(i!=len){
			for(ptr--;ptr>=0;ptr--){
				isCut[stk[ptr]] = false;
				isUse[stk[ptr]] = false;
			}
			return false;
		}
		//print
		for(int i = 0; i < len; i++){
			//printf("\nP %d : %d %d\n",i,isCut[i],isUse[i]);
			if(isCut[i]){
				if(i>0&&!isCut[i-1]){
					printf("%c%c ",s[i-1],s[i]);
				}else printf("%c ",s[i]);
			}
		}
		return true;
	}else{
		if(num>=5){
			for(int x : numpos[num]){
				//try to select
				bool check = true;
				isCut[x] = true;
				isUse[x] = true;
				for(int y : numpos[num]){
					if(x!=y){
						int nu = y>0?(s[y-1]-'0'):0;
						if(y>0&&10*nu+num<=n&&!h[nu]&&s[y-1]!=0){
							h[nu] = true;
							isCut[y] = true;
							isUse[y] = isUse[y-1] = true;
						}else{
							check = false;
							break;
						}
					}
				}
				for(int i = 1; 10*i+num<=n; i++){
					if(!h[i]) check = false;
				}
				if(check){
					//printf("select %d: %d\n",num,x);
					if(selectOne(num-1)) return true;
				}
				isCut[x] = false;
				isUse[x] = false;
				for(int y : numpos[num]){
					if(x!=y){
						int nu = y>0?(s[y-1]-'0'):0;
						if(y>0&&10*nu+num<=n&&s[y-1]!=0){
							h[nu] = false;
							isCut[y] = false;
							isUse[y] = isUse[y-1] = false;
						}
					}
				}
			}
		}else{
			for(int x : numpos[num]){
				if(!isUse[x]){
					//try to select
					isCut[x] = true;
					isUse[x] = true;
					//printf("select %d : %d\n",num,x);
					if(selectOne(num-1)) return true;
					isCut[x] = false;
					isUse[x] = false;
				}
			}
		}
	}
	//printf("RE %d\n",num);
	return false;
}

int main(){
	freopen("joke.in","r",stdin);
	freopen("joke.out","w+",stdout);
	scanf("%s",s);
	//find n
	len = strlen(s);
	if(len>9){
		n = (len-9)/2+9;
		//select 0
		for(int i = 0; i < len; i++){
			if(s[i]=='0'){
				isCut[i] = true;
				isUse[i] = isUse[i-1] = true;
			}
		}
		//printf("N = %d %d \n",n,len);
		for(int i = 0; i < len; i++){
			if(!isUse[i]) numpos[s[i]-'0'].push_back(i);
		}
		selectOne(9);
	}else{
		n = len;
		//this can easily solve with putting spacebar
		for(int i = 0; i < len; i++){
			printf("%c ",s[i]);
		}
	}
}