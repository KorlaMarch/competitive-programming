#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define fi first
#define se second

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, lim, arr[505][505], cc[505][505], cnt = 1;
int vv[250050];
pair<int,int> mx[250050];
int par[250050] ;
vector<ii> srt ; 
vector<ii> sc[250050] ;

bool inside(int x, int y){
	return (x >= 0) && (x < n) && (y >= 0) && (y < n) ;
}

int rt(int a){
	if(par[a] == a) return a ;
	return par[a] = rt(par[a]); 
}

void unions(int a, int b) {
	if(rt(a) == rt(b)) return;
	int aa = rt(a), bb = rt(b);
	par[aa] = bb;
	if(mx[aa].fi > mx[bb].fi) mx[bb] = mx[aa];
	else if(mx[aa].fi == mx[bb].fi) mx[bb].se++ ;
}

void dfs(int x, int y){
	cc[x][y] = cnt ;
	sc[cnt].push_back(ii(x,y)) ; 
	for(int i=0 ;i< 4; i++){
		int  nx = x +dx[i] , ny = y + dy[i] ; 
		if(!inside(nx, ny) || cc[nx][ny] != 0) continue;
		if(arr[nx][ny] == arr[x][y]) dfs(nx, ny) ; 
	}
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
			}
		}
		for(int i = 0; i < 250010 ;i++){
			par[i] = i; 
			mx[i] = {0,0} ; 
			sc[i].clear();	
			vv[i] = 0 ;	
		}
		cnt = 1; 
		memset(cc, 0 ,sizeof cc) ;
		srt.clear();
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if(cc[i][j]) continue ;
				dfs(i,j) ;
				mx[cnt] = ii(arr[i][j], 1) ;
				vv[cnt] = arr[i][j] ; 
				cnt++ ;
			}
		}
		for(int i = 1; i < cnt; i++) par[i] = i, srt.push_back(ii(mx[i].fi, i));
		sort(srt.begin(), srt.end());
		reverse(srt.begin(), srt.end());
		int ptr = 0 ;
		int ans = 0 ;
		for(int i = 0; i < srt.size(); i++){
			int cur = srt[i].se, val = srt[i].fi;
			int thres = val - lim ; 
			//printf("%d %d %d:\n",cur,val,thres) ; 
			while((ptr < srt.size()) && (srt[ptr].fi > thres)){
				int curr = srt[ptr].se ;
				//printf("- %d %d\n",curr,srt[ptr].fi) ; 
				for(ii v : sc[curr]){
					int cx = v.fi, cy = v.se ; 
					for(int j = 0; j < 4; j++){
						int nx = cx + dx[j], ny = cy + dy[j];
						if(!inside(nx,ny)) continue ;
						if(arr[nx][ny] > thres) {
							unions(cc[nx][ny], curr);
						}
					}
				}
				ptr++;
			}
			int rc = rt(cur) ;
			//cout << mx[rc].fi << " " << mx[rc].se << endl ; 
			if((mx[rc].fi == vv[cur]) && (mx[rc].se == 1)) ans++ ; 
		}
		printf("%d\n", ans) ; 
	}
}



