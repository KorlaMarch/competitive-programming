#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define fi first
#define se second

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, lim, arr[505][505], cc[505][505];
pair<int,int> par[505][505], mx[505][505];
vector<pair<int, pair<int, int> > > srt ; 

bool inside(int x, int y){
	return (x >= 0) && (x < n) && (y >= 0) && (y < n) ;
}

ii rt(ii a){
	if(par[a.fi][a.se] == a) return a ;
	return par[a.fi][a.se] = rt(par[a.fi][a.se]); 
}

void unions(ii a, ii b) {
	if(rt(a) == rt(b)) return;
	ii aa = rt(a), bb = rt(b);
	par[aa.fi][aa.se] = bb;
	if(mx[aa.fi][aa.se].fi > mx[bb.fi][bb.se].fi) mx[bb.fi][bb.se] = mx[aa.fi][aa.se];
	else if(mx[aa.fi][aa.se].fi == mx[bb.fi][bb.se].fi) mx[bb.fi][bb.se].se++ ;
}

int main(){
	int t ; 
	scanf("%d", &t) ;
	while(t--){
		srt.clear(); 
		scanf("%d%d", &n, &lim);
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				scanf("%d", arr[i] + j) ;
				srt.push_back({arr[i][j], {i, j}});
				par[i][j] = ii(i,j);
				mx[i][j] = ii(arr[i][j], 1) ;
			}
		}
		
		sort(srt.begin(), srt.end());
		reverse(srt.begin(), srt.end());
		int ptr = 0 ;
		int ans = 0 ;
		for(int i = 0; i < srt.size() ; i++){
			int xx = srt[i].se.fi, yy = srt[i].se.se ;
			int val = srt[i].fi ;
			int thres = val - lim ;
			cout << val << " " << thres << " " << xx << " " << yy << endl;
			while((ptr < srt.size()) && (srt[ptr].fi > thres)){
				int cx = srt[ptr].se.fi, cy = srt[ptr].se.se ;
				for(int j = 0; j < 4; j++){
					int nx = cx + dx[j], ny = cy + dy[j];
					if(!inside(nx,ny)) continue ;
					if(arr[nx][ny] > thres) {
						unions(ii(cx,cy), ii(nx,ny));
					}
				}
				cout << cx << " " << cy << ":" << srt[ptr].fi << endl;
				ptr++;
			}
			ii rtt = rt(ii(xx,yy));
			if((mx[rtt.fi][rtt.se].fi == val) && (mx[rtt.fi][rtt.se].se == 1)){
				ans++;
			}
		}
		printf("%d\n", ans) ; 
	}
}



