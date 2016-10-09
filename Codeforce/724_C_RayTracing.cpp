#include "stdio.h"
#include "vector"

int n,m,k,d,cx,cy;
long long t;
long long minT[100005];
int x[100005],y[100005];

// ++ , --
bool isPd0[300005];
std::vector<int> senD0[300005];
// +- , -+
bool isPd1[300005];
std::vector<int> senD1[300005];

int getind(int cx, int cy, int d){
	if(d==0){
		cx -= cy;
		cy -= cy;
		return cx + 150000;
	}else{
		cx += cy;
		cy -= cy;
		return cx;
	}
}

long long abs(long long n){
	return n<0?-n:n;
}

bool isCorner(int cx, int cy){
	if(cx==0&&cy==0) return true;
	if(cx==0&&cy==m) return true;
	if(cx==n&&cy==0) return true;
	if(cx==n&&cy==m) return true;

	return false;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0; i < k; i++){
		scanf("%d%d",&x[i],&y[i]);
		minT[i] = -1;
		senD0[getind(x[i],y[i],0)].push_back(i);
		senD1[getind(x[i],y[i],1)].push_back(i);
	}

	cx = cy = 0;
	d = 0;

	do{
		
		//cal NextPoint
		int ch;
		int cind = getind(cx,cy,d);

		if(d==0){
			for(int si : senD0[cind]){
				if(minT[si]==-1|| t + abs(x[si]-cx) < minT[si]){
					minT[si] = t + abs(x[si]-cx);
				}
			}
		}else{
			for(int si : senD1[cind]){
				if(minT[si]==-1|| t + abs(x[si]-cx) < minT[si]){
					minT[si] = t + abs(x[si]-cx);
				}
			}
		}
		
		if(d==0){
			if(cx==0||cy==0){
				ch = std::min(n-cx,m-cy);

				cx += ch;
				cy += ch;
			}else if(cx==n||cy==m){
				ch = std::min(cx,cy);
			
				cx -= ch;
				cy -= ch;
			}

			if(!isPd0[cind]) isPd0[cind] = true;
			else break;
		}else{
			if(cx==0||cy==m){
				ch = std::min(cy,n-cx);

				cx += ch;
				cy -= ch;
			}else if(cy==0||cx==n){
				ch = std::min(cx,m-cy);

				cx -= ch;
				cy += ch;
			}

			if(!isPd1[cind]) isPd1[cind] = true;
			else break;
		}
		t += ch;
		d = !d;
	}while(!isCorner(cx,cy));

	for(int i = 0; i < k; i++){
		printf("%I64d\n",minT[i]);
	}
}