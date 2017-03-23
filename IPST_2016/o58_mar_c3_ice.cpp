#include "stdio.h"
#include "vector"
#include "algorithm"
#include "queue"

struct event{
	int si, no, ti;
	event(int _si = 0, int _no = 0, int _ti = 0) : si(_si), no(_no), ti(_ti) {}
	bool operator<(const event& rhs) const{
		if(si==rhs.si){
			return ti>rhs.ti;
		}else return si<rhs.si;
	}
};

typedef std::pair<int,int> PII;

int n,m,u,v,w;
int s[200005];
int t[200005];
bool isV[200005];
std::vector<PII> edge[200005];
std::priority_queue<event> qu;

int main(){
	scanf("%d%d",&n,&m);

	for(int i = 1; i <= n; i++){
		scanf(" %d",&s[i]);
		if(s[i]){
			qu.push(event(s[i],i,i));
			t[i] = i;
		}else t[i] = 0;
	}

	for(int i = 1; i <= m; i++){
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}

	while(!qu.empty()){
		event pi = qu.top();
		qu.pop();
		if(!isV[pi.no]){
			//printf("DO %d %d %d\n",pi.si,pi.no,pi.ti);
			isV[pi.no] = true;
			for(PII x : edge[pi.no]){
				if(pi.si-x.second>s[x.first]){
					s[x.first] = pi.si-x.second;
					t[x.first] = pi.ti;
					qu.push(event(s[x.first],x.first,t[x.first]));
				}else if(pi.si-x.second==s[x.first]&&pi.ti<t[x.first]){
					t[x.first] = pi.ti;
					qu.push(event(s[x.first],x.first,t[x.first]));
				}
			}
		}
	}

	for(int i = 1; i <= n; i++){
		printf("%d %d\n",t[i],s[i]);
	}
}