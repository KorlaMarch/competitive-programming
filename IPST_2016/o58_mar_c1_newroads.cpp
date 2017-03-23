#include "stdio.h"
#include "vector"
#include "algorithm"

struct Edge{
	int to;
	int c;
	int id;
	Edge(int _to = 0, int _c = 0, int _id = 0) : to(_to), c(_c), id(_id) {
	}
};

int n,m,a,b,c;
std::vector<int> edge[100005];
int inD[100005],outD[100005];

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d",&a,&b,&c);
		edge[a].push_back(Edge(b,c,i));

		inD[b]++;
		outD[a]++;
	}

	for(int i = 0; i < )
}