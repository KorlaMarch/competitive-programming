#include "stdio.h"
#include "vector"
#include "set"

int n,m,unuse;
std::vector<int> cpos[100005];
int a[100005];
bool isP[100005];

int paint(int x, int y);

int paintColor(int x, int y, int c){
	int fi = x-1, mx = 0;
	for(int i : cpos[c]){
		mx = std::max(mx,paint(fi+1,i-1));
		fi = i;
	}
	return mx+1;
}

int paint(int x, int y){
	if(x>y) return -1000000000;

	int mx = 0, j = 0;
	for(int i = x; i <= y; i++,j++){
		mx = std::max(mx,paintColor(cpos[a[i]].front(),cpos[a[i]].back(),a[i]));
		i = cpos[a[i]].back();
	}
	//printf("CALL %d %d : %d\n",x,y,mx);
	return mx+j-1;
}

int main(){
	scanf("%d%d",&n,&m);
	unuse = m;
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		if(!isP[a[i]]){
			isP[a[i]] = true;
			unuse--;
		}
		cpos[a[i]].push_back(i);
	}

	printf("%d\n",paint(1,n)+unuse);
}