#include "stdio.h"
#include "set"
#include "algorithm"

int n;
char s[35][35];
//source = 901
//sink = 902
std::set<int> edge[1000];
bool isV[1000];

bool augment(int x){
	if(x==902) return true;
	isV[x] = true;
	for(auto it = edge[x].begin(); it != edge[x].end(); it++){
		if(!isV[*it]){
			if(augment(*it)){
				//change edge
				//printf("found %d : %d %d => %d %d\n",(x/30+x%30)%2,x/30+1,x%30+1,(*it)/30+1,(*it)%30+1);
				edge[*it].insert(x);
				edge[x].erase(it);
				return true;
			}
		}
	}
	return false;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf(" %s",s[i]);
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(s[i][j]=='#'){
				if((i+j)%2==0){
					//connect to source
					edge[901].insert(30*i+j);
					if(i>0&&s[i-1][j]=='#') edge[30*i+j].insert(30*(i-1)+j);
					if(i+1<n&&s[i+1][j]=='#') edge[30*i+j].insert(30*(i+1)+j);
					if(j>0&&s[i][j-1]=='#') edge[30*i+j].insert(30*i+j-1);
					if(j+1<n&&s[i][j+1]=='#') edge[30*i+j].insert(30*i+j+1);
				}else{
					//connect to sink
					edge[30*i+j].insert(902);
				}
			}
		}
	}
	int co;
	for(co = 0; augment(901); co++){
		for(int i = 0; i <= 902; i++){
			isV[i] = false;	
		}
	}
	if(co==0){
		printf("no solution\n");
	}else{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(s[i][j]=='#'&&(i+j)%2){
					const int ind = 30*i+j;
					for(auto it = edge[ind].begin(); it != edge[ind].end(); it++){
						if(*it!=902){
							printf("%d %d %d %d\n",i+1,j+1,(*it)/30+1,(*it)%30+1);
						}
					}
				}
			}
		}
	}
}