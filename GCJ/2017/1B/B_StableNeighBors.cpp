#include "stdio.h"
#include "algorithm"
#include "queue"

int t,n;
int r,o,y,g,b,v;

void printSwap(int x, char a, char b){
	for(int i = 0; i < x; i++){
		putchar(a);
		putchar(b);
	}
}

void printR(){
	putchar('R');
	if(g){
		printSwap(g,'G','R');
		g = 0;
	}
}

void printY(){
	putchar('Y');
	if(v){
		printSwap(v,'V','Y');
		v = 0;
	}
}

void printB(){
	putchar('B');
	if(o){
		printSwap(o,'O','B');
		o = 0;
	}
}

void printYB(int x){
	for(int i = 0; i < x; i++){
		printY();
		printB();
	}
}

void handleNor(){
	if(r==0){
		printYB(y);
	}else{
		for(int i = 0; i+1 < r; i++){
			printR();
			if(y>b){
				printY();
				y--;
			}else{
				printB();
				b--;
			}
		}
		printR();
		if(y==b){
			printYB(y);
		}else if(y>b){
			printYB(b);
			printY();
		}else{
			//b>y
			printB();
			printYB(y);
		}
	}
	printf("\n");
}

int main(){
	scanf("%d",&t);
	for(int te = 1; te <= t; te++){
		scanf("%d %d%d%d%d%d%d",&n,&r,&o,&y,&g,&b,&v);
		//special case
		if(b+o==n){
			if(b!=o) printf("Case #%d: IMPOSSIBLE\n",te);
			else{
				printf("Case #%d: ",te);
				printSwap(b,'B','O');
				printf("\n");
			}
		}else if(r+g==n){
			if(r!=g) printf("Case #%d: IMPOSSIBLE\n",te);
			else{
				printf("Case #%d: ",te);
				printSwap(r,'R','G');
				printf("\n");
			}
		}else if(y+v==n){
			if(y!=v) printf("Case #%d: IMPOSSIBLE\n",te);
			else{
				printf("Case #%d: ",te);
				printSwap(y,'Y','V');
				printf("\n");
			}
		}else if((b<=o&&b&&o)||(r<=g&&r&&g)||(y<=v&&y&&v)){
			printf("Case #%d: IMPOSSIBLE\n",te);
		}else{
			b -= o;
			r -= g;
			y -= v;
			//printf("%d %d %d\n",b,r,y);
			int mx = std::max(r,std::max(y,b));
			if(2*mx>b+r+y){
				printf("Case #%d: IMPOSSIBLE\n",te);
			}else{
				printf("Case #%d: ",te);
				handleNor();
			}
		}
	}
}