#include "stdio.h"
#include "algorithm"

int len,sum,x,y;
char s[100005];

int findZero(int p){
	int co = 0;
	while(p<len&&s[p]==0){
		p++,co++;
	}
	return co;
}

int delOne(int num, bool isP){
	//printf("%d %d\n",num,isP);
	for(int i = len-1; i >= 0; i--){
		if(s[i]%3==num){
			if(i==0){
				int re = findZero(i+1);
				if(isP){
					for(int j = re+1; j < len; j++){
						putchar(s[j]+'0');
					}
					if(re+1>=len) putchar('0');
				}
				return std::min(len-1,1+re);
			}else{
				if(isP){
					for(int j = 0; j < len; j++){
						if(i!=j){
							putchar(s[j]+'0');
						}
					}
				}
				return 1;
			}
		}
	}
	return len;
}

int delTwo(int num, bool isP){
	//printf("%d %d\n",num,isP);
	int x,y;
	for(x = len-1; x >= 0; x--){
		if(s[x]%3==num) break;
	}
	for(y = x-1; y >= 0; y--){
		if(s[y]%3==num) break;
	}
	//printf("%d %d\n",x,y);

	if(y<0) return len;
	else{
		int re = findZero(y+1);
		int re2 = findZero(x+1);
		if(y==0){
			if(x==re+1){
				re = re+re2+2;
				if(isP){
					for(int j = re; j < len; j++){
						putchar(s[j]+'0');
					}
					if(re>=len) putchar('0');
				}
				return std::min(len-1,re);
			}else{
				if(isP){
					for(int j = re+1; j < len; j++){
						if(j!=x) putchar(s[j]+'0');
					}
					if(re+1>=len) putchar('0');
				}
				return std::min(len-1,re+2);
			}
		}else{
			if(isP){
				for(int j = 0; j < len; j++){
					if(j!=x&&j!=y){
						putchar(s[j]+'0');
					}
				}
			}
			return 2;
		}
	}
}

int main(){
	scanf(" %s",s);
	for(len = 0; s[len]; len++){
		s[len] -= '0';
		sum += s[len];
	}
	sum %= 3;
	if(len==1&&sum!=0) printf("-1\n");
	else if(sum==0){
		for(int i = 0; i < len; i++){
			putchar(s[i]+'0');
		}
	}else if(sum==1){
		x = delOne(1,false);
		if(len!=2) y = delTwo(2,false);
		else y = len;

		if(x==len&&y==len) printf("-1\n");
		else if(y==len||(x<y)) delOne(1,true);
		else delTwo(2,true);

	}else if(sum==2){
		x = delOne(2,false);
		if(len!=2) y = delTwo(1,false);
		else y = len;

		if(x==len&&y==len) printf("-1\n");
		else if(y==len||(x<y)) delOne(2,true);
		else delTwo(1,true);
	}
}