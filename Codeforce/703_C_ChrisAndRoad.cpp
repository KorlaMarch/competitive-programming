#include "stdio.h"
#include "algorithm"

int n,w,v,u;
long double miny;
int minid;

std::pair<long double,long double> end;
std::pair<long double,long double> compo[10005];
std::pair<int,int> po[10005];

int main(){
	scanf("%d%d%d%d",&n,&w,&v,&u);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&po[i].first,&po[i].second);
		if(po[i].first<0) po[i].first = 0;
	}
	end.first = w/(long double)u;
	end.second = w;

	for(int i = 0; i < n; i++){
		compo[i].first = po[i].first/(long double)v;
		compo[i].second = (long double) po[i].second;
	}
	minid = -1;
	bool err = false;
	for(int i = 0; i < n; i++){
		if (compo[i].second > u*compo[i].first) {
			err = true;
		}
		if(compo[i].second<miny||minid==-1){
			miny = compo[i].second;
			minid = i;
		}

	}

	if ( not err ) {
		printf("%.10Lf\n",end.first);
		return 0;
	}

	while(true){
		int nexid = ( minid+1 ) % n;
		if((compo[nexid].second-compo[minid].second)<end.first*(compo[nexid].first-compo[minid].first)){
			minid = nexid;
		} else {
			break;
		}
	}
	printf("%.10Lf\n",compo[minid].first+(w-compo[minid].second)/u);

}