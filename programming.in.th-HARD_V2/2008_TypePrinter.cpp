#include "stdio.h"
#include "queue"
#include "string.h"
#include "algorithm"

int n,mxS,mxP;
char str[25001][21];
std::queue<int> radix[27];
std::queue<char> oper;

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf(" %s", str[i]);
		radix[0].push(i);

		int len = strlen(str[i]);
		if(len>mxS){
			mxS = len;
			mxP = i;
		}
	}

	//radixSort
	for(int i = mxS-1; i >= 0; i--){
		radix[0].push(-1);
		while(radix[0].front()!=-1){
			int v = radix[0].front();
			radix[0].pop();
			radix[ str[v][i] ? str[v][i]-'a'+1 : 0 ].push(v);
		}
		radix[0].pop();

		//push back to qu
		const int skind = str[mxP][i]-'a'+1;
		for(int j = 1; j <= 26; j++){
			if(j != skind){
				while(!radix[j].empty()){
					radix[0].push(radix[j].front());
					radix[j].pop();
				}
			}
		}

		while(!radix[skind].empty()){
			radix[0].push(radix[skind].front());
			radix[skind].pop();
		}
	}

	int lw = radix[0].front();
	int ls;
	radix[0].pop();

	for(ls = 0; str[lw][ls]; ls++){
		oper.push(str[lw][ls]);
	}
	oper.push('P');


	while(!radix[0].empty()){
		int w = radix[0].front();
		radix[0].pop();

		int cp;
		for(cp = 0; str[lw][cp] && str[w][cp] && str[lw][cp]==str[w][cp]; cp++);

		for(int i = ls; i > cp; i--) oper.push('-');

		for(ls = cp; str[w][ls]; ls++){
			oper.push(str[w][ls]);
		}

		lw = w;
		oper.push('P');
	}

	printf("%d\n",oper.size());
	while(!oper.empty()){
		putchar(oper.front());
		putchar('\n');
		oper.pop();
	}
}