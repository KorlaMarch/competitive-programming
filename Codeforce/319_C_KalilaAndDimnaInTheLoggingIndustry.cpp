#include "stdio.h"
#include "algorithm"
#include "vector"

typedef std::pair<long long, long long> PII;

int n;
long long a[100005];
long long b[100005];
long long dyn[100005];
std::vector<PII> line;

double intersect(PII a, PII b){
	return (b.second-a.second)/(double)(a.first-b.first);
}

// y = mx + c
void addSet(PII li){
	while(line.size()>=2 && intersect(li, line[line.size()-2]) <= intersect(line.back(),line[line.size()-2])) line.pop_back();
	line.push_back(li);
}

long long getY(long long p){
	int x = 1, y = line.size()-1, lm, m;
	if(line.size()<=1||p<=intersect(line[0],line[1])) return line[0].first*p + line[0].second;
	while(x<=y){
		m = (x+y)/2;
		if(intersect(line[m],line[m-1])<=p){
			lm = m;
			x = m+1;
		}else{
			y= m-1;
		}
	}
	return line[lm].first*p + line[lm].second;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%I64d",&a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%I64d",&b[i]);
	}

	dyn[0] = 0;
	addSet({b[0],0});
	for(int i = 1; i < n; i++){
		dyn[i] = getY(a[i]);
		addSet({b[i],dyn[i]});
	}
	printf("%I64d\n",dyn[n-1]);
}