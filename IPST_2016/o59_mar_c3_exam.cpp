#include "stdio.h"
#include "vector"
#include "map"
#include "math.h"
#include "algorithm"

struct Query{
	int s,t;
	int id;
	Query(int _s = 0, int _t = 0, int _id = 0) : s(_s), t(_t), id(_id) { }
};

bool cmp(Query a, Query b){
	return a.t < b.t;
}

int n,m,sq,csum,k;
int a[50005];
Query tmp;
std::vector<Query> qu[300];
std::vector<int> ans;
std::map<int,int> label;
int mp[50005];

void addPoint(int x){
	mp[x]++;
	if(mp[x]!=1) csum++;
}

void remPoint(int x){
	mp[x]--;
	if(mp[x]!=0) csum--;
}

int main(){
	scanf("%d",&n);
	sq = (int)sqrt(n);
	k = 1;
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
		//re-label
		if(label[a[i]]==0){
			label[a[i]] = k;
			a[i] = k;
			k++;
		}else a[i] = label[a[i]];
	}

	scanf("%d",&m);
	ans.resize(m);
	for(int i = 0; i < m; i++){
		scanf("%d%d",&tmp.s,&tmp.t);
		tmp.id = i;
		qu[tmp.s/sq].push_back(tmp);
	}
	for(int i = 0; i < 300; i++){
		if(!qu[i].empty()) std::sort(qu[i].begin(),qu[i].end(),cmp);
	}
	for(int i = 0; i < 300; i++){
		if(!qu[i].empty()){
			//do first
			csum = 0;
			auto it = qu[i].begin();
			int x=it->s,y=it->t;
			for(int j = x; j <= y; j++){
				addPoint(a[j]);
			}
			ans[it->id] = csum;
			for(it++; it != qu[i].end(); it++){
				//update y
				while(y<it->t){
					y++;
					addPoint(a[y]);
				}
				//update x
				while(x<it->s){
					remPoint(a[x]);
					x++;
				}
				while(it->s<x){
					x--;
					addPoint(a[x]);
				}
				ans[it->id] = csum;
			}

			for(int j = x; j <= y; j++){
				remPoint(a[j]);
			}
		}
	}
	for(int i = 0; i < m; i++){
		printf("%d\n",ans[i]);
	}
}