#include "stdio.h"
#include "vector"

int m,n,f,q,u;
long long a[101];
bool isIN[1001];
std::vector<bool> hash[1001];
std::vector<int> bits;
char s[1001];
char c;
int main(){
	freopen("filter.in","r",stdin);
	freopen("filter.out","w+",stdout);
	scanf("%d%d",&m,&f);
	for(int i = 0; i < f; i++){
		scanf("%I64d",&a[i]);
	}
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf(" %s",s);

		for(int j = 0; s[j]; j++){
			c = s[j];
			if(c>='0'&&c<='9') c -= '0';
			else c = c-'a'+10;
			for(int k = 0; k < 4; k++){
				hash[i].push_back(c%2);
				c /= 2;
			}
		}
	}
	
	scanf("%d",&q);
	int c = 0;
	for(int i = 0; i < q; i++){
		scanf("%d",&u);
		bits.clear();
		for(int j = 0; j < f; j++){
			bits.push_back((a[j]*u)%m);
		}
		for(int j = 0; j < n; j++){
			int k;
			for(k = 0; k < f; k++){
				if(!hash[j][bits[k]]) break;
			}
			if(k==f&&!isIN[j]){
				c++;
				isIN[j] = true;
			}
		}
	}
	printf("%d ",c);
	for(int i = 0; i < n; i++){
		if(isIN[i]) printf("%d ",i);
	}
}