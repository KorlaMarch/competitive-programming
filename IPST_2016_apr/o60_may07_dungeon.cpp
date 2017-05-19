#include "stdio.h"
#include "algorithm"
#include "queue"
#include "vector"

typedef std::pair<int,int> PII;

int l,w,h,xs,ys,xg,yg,b,t,x,y;
char mp[1005][1005];
int minT[1005][1005];
int xt[5],yt[5],xt2[5],yt2[5];
std::priority_queue<std::pair<int,PII>,std::vector<std::pair<int,PII> >,std::greater<std::pair<int,PII> > > qu;

void pushQu(int x, int y, int t){
	if(x<=0||y<=0||x>w||y>h||mp[x][y]=='-') return;
	if(minT[x][y]==0||t<minT[x][y]){
		minT[x][y] = t;
		qu.push({t,{x,y}});
	}
}

int main(){
	scanf("%d",&l);
	for(int k = 0; k < l; k++){
		scanf("%d%d%d%d%d%d%d%d",&w,&h,&xs,&ys,&xg,&yg,&b,&t);
		//clear mp
		for(int i = 1; i <= w; i++){
			for(int j = 1; j <= h; j++){
				mp[i][j] = 0;
				minT[i][j] = 0;
			}
		}
		while(!qu.empty()) qu.pop();
		for(int i = 0; i < b; i++){
			scanf("%d%d",&x,&y);
			mp[x][y] = '-';
		}
		for(int i = 0; i < t; i++){
			scanf("%d%d%d%d",&xt2[i],&yt2[i],&xt[i],&yt[i]);
			mp[xt2[i]][yt2[i]] = 'A' + i;
			mp[xt[i]][yt[i]] = 'a' + i;
		}

		pushQu(xs,ys,1);

		while(!qu.empty()){
			int cuT = qu.top().first;
			PII pos = qu.top().second;
			qu.pop();
			if(cuT!=minT[pos.first][pos.second]) continue;

			if(pos.first==xg&&pos.second==yg){
				printf("%d\n",cuT-1);
				break;
			}

			if(mp[pos.first][pos.second]>='A'&&mp[pos.first][pos.second]<='Z'){
				//teleport
				const int ind = mp[pos.first][pos.second]-'A';
				pushQu(xt[ind],yt[ind],cuT);
			}else{
			// }else if(mp[pos.first][pos.second]>='a'&&mp[pos.first][pos.second]<='z'){
			// 	//teleport
			// 	const int ind = mp[pos.first][pos.second]-'a';
			// 	pushQu(xt2[ind],yt2[ind],cuT);
			// }
				pushQu(pos.first+1,pos.second,cuT+101);
				pushQu(pos.first-1,pos.second,cuT+101);
				pushQu(pos.first,pos.second+1,cuT+101);
				pushQu(pos.first,pos.second-1,cuT+101);

				pushQu(pos.first-1,pos.second-1,cuT+151);
				pushQu(pos.first-1,pos.second+1,cuT+151);
				pushQu(pos.first+1,pos.second-1,cuT+151);
				pushQu(pos.first+1,pos.second+1,cuT+151);
			}
		}
	}
}