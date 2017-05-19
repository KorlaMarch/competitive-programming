#include "stdio.h"
#include "queue"
#include "algorithm"
#include "vector"

typedef std::pair<int,int> PII;

struct Node{
	int loc,state,dis;
	Node(int _loc = 0, int _state = 0, int _dis = 0) : loc(_loc), state(_state), dis(_dis) {}
	bool operator()(Node a, Node b){
		return a.dis>b.dis;
	}
};

int r,c,k,sx,sy;
bool isV[105][105];
char mp[105][105];
char nodeC[105];
std::queue<PII> qu[2];
std::vector<PII> edge[105];
std::priority_queue<Node,std::vector<Node>,Node> pqu;
int minDis[50][33000];

int getNodeID(char c){
	if(c=='z'){
		return 1;
	}else if(c=='Z'){
		return 2;
	}else if('a'<=c&&c<'z'){
		return c-'a'+10;
	}else if('A'<=c&&c<'Z'){
		return c-'A'+30;
	}
	return 0;
}

void pushQu(int ind, int x, int y){
	if(x<0||y<0||x>=r||y>=c||mp[x][y]=='#'||isV[x][y]) return;
	qu[ind].push({x,y});
	isV[x][y] = true;
}

int main(){
	scanf("%d%d%d",&r,&c,&k);
	for(int i = 0; i < r; i++){
		scanf(" %s",mp[i]);
	}
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(mp[i][j]!='.'&&mp[i][j]!='?'){
				const int cid = getNodeID(mp[i][j]);
				nodeC[cid] = mp[i][j];
				//reset isV
				for(int x = 0; x < r; x++){
					for(int y = 0; y < c; y++){
						isV[x][y] = false;
					}
				}
				pushQu(0,i,j);
				for(int x = 0; !qu[x%2].empty(); x++){
					const int cind = x%2;
					while(!qu[cind].empty()){
						PII t = qu[cind].front();
						qu[cind].pop();

						int qid = getNodeID(mp[t.first][t.second]);
						if(qid&&qid!=cid){
							edge[cid].push_back({qid,x});
							edge[qid].push_back({cid,x});
						}else{
							pushQu(!cind,t.first,t.second-1);
							pushQu(!cind,t.first,t.second+1);
							pushQu(!cind,t.first-1,t.second);
							pushQu(!cind,t.first+1,t.second);
						}
					}
				}
			}
		}
	}

	//run dijkstar 
	pqu.push(Node(1,0,1));
	while(!pqu.empty()){
		Node t = pqu.top();
		pqu.pop();

		if(t.loc==2){
			printf("%d\n",t.dis-1);
			return 0;
		}

		for(PII pi : edge[t.loc]){
			Node newt;
			newt.loc = pi.first;
			newt.dis = t.dis+pi.second;
			if('a'<=nodeC[pi.first]&&nodeC[pi.first]<'z'){
				//key
				newt.state = t.state|(1<<(nodeC[pi.first]-'a'));
			}else if('A'<=nodeC[pi.first]&&nodeC[pi.first]<'Z'){
				//door
				if(t.state&(1<<(nodeC[pi.first]-'A'))){
					newt.state = t.state;
				}else continue;
			}else{
				newt.state = t.state;
			}

			if(minDis[newt.loc][newt.state]==0||newt.dis<minDis[newt.loc][newt.state]){
				minDis[newt.loc][newt.state] = newt.dis;
				pqu.push(newt);
			}
		}
	}
	printf("-1\n");
}