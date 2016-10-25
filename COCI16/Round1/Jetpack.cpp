#include "stdio.h"
#include "vector"
#include "algorithm"

int n;
char s[10][100005];
int from[10][100005];
std::vector< std::pair<int,int> > oper;

int main(){
	scanf("%d",&n);
	for(int i = 9; i >= 0; i--){
		scanf(" %s",s[i]);
	}
	for(int i = 0; i < 10; i++){
		if(s[i][n-1]=='.'){
			from[i][n-1] = 0;
		}else{
			from[i][n-1] = -1;
		}
	}
	for(int i = n-2; i >= 0; i--){
		for(int j = 0; j < 10; j++){
			if(s[j][i]=='.'){
				if( (j==0||j==9) && from[j][i+1] != -1){
					from[j][i] = j;
				}else if(j<9&&from[j+1][i+1]!=-1){
					from[j][i] = j+1;
				}else if(j>0&&from[j-1][i+1]!=-1){
					from[j][i] = j-1;
				}else{
					from[j][i] = -1;
				}
			}else{
				from[j][i] = -1;
			}
		}
	}

	//find oper
	int cr = 0, co = 0, st = 0;
	for(int i = 0; i < n-1; i++){
		if(from[cr][i]>cr || (cr==9&&from[cr][i]==cr)){
			//pass
			if(co){
				co++;
			}else{
				st = i;
				co = 1;
			}
		}else{
			if(co){
				oper.push_back({st,co});
				co = 0;
			}
		}
		if(from[cr][i]==-1){
			printf("ERROR %d %d\n",i,cr);
			return 0;
		}
		cr = from[cr][i];
	}
	
	if(co){
		oper.push_back({st,co});
		co = 0;
	}

	printf("%d\n",oper.size());
	for(auto pi : oper){
		printf("%d %d\n",pi.first,pi.second);
	}

	return 0;
}