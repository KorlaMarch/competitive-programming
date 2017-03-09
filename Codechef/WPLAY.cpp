#include "stdio.h"
#include "string"
#include "string.h"
#include "set"
#include "iostream"

bool recur(int turn, int dep, std::string& fe);
bool doMinimax(int turn);

int d,t,r,c,n;
std::set<std::string> dic;
char grid[20];
char str[20];
bool isUsed[20];

bool recur(int turn, int dep, std::string& fe){
	if(dep==n){
		if(dic.count(fe)){
			//recur next
			// printf("Find word :\n");
			// for(int i = 0; i < 26; i++){
			// 	printf("%c ",i+'A');
			// }
			// printf("\n");
			// for(int i = 0; i < 26; i++){
			// 	printf("%d ",fe[i]);
			// }
			// printf("\n");
			return doMinimax(turn+1);
		}else{
			//not found
			if(turn%2==0) return false;
			else return true;
		}
	}else if(isUsed[dep]){
		return recur(turn,dep+1,fe);
	}else{
		//select
		isUsed[dep] = true;
		fe[grid[dep]-'A']++;
		bool r = recur(turn,dep+1,fe);
		fe[grid[dep]-'A']--;
		isUsed[dep] = false;
		//r==1&&turn==0
		//r==0&&turn==1
		if(turn%2!=r) return r;
		//not select
		bool r2 = recur(turn,dep+1,fe);
		return r2;
	}
}

bool doMinimax(int turn){
	//printf("turn = %d\n",turn);
	std::string fe;
	fe.assign(26,0);
	if(turn%2==0){
		//look for max
		return recur(turn,0,fe);
		//return 0;
	}else{
		//look for min
		return recur(turn,0,fe);
		//return 1;
	}
}

int main(){
	scanf("%d",&d);
	std::string feq;
	for(int i = 0; i < d; i++){
		scanf(" %s",str);
		feq.assign(26,0);
		for(int j = 0; str[j]; j++){
			feq[str[j]-'A']++;
		}
		dic.insert(feq);
	}
	scanf("%d%d %d",&r,&c,&t);
	for(int k = 0; k < t; k++){
		for(int i = 0; i < r; i++){
			scanf(" %s", grid+i*c);
		}
		memset(isUsed,0,r*c);
		n = r*c;
		if(doMinimax(0)){
			printf("Alice\n");
		}else{
			printf("Bob\n");
		}
	}
}