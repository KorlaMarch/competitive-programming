#include "stdio.h"
#include "vector"
#include "stack"
#include "algorithm"
#include "string"
#include "queue"

#define INF 100000000
typedef std::pair<int,int> PII;

int n,m,u,v,ind;
std::vector<int> edge[10005];
std::vector<int> edgeSC[10005];
std::vector<int> redgeSC[10005];
std::vector<int> scc[10005];
std::vector<int> cedge[10005];
std::stack<int> st;
std::string word[10005];
std::string ans;
std::vector<int> topo;
int sccG[10005];
int inT[10005];
char isV[10005];
char inchar[10005];
// 0 = not visit
// 1 = on stack
// 2 = already end
char color[10005];
int mxlen[10005];
std::queue<PII> qu[2][26];

void tarjan(int x){
	//printf("Tar : %d %d\n",x,ind);
	inT[x] = ind;
	sccG[x] = ind;
	st.push(x);
	color[x] = 1;
	ind++;

	for(int i : edge[x]){
		//printf("Look %d %d\n",i,color[i]);
		if(color[i]==0){
			tarjan(i);
			sccG[x] = std::min(sccG[x],sccG[i]);
		}else if(color[i]==1){
			//it is on same scc
			sccG[x] = std::min(sccG[x],sccG[i]);
		}
	}

	if(sccG[x]==inT[x]){
		do{
			scc[inT[x]].push_back(st.top());
			color[st.top()] = 2;
			st.pop();
		}while(scc[inT[x]].back()!=x);
	}

	//printf("Return\n");
}


void topoSort(int x){
	isV[x] = 1;
	for(int i : edgeSC[x]){
		if(!isV[i]) topoSort(i);
	}
	topo.push_back(x);
}

void solve(int start, int end){
	topoSort(start);
	std::reverse(topo.begin(),topo.end());

	//find max size of each vertex
	mxlen[start] = word[start].size();
	for(int i = 1; i < topo.size(); i++){
		const int x = topo[i];
		mxlen[x] = 0;
		for(int y : redgeSC[x]){
			if(isV[y]) mxlen[x] = std::max(mxlen[x],mxlen[y]);
		}
		mxlen[x] += word[x].size();
	}

	//printf("MAX %d\n",mxlen[end]);

	//make new clean graph
	isV[end] = 2;
	for(int i = topo.size()-1; i >= 0; i--){
		const int x = topo[i];
		if(x!=end){
			for(int y : edgeSC[x]){
				if(isV[y]==2&&mxlen[y]==mxlen[x]+word[y].size()){
					//printf("\tClean %d %d\n",x,y);
					cedge[x].push_back(y);
					isV[x] = 2;
				}
			}
		}
	}

	//ans.assign(mxlen[end],'A');
	//BFS
	qu[0][word[start][0]-'A'].push({start,0});
	for(int i = 0; i < mxlen[end]; i++){
		const int ind = i%2;
		for(int j = 0; j < 26; j++){
			while(!qu[!ind][j].empty()) qu[!ind][j].pop();
		}
		for(int j = 0; j < 26; j++){
			if(!qu[ind][j].empty()){
				ans.push_back(j+'A');
				while(!qu[ind][j].empty()){
					PII pi = qu[ind][j].front();
					//printf("GET %d %d\n",pi.first,pi.second);
					qu[ind][j].pop();
					if(word[pi.first][pi.second]!='-'){
						word[pi.first][pi.second] = '-';
						if(pi.second+1<word[pi.first].size()){
							qu[!ind][word[pi.first][pi.second+1]-'A'].push({pi.first,pi.second+1});
						}else{
							//move to next 
							for(int x : cedge[pi.first]){
								qu[!ind][word[x][0]-'A'].push({x,0});
							}
						}
					}
				} 
				break;
			}
		}
	}
}

int main(){
	scanf("%d%d %s",&n,&m,inchar);
	for(int i = 0; i < m; i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
	}

	ind = 1;
	//scc
	for(int i = 1; i <= n; i++){
		//printf("loop : %d\n",i);
		if(color[i]==0) tarjan(i);
	}

	//do grouping in scc
	for(int i = 1; i < ind; i++){
		if(!scc[i].empty()){
			for(int j : scc[i]){
				word[i].push_back(inchar[j-1]);
				sccG[j] = i;
			}
			std::sort(word[i].begin(),word[i].end());
		}
	}
	for(int i = 1; i < ind; i++){
		if(!scc[i].empty()){
			for(int j : scc[i]){
				//printf("%d ",j);
				for(int k : edge[j]){
					//not self loop
					if(i!=sccG[k]){
						edgeSC[i].push_back(sccG[k]);
						redgeSC[sccG[k]].push_back(i);
					}
				}
			}
			//printf("\nWord %d : %s\n",i,word[i].c_str());
		}
	}

	solve(sccG[1],sccG[n]);

	printf("%s\n",ans.c_str());
}