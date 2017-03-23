#include "vector"
#include "algorithm"
#include "queue"
#include "iostream"

typedef std::pair<int,int> PII;

struct Intersect{
	double t;
	int i,j;
	double y;
	Intersect(double _t = 0.0, int _i = 0, int _j = 0, double _y = 0.0) : t(_t), i(_i), j(_j), y(_y) {
	}
};

struct Query{
	int id;
	bool isB;
	long long t;
	long long p;
	Query(int _id = 0, bool _isB = false, long long _t = 0, long long _p = 0) : id(_id), isB(_isB), t(_t), p(_p) {}
};

int n,m,t;
int v[2005];
long long x[2005];
long long p,b,e;
std::vector<Intersect> in;
std::vector<Query> qu;
std::vector<int> run;
std::priority_queue<PII> st;
std::priority_queue<int> pst;
int pos[2005];
int bc[200005],ec[200005];
long long ct;

bool cmp(Intersect a, Intersect b){
	if(a.t==b.t){
		return a.y<b.y;
	}else return a.t<b.t;
}

bool cmp2(Query a, Query b){
	if(a.t==b.t){
		if(a.id==b.id){
			return a.isB;
		}else{
			return a.p<b.p;
		}
	}else return a.t<b.t;
}

//runner
bool cmp3(int a, int b){
	if(x[a]==x[b]){
		return v[a]<v[b];
	}else return x[a]<x[b];
}

bool cmp4(int val, int a){
	//printf("cmp %d %d\n",a,val);
	return val<x[a]+v[a]*ct;
}

void pushSt(Intersect x){
	st.push({v[x.i],x.i});
	st.push({v[x.j],x.j});
	pst.push(pos[x.i]);
	pst.push(pos[x.j]);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin >> n >> m;
	//scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		//scanf("%d%d",&t[i],&v[i]);
		std::cin >> t >> v[i];
		x[i] = -v[i]*t;
		run.push_back(i);
	}
	for(int i = 0; i < m; i++){
		//scanf("%lld %lld %lld",&p[i],&b[i],&e[i]);
		std::cin >> p >> b >> e;
		//x == p[i]
		//y == mode (begin=0,end=1)
		qu.push_back(Query(i,true,b,p));
		qu.push_back(Query(i,false,e,p));
	}

	//find intersection
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(v[i]!=v[j]&&x[i]!=x[j]){
				double inT = (x[i]-x[j])/(double)(v[j]-v[i]);
				in.push_back(Intersect(inT,i,j,x[i]+inT*v[i]));
			}
		}
	}

	std::sort(in.begin(),in.end(),cmp);
	std::sort(qu.begin(),qu.end(),cmp2);
	std::sort(run.begin(),run.end(),cmp3);

	for(int i = 0; i < run.size(); i++){
		pos[run[i]] = i;
	}

	for(unsigned int i = 0,j = 0; i < qu.size(); i++){
		for(; j < in.size() && in[j].t <= (double)qu[i].t; j++){
			//find all point that has a same intersect
			pushSt(in[j]);
			while(j+1 < in.size() && in[j].t==in[j+1].t && in[j].y==in[j+1].y){
				j++;
				pushSt(in[j]);
			}
			PII sls = {-1,-1};
			int pls = -1;
			while(!st.empty()&&!pst.empty()){
				sls = st.top();
				pls = pst.top();
				while(!st.empty()&&st.top()==sls) st.pop();
				while(!pst.empty()&&pst.top()==pls) pst.pop();

				run[pls] = sls.second;
				pos[sls.second] = pls;
			}
		}

		ct = qu[i].t;
		// printf("T = %lld %d : %lld\n",ct,qu[i].id,qu[i].p);
		// for(int k = 0; k < run.size(); k++){
		// 	printf("Runner : %d %lld\n",run[k],x[run[k]]+ct*v[run[k]]);
		// }
		if(qu[i].isB){
			//begin
			bc[qu[i].id] = std::upper_bound(run.begin(),run.end(),qu[i].p,cmp4)-run.begin();
			//printf("Begin : %d\n",bc[qu[i].id]);
		}else{
			//end
			ec[qu[i].id] = std::upper_bound(run.begin(),run.end(),qu[i].p-1,cmp4)-run.begin();
			//printf("End : %d\n",ec[qu[i].id]);
		}

	}

	for(int i = 0; i < m; i++){
		//printf("%d\n",bc[i]-ec[i]);
		std::cout << bc[i]-ec[i] << "\n";
	}
}