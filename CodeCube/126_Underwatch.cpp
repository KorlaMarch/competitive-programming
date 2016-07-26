#include "stdio.h"

char time[3][15];
int n;

int countPoten(int of, int to){
	int co = 0;

	// 0
	if(0<=to&&
		time[1][of+1]==' '){
		co++;
	}

	// 1
	if(1<=to&&
		time[0][of]==' '&&time[0][of+1]==' '&&time[0][of+2]==' '&&
		time[1][of]==' '&&time[1][of+1]==' '&&
		time[2][of]==' '&&time[2][of+1]==' '){
		co++;
	}

	// 2
	if(2<=to&&time[1][of]==' '&&time[2][of+2]==' '){
		co++;
	}

	// 3
	if(3<=to&&time[1][of]==' '&&time[2][of]==' '){
		co++;
	}

	// 4
	if(4<=to&&
		time[0][of]==' '&&time[0][of+1]==' '&&time[0][of+2]==' '&&
		time[2][of]==' '&&time[2][of+1]==' '){
		co++;
	}

	// 5
	if(5<=to&&time[1][of+2]==' '&&time[2][of]==' '){
		co++;
	}

	// 6
	if(6<=to&&time[1][of+2]==' '){
		co++;
	}

	// 7
	if(7<=to&&
		time[1][of]==' '&&time[1][of+1]==' '&&
		time[2][of]==' '&&time[2][of+1]==' '){
		co++;
	}

	// 8
	if(8<=to){
		co++;
	}

	// 9
	if(9<=to&&time[2][of]==' '){
		co++;
	}

	return co;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < 3; i++){
		scanf(" %[^\n]",time[i]);
		int j;
		for(j = 0; time[i][j]; j++);
		for(; j < 15; j++) time[i][j] = ' ';
	}
	printf("%d\n",countPoten(0,1)*countPoten(3,9)*countPoten(7,5)*countPoten(10,9)+
		(countPoten(0,2)-countPoten(0,1))*countPoten(3,3)*countPoten(7,5)*countPoten(10,9));
}