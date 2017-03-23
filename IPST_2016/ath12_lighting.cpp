#include "stdio.h"
#include "set"

int t,m,n;
char s[40][40];
std::set<int> edge[1000];
bool isV[1000];

bool augment(int x){
	if(x==902){
		return true;
	}
	isV[x] = true;

	for(auto it = edge[x].begin(); it != edge[x].end(); it++){
		if(!isV[*it]){
			if(augment(*it)){
				edge[*it].insert(x);
				edge[x].erase(it);
				return true;
			}
		}
	}

	return false;
}

void printEdge(int x){
	printf("%d : ", x);
	for(int i : edge[x]){
		printf("%d ",i);
	}
	printf("\n");
}

int main(){
	scanf("%d",&t);
	for(int k = 0; k < t; k++){
		for(int i = 0; i <= 902; i++){
			edge[i].clear();
		}
		scanf("%d%d",&m,&n);
		for(int i = 0; i < m; i++){
			scanf(" %s",s[i]);
		}
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(s[i][j]=='x'){
					if(i>0&&s[i-1][j]=='.') s[i-1][j] = '*';
					if(i+1<m&&s[i+1][j]=='.') s[i+1][j] = '*';
					if(j>0&&s[i][j-1]=='.') s[i][j-1] = '*';
					if(j+1<n&&s[i][j+1]=='.') s[i][j+1] = '*';
				}
			}
		}
		int co = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(s[i][j]=='.'){
					if((i+j)%2==0){
						//connect to source
						edge[901].insert(30*i+j);
						if(i>0&&s[i-1][j]=='.') edge[30*i+j].insert(30*(i-1)+j);
						if(i+1<m&&s[i+1][j]=='.') edge[30*i+j].insert(30*(i+1)+j);
						if(j>0&&s[i][j-1]=='.') edge[30*i+j].insert(30*i+j-1);
						if(j+1<n&&s[i][j+1]=='.') edge[30*i+j].insert(30*i+j+1);

					}else{
						//connect to sink
						edge[30*i+j].insert(902);
					}
				}else if(s[i][j]=='*'){
					co++;
				}
			}
		}
		
		for(int i = 0; i <= 902; i++){
			isV[i] = false;
		}
		for(; augment(901); co++){
			for(int i = 0; i <= 902; i++){
				isV[i] = false;
			}
		}
		printf("%d\n",co);
	}
}