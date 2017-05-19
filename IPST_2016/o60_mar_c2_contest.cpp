#include "stdio.h"
#include "algorithm"
#include "vector"

#define FSIZE 400005

int n,m,a,b,pt,mi;
int xi[FSIZE];
int fen[FSIZE];
int p[FSIZE];
int ans[100005];
std::vector<int> child[FSIZE];

void addFen(int i, int v){
	mi += v;
	for(; i < FSIZE; i+=(i&-i)){
		fen[i] += v;
	}
}

int getFen(int i){
	int v = 0;
	for(; i > 0; i -= (i&-i)){
		v += fen[i];
	}
	return v;
}

int getInd(int ind){
	int x=1,y=FSIZE-1;
	int m,lm=-1;
	while(x<=y){
		m = (x+y)/2;
		if(getFen(m)>=ind){
			y = m-1;
			lm = m;
		}else{
			x = m+1;
		}
	}
	return lm;
}

void recurSet(int x, int s){
	if(x<=n){
		if(xi[x]==s){
			ans[x] = s;
		}else{
			ans[x] = s+1;
		}
	}
	for(int i : child[x]){
		recurSet(i,s);
	}	
}

// void printFen(){
// 	for(int i = 1; i < 10; i++){
// 		printf("%d ",getFen(i));
// 	}
// 	printf("\n");
// }

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d",&xi[i]);
		addFen(i,1);
		p[i] = i;
	}
	pt = n+1;
	for(int i = 0; i < m; i++){
		scanf("%d%d",&a,&b);
		int cind = 1;
		int rind = 1;
		int lim = mi;
		//printf("Round %d\n",i);
		//printFen();
		while(1){
			//group pt
			//printf("group %d\n",pt);

			for(int k = 0; k < b; k++){
				const int pos = getInd(cind);
				if(pos==-1||rind>lim) break;
				//printf("get ind %d(%d %d) : %d\n",pos,cind,rind,xi[pos]);
				p[pos] = pt;
				child[pt].push_back(pos);
				xi[pt] = std::max(xi[pt],xi[pos]);
				addFen(pos,-1);
				cind += a-1;
				rind += a;
			}
			if(!child[pt].empty()){
				//printf("G ")
				addFen(pt,1);
				p[pt] = pt;
				pt++;
			}else break;
		}
	}

	for(int i = 1; i < pt; i++){
		//printf("P %d %d\n",i,p[i]);
		if(p[i]==i){
			recurSet(i,xi[i]);
		}
	}
	for(int i = 1; i <= n; i++){
		printf("%d\n",ans[i]);
	}
}