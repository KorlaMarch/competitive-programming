#include "stdio.h"
#include "queue"

#define PII std::pair<int,int>

int t,n;
char c;
//fi = min se = max
std::queue<PII> qu;
int main(){
	scanf("%d",&t);
	for(int k = 0; k < t; k++){
		scanf("%d",&n);
		int i;
		for(i = 1; i+1 <= n; i += 2){
			printf("? %d %d\n",i,i+1);
			fflush(stdout);
			scanf(" %c",&c);
			if(c=='='){
				qu.push({i,i});
			}else if(c=='<'){
				qu.push({i,i+1});
			}else{
				qu.push({i+1,i});
			}
		}
		if(i<=n) qu.push({i,i});

		while(qu.size()>1){
			PII fe = qu.front();
			qu.pop();
			PII se = qu.front();
			qu.pop();
			PII nw;
			
			//compare min
			printf("? %d %d\n",fe.first,se.first);
			fflush(stdout);
			scanf(" %c",&c);
			if(c=='<'){
				nw.first = fe.first;
			}else{
				nw.first = se.first;
			}

			//compare max
			printf("? %d %d\n",fe.second,se.second);
			fflush(stdout);
			scanf(" %c",&c);
			if(c=='>'){
				nw.second = fe.second;
			}else{
				nw.second = se.second;
			}
			qu.push(nw);
		}

		PII sol = qu.front();
		qu.pop();
		printf("! %d %d\n",sol.first,sol.second);
		fflush(stdout);
	}
}