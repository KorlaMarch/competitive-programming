#include<bits/stdc++.h>
using namespace std;

int t, n;
// c, (dx,dy)
set<pair<int, pair<int, int> > > s;
int px[2005], py[2005];


int main(){
	scanf("%d", &t);
	for(int k = 0; k < t; k++){
		s.clear();
		
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d %d", &px[i], &py[i]);
		}
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				int dx, dy, c;
				dx = px[j]-px[i];
				dy = py[j]-py[i];
				
				int gc = __gcd(dx, dy);
				
				if(gc!=0){
					dx /= gc;
					dy /= gc;
				}
				
				if(dx < 0) {
					dx = -dx;
					dy = -dy;
				}
				
				if(dx == 0 && dy < 0) {
					dy = -dy;
				}
				
				if(!dx&&!dy){
					continue;		
				}
				
				c = dx*py[i] - dy*px[i];
				
				s.insert({c, {dx, dy}});
				//printf("Insert %d %d : %d %d %d\n", i,j,c,dx,dy);
			}
		}
		printf("%d\n", s.size());
	}
	return 0;
}
