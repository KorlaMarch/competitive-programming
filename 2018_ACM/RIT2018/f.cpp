#include<bits/stdc++.h>
using namespace std;

int srt[5][1000010], n;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		memset(srt, 0, sizeof srt);
		scanf("%d",&n) ;
		for(int i=0;i<n;i++){
			int x, y ;
			scanf("%d%d",&x,&y) ;
			srt[0][i] = x;
			srt[1][i] = y;
			srt[2][i] = x+y;
			srt[3][i] = x-y;			
		}
		bool ok = 1 ;
		for(int i = 0; i< 4 ; i++) {
			sort(srt[i], srt[i] + n) ;
			for(int j = 0; j < (n - 1); j++){
				ok = ok & !(srt[i][j] == srt[i][j+1]);
			}
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0; 
}

