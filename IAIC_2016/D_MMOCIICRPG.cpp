#include "iostream"
#include "vector"
#include "algorithm"

int n,m,q,ti,ki;
int vi[200005];
int pi[200005],mi[200005];
std::vector<int> compath;
std::vector<int> child[200005];
std::vector<std::pair<int,int> > qu[200005];
long long ans[200005];

int sumc;
int fenC[200005];
long long sumv;
long long fenV[2000005];
int count[200005];

int getFenC(int i){
	int v = 0;
	for(; i > 0; i -= (i&-i)) v += fenC[i];
	return v;
}

void addFenC(int i, int v){
	sumc += v;
	for(; i <= m; i += (i&-i)) fenC[i] += v;
}

long long getFenV(int i){
	long long v = 0;
	for(; i > 0; i -= (i&-i)) v += fenV[i];
	return v;
}

void addFenV(int i, long long v){
	sumv += v;
	for(; i <= m; i += (i&-i)) fenV[i] += v;
}

void doQuerry(int x){
	int k;

	if(mi[x]){
		count[mi[x]]++;
		if(count[mi[x]]==1){
			//printf("ADD %d\n",vi[mi[x]]);
			k = std::lower_bound(compath.begin(),compath.end(),vi[mi[x]])-compath.begin()+1;
			addFenC(k,1);
			addFenV(k,vi[mi[x]]);
		}
	}

	for(std::pair<int,int> pi : qu[x]){
		int kcom = std::lower_bound(compath.begin(),compath.end(),pi.first)-compath.begin();
		//printf("DO QU %d %d : %lld %d\n",pi.first,pi.second,getFenV(kcom),getFenC(kcom));
		ans[pi.second] = sumv-getFenV(kcom)-pi.first*(sumc-getFenC(kcom));
	}

	for(int i : child[x]){
		doQuerry(i);
	}

	if(mi[x]){
		count[mi[x]]--;
		if(count[mi[x]]==0){
			//printf("RE %d\n",vi[mi[x]]);
			addFenC(k,-1);
			addFenV(k,-vi[mi[x]]);
		}
	}
}

char str[50];

void readTwoNum(int& a, int& b){
	std::cin.getline(str,50);
	a = 0;
	b = 0;
	int i;
	for(i = 0; str[i] != ' '; i++){
		a *= 10;
		a += str[i]-'0';
	}
	for(i++; str[i]; i++){
		b *= 10;
		b += str[i]-'0';
	}
	//std::cout << "GET " << str << " " << a << " " << b << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin >> n >> m >> q;
	//scanf("%d%d%d",&n,&m,&q);
	for(int i = 1; i <= m; i++){
		//scanf("%d",&vi[i]);
		std::cin >> vi[i];
		compath.push_back(vi[i]);
	}
	std::cin.getline(str,50);
	std::sort(compath.begin(),compath.end());
	for(int i = 2; i <= n; i++){
		//scanf("%d%d",&pi[i],&mi[i]);
		//std::cin >> pi[i] >> mi[i];
		readTwoNum(pi[i],mi[i]);
		child[pi[i]].push_back(i);
	}
	for(int i = 0; i < q; i++){
		//scanf("%d%d",&ti,&ki);
		//std::cin >> ti >> ki;
		readTwoNum(ti,ki);
		qu[ti].push_back({ki,i});
	}

	doQuerry(1);

	for(int i = 0; i < q; i++){
		std::cout << ans[i] << "\n";
	}
}