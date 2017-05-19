#include "stdio.h"
#include "vector"
#include "algorithm"
#include "stdlib.h"

#define INF 100000000007LL
typedef std::pair<long long ,long long> PII;

int n,m,q,ai,bi,li,co,bigCo;
std::vector<PII> edge[100005];
std::vector<PII> comEdge[200005];
bool isV[200005];
int beg[200005];
long long suml[200005];
int par[100005];
long long member[100005];
long long dis[105][105];

int getBeg(int x, int o){
	for(PII pi : edge[x]){
		if(pi.first!=o&&edge[pi.first].size()<=2){
			return getBeg(pi.first,x);
		}
	}
	return x;
}

int callen(int x, int o, long long len, int id){
	isV[x] = true;
	member[x] = len;
	par[x] = id;
	//printf("%d -> (%d,%d)\n",x,id,len);
	for(PII pi : edge[x]){
		if(pi.first!=o&&!isV[pi.first]){
			if(edge[pi.first].size()<=2){
				return callen(pi.first,x,len+pi.second,id);
			}
		}
	}
	suml[id] = len;
	return x;
}

void addEdge(int x, int id){
	for(PII pi : edge[x]){
		if(edge[pi.first].size()>2){
			comEdge[id].push_back({pi.first,pi.second});
			//printf("Edge(%d) %d -> %d : %d\n",comEdge[id].size()-1,id,pi.first,pi.second);
			comEdge[pi.first].push_back({id,pi.second});
		}
	}
}

void makeCom(int x, int id){
	beg[id] = getBeg(x,0);

	int end = callen(beg[id],0,0,id);
	//connent to other node
	//printf("BEG %d %d\n",beg[id],end);
	if(beg[id]==end){
		addEdge(beg[id],id);
	}else{
		//begin
		if(edge[beg[id]].size()==1){
			comEdge[id].push_back({0,INF});
		}else{
			addEdge(beg[id],id);
		}
		//end
		addEdge(end,id);
	}
	comEdge[id].resize(2,{0,INF});
	if(comEdge[id][0].first!=0&&comEdge[id][1].first!=0){
		const long long w = comEdge[id][0].second + comEdge[id][1].second + suml[id];
		if(w<dis[par[comEdge[id][0].first]][par[comEdge[id][1].first]]){
			dis[par[comEdge[id][0].first]][par[comEdge[id][1].first]] = w;
			dis[par[comEdge[id][1].first]][par[comEdge[id][0].first]] = w;
		}
	}
	//parlist.push_back(id);
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	co = n+1;
	bigCo = 1;
	int sumE = 0;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d",&ai,&bi,&li);
		sumE += li;
		edge[ai].push_back({bi,li});
		edge[bi].push_back({ai,li});
	}
	
	bool isCy = true;
	//check for special case
	for(int i = 1; i <= n; i++){
		if(edge[i].size()!=2){
			isCy = false;
			break;
		}
	}
	
	if(isCy){
		//special case
		callen(1,0,0,0);
		int s,t;
		for(int i = 0; i < q; i++){
			scanf("%d%d",&s,&t);
			int ans = abs(member[s]-member[t]);
			printf("%d\n",std::min(ans,sumE-ans));
		}
	}else{
		//make com Edge
		for(int i = 1; i <= n; i++){
			if(edge[i].size()>2) par[i] = bigCo++;
		}
		for(int i = 1; i < bigCo; i++){
			for(int j = 1; j < bigCo; j++){
				dis[i][j] = INF;
			}
			dis[i][i] = 0;
		}

		for(int i = 1; i <= n; i++){
			if(!isV[i]&&edge[i].size()==2){
				makeCom(i,co++);
			}
		}
		for(int i = 1; i <= n; i++){
			if(par[i]<=n){
				//printf("PAR %d : %d\n",i,par[i]);
				//parlist.push_back(i);
				for(PII pi : edge[i]){
					if(par[pi.first]<=n){
						dis[par[i]][par[pi.first]] = std::min(dis[par[i]][par[pi.first]],pi.second);
					}
				}
			}
		}

		if(bigCo==1) return -1;
		// all pair shortest path
		for(int v = 1; v < bigCo; v++){
			for(int i = 1; i < bigCo; i++){
				for(int j = 1; j < bigCo; j++){
					if(dis[i][v]+dis[v][j]<dis[i][j]){
						dis[i][j] = dis[i][v]+dis[v][j];
					}
				}
			}
		}

		// for(int i = 1; i < bigCo; i++){
		// 	for(int j = 1; j < bigCo; j++){
		// 		printf("D %d %d : %d\n",i,j,dis[i][j]);
		// 	}
		// }

		int s,t;
		for(int i = 0; i < q; i++){
			scanf("%d%d",&s,&t);
			//find min
			long long mn = INF;
			if(par[s]==par[t]){
				mn = std::min(mn,llabs(member[s]-member[t]));
			}
			if(par[s]<=n&&par[t]<=n){
				mn = std::min(mn,dis[par[s]][par[t]]);
			}else if(par[s]<=n){
				if(comEdge[par[t]][0].first!=0){
					mn = std::min(mn,member[t]+comEdge[par[t]][0].second+dis[par[s]][par[comEdge[par[t]][0].first]]);
				}
				if(comEdge[par[t]][1].first!=0){
					mn = std::min(mn,suml[par[t]]-member[t]+comEdge[par[t]][1].second+dis[par[s]][par[comEdge[par[t]][1].first]]);
				}
			}else if(par[t]<=n){
				if(comEdge[par[s]][0].first!=0){
					mn = std::min(mn,member[s]+comEdge[par[s]][0].second+dis[par[t]][par[comEdge[par[s]][0].first]]);
				}
				if(comEdge[par[s]][1].first!=0){
					mn = std::min(mn,suml[par[s]]-member[s]+comEdge[par[s]][1].second+dis[par[t]][par[comEdge[par[s]][1].first]]);
				}
			}else{
				long long a,b,c,d;
				a = b = c = d = INF;
				// 0 -> 0
				if(comEdge[par[s]][0].first!=0&&comEdge[par[t]][0].first!=0)
					a = member[t]+comEdge[par[t]][0].second+member[s]+comEdge[par[s]][0].second+
					dis[par[comEdge[par[s]][0].first]][par[comEdge[par[t]][0].first]];

				// 1 -> 0
				if(comEdge[par[s]][1].first!=0&&comEdge[par[t]][0].first!=0)
					b = member[t]+comEdge[par[t]][0].second+suml[par[s]]-member[s]+comEdge[par[s]][1].second+
					dis[par[comEdge[par[s]][1].first]][par[comEdge[par[t]][0].first]];

				// 0 -> 1
				if(comEdge[par[s]][0].first!=0&&comEdge[par[t]][1].first!=0)
					c = suml[par[t]]-member[t]+comEdge[par[t]][1].second+member[s]+comEdge[par[s]][0].second+
					dis[par[comEdge[par[s]][0].first]][par[comEdge[par[t]][1].first]];

				// 1 -> 1
				if(comEdge[par[s]][1].first!=0&&comEdge[par[t]][1].first!=0)
					d = suml[par[t]]-member[t]+comEdge[par[t]][1].second+suml[par[s]]-member[s]+comEdge[par[s]][1].second+
					dis[par[comEdge[par[s]][1].first]][par[comEdge[par[t]][1].first]];
				//printf("RE %d %d %d %d : %d\n",a,b,c,d,mn);
				mn = std::min(mn,std::min(std::min(a,b),std::min(c,d)));
			}
			printf("%I64d\n",mn);
		}
	}
}
