#include "stdio.h"
#include "algorithm"

typedef std::pair<long long,long long> PII;

int q,t;
long long x,y,k;
long long hi[32];
long long si[32];

PII rotate(int d, PII a, int rot){
	if(rot==0){
		return a;
	}else if(rot==1){
		return {si[d]-a.second,a.first};
	}else if(rot==2){
		return {si[d]-a.first,si[d]-a.second};
	}else{
		return {a.second,si[d]-a.first};
	}
}

long long find1(int i, PII pi){
	if(pi.first==0&&pi.second==0) return 0;
	if(i<-10) return 0;
	//printf("%d : %lld %lld\n",i,pi.first,pi.second);

	long long k;
	int rot;
	bool isIn = false;

	if(i%2==1){
		//even
		if(pi.first<=si[i]&&pi.second<=si[i]){
			k = 0;
			rot = 0;
		}else if(pi.first>si[i]&&pi.second<=si[i]){
			k = hi[i]+1;
			rot = 1;
			isIn = true;
		}else if(pi.first>si[i]&&pi.second>si[i]){
			k = 2*hi[i]+2;
			rot = 1;
			isIn = true;
		}else if(pi.first<=si[i]&&pi.second>si[i]){
			k = 3*hi[i]+3;
			rot = 2;
		}
	}else{
		//odd
		if(pi.first<=si[i]&&pi.second<=si[i]){
			k = 0;
			rot = 0;
		}else if(pi.first<=si[i]&&pi.second>si[i]){
			k = hi[i]+1;
			rot = 3;
			isIn = true;
		}else if(pi.first>si[i]&&pi.second>si[i]){
			k = 2*hi[i]+2;
			rot = 3;
			isIn = true;
		}else if(pi.first>si[i]&&pi.second<=si[i]){
			k = 3*hi[i]+3;
			rot = 2;
		}
	}

	if(pi.first>si[i]) pi.first -= si[i]+1;
	if(pi.second>si[i]) pi.second -= si[i]+1;

	pi = rotate(i,pi,rot);
	//printf("RE %d : %lld\n",i,k);
	if(!isIn) k += find1(i-1,pi);
	else k += hi[i]-find1(i-1,pi);
	//printf("RE2 %d : %lld (%d)\n",i,k,isIn);
	return k;
}

PII find2(int i, long long k){
	//if(i<-20) return {0,0};
	//printf("%d : %d\n",i,k);
	if(k==0) return {0,0};

	PII re,ge;
	int rot;
	bool isIn = false;

	if(i%2==1){
		//even
		if(k<=hi[i]){
			re.first = 0;
			re.second = 0;
			rot = 0;
		}else if(k<=2*hi[i]+1){
			re.first = si[i]+1;
			re.second = 0;
			k -= hi[i]+1;
			rot = 3;
			isIn = true;
		}else if(k<=3*hi[i]+2){
			re.first = si[i]+1;
			re.second = si[i]+1;
			k -= 2*hi[i]+2;
			rot = 3;
			isIn = true;
		}else{
			re.first = 0;
			re.second = si[i]+1;
			k -= 3*hi[i]+3;
			rot = 2;
		}
	}else{
		//odd
		if(k<=hi[i]){
			re.first = 0;
			re.second = 0;
			rot = 0;
		}else if(k<=2*hi[i]+1){
			re.first = 0;
			re.second = si[i]+1;
			k -= hi[i]+1;
			rot = 1;
			isIn = true;
		}else if(k<=3*hi[i]+2){
			re.first = si[i]+1;
			re.second = si[i]+1;
			k -= 2*hi[i]+2;
			rot = 1;
			isIn = true;
		}else{
			re.first = si[i]+1;
			re.second = 0;
			k -= 3*hi[i]+3;
			rot = 2;
		}
	}

	if(!isIn) ge = find2(i-1,k);
	else ge = find2(i-1,hi[i]-k);
	ge = rotate(i,ge,rot);
	//printf("%d : %lld %lld : %lld %lld\n",i,re.first,re.second,ge.first,ge.second);
	re.first += ge.first;
	re.second += ge.second;
	return re;
}

int main(){
	for(int i = 1; i <= 31; i++){
		hi[i] = 4*hi[i-1] + 3;
		si[i] = 2*si[i-1] + 1;
		//printf("%d : %lld %lld\n",i,hi[i],si[i]);
	}
	scanf("%d",&q);
	for(int a = 0; a < q; a++){
		scanf("%d",&t);
		//t = 1;
		if(t==1){
			scanf("%lld%lld",&x,&y);
			x--,y--;
			printf("%lld\n",find1(31,{x,y}));
		}else if(t==2){
			scanf("%lld",&k);

			PII ans = find2(31,k);

			printf("%lld %lld\n",ans.first+1,ans.second+1);
		}
	}
}