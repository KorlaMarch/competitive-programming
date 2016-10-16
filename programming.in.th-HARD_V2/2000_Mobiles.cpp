#include "stdio.h"
#include "algorithm"

int n,swc;
int mxH[100005],mnH[100005];
int l[100005];
int r[100005];

void findH(int no, int h){
	if(l[no]==-1&&r[no]==-1){
		mxH[no] = mnH[no] = h+1;
	}else if(l[no]==-1){
		findH(r[no],h+1);
		mnH[no] = h+1;
		mxH[no] = mxH[r[no]];
	}else if(r[no]==-1){
		findH(l[no],h+1);
		mnH[no] = h+1;
		mxH[no] = mxH[l[no]];
	}else{
		findH(l[no],h+1);
		findH(r[no],h+1);
		mnH[no] = std::min(mnH[l[no]],mnH[r[no]]);
		mxH[no] = std::max(mxH[l[no]],mxH[r[no]]);
	}
}

bool fixH(int no){
	if(mxH[no]==mnH[no]){
		return true;
	}else if(l[no]==-1){
		std::swap(l[no],r[no]);
		swc++;
		return fixH(l[no]);
	}else if(r[no]==-1){
		return fixH(l[no]);
	}else if(mnH[l[no]]==mxH[l[no]]){
		if(mnH[l[no]]==mxH[no]){
			return fixH(r[no]);
		}else{
			std::swap(l[no],r[no]);
			swc++;
			return fixH(l[no]);
		}
	}else if(mnH[r[no]]==mxH[r[no]]){
		if(mnH[r[no]]==mnH[no]){
			return fixH(l[no]);
		}else{
			std::swap(l[no],r[no]);
			swc++;
			return fixH(r[no]);
		}
	}else{
		return false;
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	findH(1,0);
	if(mxH[1]-mnH[1]>1 || !fixH(1)){
		printf("-1\n");
	}else{
		printf("%d\n",swc);
	}
}