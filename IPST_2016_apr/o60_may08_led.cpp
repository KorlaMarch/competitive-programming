#include "stdio.h"
#include "map"
#include "algorithm"
#include "set"

typedef std::pair<int,int> PII;

int n;
PII pos[1000005];
int fen[3000005];
std::map<int,PII> lp1,lp2;
std::map<PII,int> ans;
std::set<PII> po;
std::vector<PII> rect1,rect2;
std::vector<int> path;
std::vector<PII> qsPos;

void addFen(int x, int v){
	x = std::lower_bound(path.begin(),path.end(),x)-path.begin()+1;
	for(; x <= path.size(); x += (x&-x)) fen[x] += v;
}

int getFen(int x){
	x = std::lower_bound(path.begin(),path.end(),x)-path.begin()+1;
	int v = 0;
	for(; x > 0; x -= (x&-x)) v += fen[x];
	return v;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&pos[i].first,&pos[i].second);
		po.insert(pos[i]);
		path.push_back(pos[i].second);
	}
	std::sort(pos,pos+n);
	for(int i = 0; i < n; i++){
		int ind = pos[i].first-pos[i].second;
		if(lp1.count(ind)){
			rect1.push_back(pos[i]);
			rect2.push_back(lp1[ind]);
		}
		lp1[ind] = pos[i];

		ind = pos[i].first+pos[i].second;
		if(lp2.count(ind)){
			PII a = {pos[i].first,lp2[ind].second};
			PII b = {lp2[ind].first,pos[i].second};
			if(po.count(a)==0||po.count(b)==0){
				rect1.push_back(a);
				rect2.push_back(b);
			}
		}
		lp2[ind] = pos[i];
	}

	for(int i = 0; i < rect1.size(); i++){
		rect1[i].first--;
		rect1[i].second--;
		qsPos.push_back(rect1[i]);
		qsPos.push_back(rect2[i]);
		qsPos.push_back({rect1[i].first,rect2[i].second});
		qsPos.push_back({rect2[i].first,rect1[i].second});

		path.push_back(rect1[i].second);
		path.push_back(rect2[i].second);
	}
	//find qs
	std::sort(qsPos.begin(),qsPos.end());
	std::sort(path.begin(),path.end());

	int i = 0;
	for(PII pi : qsPos){
		while(i<n&&pos[i]<=pi){
			addFen(pos[i].second,1);
			i++;
		}
		ans[pi] = getFen(pi.second);
	}

	int count = 0;
	for(int i = 0; i < rect1.size(); i++){
		const int po = ans[rect1[i]]-ans[{rect1[i].first,rect2[i].second}]-ans[{rect2[i].first,rect1[i].second}]+ans[rect2[i]];
		if(po==0) count++;
	}
	printf("%d\n",count);
}