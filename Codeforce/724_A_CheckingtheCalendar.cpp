#include "stdio.h"

char s1[30],s2[30];

int sToV(char s[]){
	if(s[0]=='m'){
		return 1;
	}else if(s[0]=='t'){
		if(s[1]=='u'){
			return 2;
		}else if(s[1]=='h'){
			return 4;
		}
	}else if(s[0]=='w'){
		return 3;
	}else if(s[0]=='f'){
		return 5;
	}else if(s[0]=='s'){
		if(s[1]=='a'){
			return 6;
		}else if(s[1]=='u'){
			return 0;
		}
	}
	printf("Error %s\n",s);
	return -1;
}

int nextD(int d, int nx){
	return (d+nx)%7;
}

int main(){
	int v1, v2;
	scanf(" %s %s", s1, s2);
	
	v1 = sToV(s1);
	v2 = sToV(s2);

	if(nextD(v1,28)==v2 || nextD(v1,30)==v2 || nextD(v1,31)==v2 ){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
}