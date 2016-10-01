#include "stdio.h"
#include "algorithm"

#define TEAMNUM 6

int ind[10];
char teamN[10],s[10];
int tp[10], tgd[10], tgf[10], tr[10];
int w,d,l,gf,ga,r;

bool cmp(int a, int b){
	if(tp[a]==tp[b]){
		if(tgd[a]==tgd[b]){
			if(tgf[a]==tgf[b]){
				return tr[a]<tr[b];
			}else return tgf[a]>tgf[b];
		}else return tgd[a]>tgd[b];
	}else return tp[a]>tp[b];
}

int main(){
	for(int i = 0; i < TEAMNUM; i++){
		scanf(" %s %d %d %d %d %d %d", s, &w, &d, &l, &gf, &ga, &r);
		teamN[i] = s[0];
		tp[i] = 3*w + d;
		tgd[i] = gf-ga;
		tgf[i] = gf;
		tr[i] = r;
		ind[i] = i;
	}
	std::sort(ind,ind+TEAMNUM,cmp);
	for(int i = 0; i < 4; i++){
		int x = ind[i];
		if(tgd[x]) printf("%c3 %d %+d %d %d\n",teamN[x],tp[x],tgd[x],tgf[x],tr[x]);
		else printf("%c3 %d 0 %d %d\n",teamN[x],tp[x],tgf[x],tr[x]);
	}
}