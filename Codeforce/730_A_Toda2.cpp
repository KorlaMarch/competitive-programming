#include "stdio.h"
#include "queue"

#define PII std::pair<int,int>

int n,ri,ptr;
int feq[105];
std::priority_queue<PII> qu;
bool oper[10005][105];

void nega(PII& x){
	feq[x.first]--;
	if(x.first>0){
		x.first--;
	}
	feq[x.first]++;

	oper[ptr][x.second] = true;
}

void repush(int left){
	for(int i = 0; i < left; i++){
		PII pi = qu.top();
		qu.pop();

		nega(pi);
		qu.push(pi);
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&ri);
		qu.push({ri,i});
		feq[ri]++;
	}
	for(int i = 0; feq[qu.top().first] != n; i++,ptr++){
		PII pi = qu.top();

		if(feq[pi.first]==1){
			qu.pop();
			PII pi2 = qu.top();
			qu.pop();

			nega(pi);
			nega(pi2);

			qu.push(pi);
			qu.push(pi2);

		}else{
			if(feq[pi.first]>5){
				if(feq[pi.first] == 6){
					repush(4);
				}else{
					repush(5);
				}
			}else{
				// <= 5
				repush(feq[pi.first]);
			}
		}
	}
	printf("%d\n%d\n",qu.top().first,ptr);
	for(int i = 0; i < ptr; i++){
		for(int j = 0; j < n; j++){
			if(oper[i][j]) putchar('1');
			else putchar('0');
		}
		putchar('\n');
	}
}