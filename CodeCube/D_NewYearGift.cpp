#include "stdio.h"
#include "vector"
#include "algorithm"

int n,m,a,b,co,mx,mxP;
int deg[30005];
std::vector<int> edge[30005];
std::vector< std::pair<int,int> > lv;
bool isU[30005];

void listLeave(int no, int p, int h){
	if(edge[no].size()==1&&p){
		//printf("NO = %dn",no);
		lv.push_back({h,no});
	}else{
		for(int x : edge[no]){
			if(x != p){
				listLeave(x,no,h+1);
			}
		}
	}
}

void findFar(int no, int p, int h){
	if(edge[no].size()==1&&p){
		if(h>mx){
			mx = h;
			mxP = no;
		}
	}else{
		for(int x : edge[no]){
			if(x != p && !isU[x]){
				findFar(x,no,h+1);
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i < n; i++){
		scanf("%d%d",&a,&b);
		deg[a]++;
		deg[b]++;

		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		if(deg[i]==1){
			co++;
		}
	}

	printf("%d\n",(co+1)/2);


	if(m==2){
		listLeave(1,0,0);
		for(auto pi : lv){
			if(!isU[pi.second]){
				mx = 0;
				mxP = 0;
				findFar(pi.second,0,0);
				if(mx){
					isU[mxP] = true;
					isU[pi.second] = true;
					printf("%d %d\n",pi.second,mxP);
				}else{
					printf("%d 1\n",pi.second);
				}
			}
		}
	}
}