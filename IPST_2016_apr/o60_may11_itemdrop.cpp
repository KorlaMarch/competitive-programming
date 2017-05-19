#include "stdio.h"
#include "math.h"
#include "algorithm"

#define INF 1000000000.0

typedef std::pair<double,double> PII;

int m,n,t;
int cx[105],cy[105],ri[105];
PII cpos[105];
int xi[105],yi[105];

double dot(PII a, PII b){
	return a.first*b.first + a.second*b.second;
}

double cross(PII a, PII b){
	return a.first*b.second-a.second*b.first;
}

double dist(PII a){
	return sqrt(dot(a,a));
}

PII sub(PII a, PII b){
	//cal a-b
	return {a.first-b.first,a.second-b.second};
}

PII mul(PII a, double x){
	return {a.first*x,a.second*x};
}

PII projPoint(PII a, PII b, PII c){
	//proj point c on a->b
	PII unitV = mul(sub(b,a),1.0/dist(sub(b,a)));
	return mul(unitV,dot(sub(c,a),unitV));
}

PII unit(PII a, PII b){
	return mul(sub(b,a),1.0/dist(sub(b,a)));
}

double projDis(PII a, PII b, PII c){
	//proj point c on a->b
	PII unitV = unit(a,b);
	return dot(sub(c,a),unitV);
}

double disLine(PII a, PII b, PII c){
	// distance of line a->b to point c
	return dist(sub(c,projPoint(a,b,c)));
}

double disSeg(PII a, PII b, PII c){
	//distance of segment a->b to point c
	double pro = projDis(a,b,c);
	if(pro<0){
		return dist(sub(a,c));
	}else if(pro>dist(sub(b,a))){
		return dist(sub(b,c));
	}else{
		return disLine(a,b,c);
	}
}

PII findIntersect(PII a1, PII a2, PII b1, PII b2){
	double x=-INF,y=INF;
	double m;
	PII unitA = unit(a1,a2);
	PII unitB = unit(b1,b2);
	PII ai; 

	for(int i = 0; i < 100; i++){
		m = (x+y)/2.0;
		double cr = cross(unitA,mul(unitB,m));
		if(cr<0){
			x = ;
		}else{
			y = ;
		}
	}
	return mul(unitB,m);
}

PII findTA(PII a, PII b){

}

PII findTB(PII a, PII b){
	
}

int main(){
	scanf("%d%d%d",&m,&n,&t);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d",&cx[i],&cy[i],&ri[i]);
		cpos[i].first = cx[i];
		cpos[i].second = cy[i];
	}
	scanf("%d%d",&xi[0],&yi[0]);
	for(int i = 1; i < n; i++){
		scanf("%d%d",&xi[i],&yi[i]);
		PII pa = {xi[i-1],yi[i-1]};
		PII pb = {xi[i],yi[i]};
		//try normal line
		bool isOb = false;
		for(int j = 0; j < m; j++){
			if(disSeg(pa,pb,cpos[j])<ri[j]){
				isOb = true;
				break;
			}
		}
		if(isOb){
			PII ta = findTA(pa,pb);
			PII tb = findTB(pa,pb);
			double di = std::min(dist(sub(pa,ta))+dist(sub(ta,pb)),dist(sub(pa,tb))+dist(sub(tb,pb)));
			printf("%d\n",std::min(t,(int)round(di)));
		}else{
			printf("%d\n", std::min(t,(int)round(dist(sub(pa,pb)))));
		}
	}
}