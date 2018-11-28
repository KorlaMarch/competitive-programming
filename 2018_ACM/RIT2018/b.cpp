#include "stdio.h"

int t;
int rx, ry, h;
int wx, wy, wl;
int n;
int ax[10005], ay[10005], bx[10005], by[10005];

int main(){
	scanf("%d", &t);
	for(int k = 0; k < t; k++){
		// getting inputs
		scanf("%d%d%d", &rx, &ry, &h);
		scanf("%d%d%d", &wx, &wy, &wl);
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d%d%d%d", &ax[i], &ay[i], &bx[i], &by[i]);
		}
		
		// bfs
	}

}
