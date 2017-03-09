#include "stdio.h"
#include "map"
#include "algorithm"

int n,q,maxT,maxP,od,j,z,p;
int li[50005],xi[50005];
int tlist[50005];
int pcount[50005];
std::map<int,int> segment[300005];

bool isIntersect(int x1, int y1, int x2, int y2){
	return (x1<=x2&&x2<=y1)||(x1<=y2&&y2<=y1)||(x2<=x1&&x1<=y2)||(x2<=y1&&y1<=y2);
}

void addseg(int no, int i, int j, int x, int y, int t, int id){
	if(x<=i&&j<=y){
		//subset
		segment[no].insert({t,id});
	}else if(i!=j){
		if(isIntersect(i,(j-i+1)/2+i-1,x,y)) addseg(no*2+1,i,(j-i+1)/2+i-1,x,y,t,id);
		if(isIntersect((j-i+1)/2+i,j,x,y)) addseg(no*2+2,(j-i+1)/2+i,j,x,y,t,id);
	}
}

void remseg(int no, int i, int j, int x, int y, int t){
	if(x<=i&&j<=y){
		//subset
		segment[no].erase(t);
	}else if(i!=j){
		if(isIntersect(i,(j-i+1)/2+i-1,x,y)) remseg(no*2+1,i,(j-i+1)/2+i-1,x,y,t);
		if(isIntersect((j-i+1)/2+i,j,x,y)) remseg(no*2+2,(j-i+1)/2+i,j,x,y,t);
	}
}

void palmfall(int no, int i, int j, int p){
	if(!segment[no].empty()&&segment[no].rbegin()->first>maxT){
		maxT = segment[no].rbegin()->first;
		maxP = segment[no].rbegin()->second;
	}
	if(i!=j){
		if(p<(j-i+1)/2+i) palmfall(no*2+1,i,(j-i+1)/2+i-1,p);
		else palmfall(no*2+2,(j-i+1)/2+i,j,p);
	}
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i = 1; i <= n; i++){
		scanf("%d%d",&li[i],&xi[i]);
		tlist[i] = i;
		addseg(0,0,100000,xi[i],xi[i]+li[i],i,i);
	}

	for(int i = 0; i < q; i++){
		scanf("%d",&od);
		if(od==1){
			scanf("%d%d",&j,&z);
			remseg(0,0,100000,xi[j],xi[j]+li[j],tlist[j]);
			xi[j] = z;
			tlist[j] = i+q+1;
			addseg(0,0,100000,xi[j],xi[j]+li[j],tlist[j],j);
			//printf("%d are now %d %d\n",j,xi[j],xi[j]+li[j]);
		}else{
			scanf("%d",&p);
			maxT = 0;
			maxP = 0;
			palmfall(0,0,100000,p);
			//printf("%d Hit on %d\n",p,maxP);
			pcount[maxP]++;
		}
	}

	for(int i = 1; i <= n; i++){
		printf("%d\n",pcount[i]);
	}
}