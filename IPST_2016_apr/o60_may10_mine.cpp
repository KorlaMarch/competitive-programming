#include "mine.h"
#include "stdio.h"

int av;

bool search(int x, int y, int si){
	if(si<=0||x>av||y>av) return false;
	//printf(":%d %d %d\n",x,y,si);
	int midx,midy;
	int si2 = si/2;
	int re;
	midx = x + si2;
	midy = y + si2;
	if(midx>av) midx = av;
	else if(midy>av) midy = av;
	re = probe(midx,midy);
	//printf("ASK %d %d : %d\n",midx,midy,re);
	if(re>si2) return false;
	else{
		if(si%2) si2++;
		search(x,y,si2);
		search(midx,y,si2);
		search(x,midy,si2);
		search(midx,midy,si2);
	}
	return true;
}


bool search(int x, int y, int si){
	if(si<=0||x>av||y>av) return false;
	//printf(":%d %d %d\n",x,y,si);
	int midx,midy;
	int si2 = si/2;
	int re;
	midx = x + si2;
	midy = y + si2;
	if(midx>av) midx = av;
	else if(midy>av) midy = av;
	re = probe(midx,midy);
	//printf("ASK %d %d : %d\n",midx,midy,re);
	if(re>si2) return false;
	else{
		if(si%2) si2++;
		search(x,y,si2);
		search(midx,y,si2);
		search(x,midy,si2);
		search(midx,midy,si2);
	}
	return true;
}

int main(){
	av = initialize();
	search(1,1,av);
}