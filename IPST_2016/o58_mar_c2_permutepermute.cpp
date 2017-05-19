#include "stdio.h"
#include "vector"
#include "algorithm"

int n,m;
char in[100005][10];
int xi[100005],qu[100006],yi[100005];
char permute[800005][10];
int leaf[200005];
std::vector<int> point;

void makeSeg(int no, int x, int y){
	for(int i = 0; i < 10; i++){
		permute[no][i] = i;
	}

	if(x!=y){
		makeSeg(no*2+1,x,x+(y-x)/2);
		makeSeg(no*2+2,x+(y-x)/2+1,y);
	}else{
		leaf[x] = no;
	}
}

void updateSeg(int no){
	//recombine
	//printf("update %d : ",no);
	for(int i = 0; i < 10; i++){
		permute[no][i] = permute[no*2+2][permute[no*2+1][i]];
		//printf("%d(%d) ",permute[no][i],permute[no*2+1][i]);
	}
	//printf("\n");

	if(no) updateSeg((no-1)/2);
}

void addSeg(int source, int pos){
	pos = std::lower_bound(point.begin(),point.end(),pos)-point.begin();
	int x = leaf[pos];
	for(int i = 0; i < 10; i++){
		permute[x][i] = in[source][i];
	}
	if(x) updateSeg((x-1)/2);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d",&xi[i]);
		point.push_back(xi[i]);
		for(int j = 0; j < 10; j++){
			scanf("%d",&in[i][j]);
		}
	}

	for(int j = 0; j < 10; j++){
		in[n][j] = j;
	}

	for(int i = 0; i < m; i++){
		scanf("%d%d",&qu[i],&yi[i]);
		qu[i]--;
		point.push_back(yi[i]);
	}
	std::sort(point.begin(),point.end());
	makeSeg(0,0,point.size()-1);

	for(int i = 0; i < n; i++){
		addSeg(i,xi[i]);
	}

	for(int i = 0; i < m; i++){
		addSeg(n,xi[qu[i]]);
		xi[qu[i]] = yi[i];
		addSeg(qu[i],yi[i]);
		printf("%d\n",permute[0][0]);
	}
}