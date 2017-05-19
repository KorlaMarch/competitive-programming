#include "stdio.h"
#include "vector"
#include "algorithm"

#define INDSIZE 300000

typedef std::pair<int,int> PII;

struct Node{
	int xi,yi;
	int id;
	Node(int _xi = 0, int _yi = 0, int _id = 0) : xi(_xi), yi(_yi), id(_id) {}
};

bool cmp(Node a, Node b){
	if(a.xi==b.xi) return a.yi < b.yi;
	else return a.xi < b.xi;
}

int n,q;
PII stu[70005];
Node teach[70005];
std::vector<int> ti;
int opi[70005],oqi[70005];
int qsEnd[INDSIZE];
int qsStart[INDSIZE];
int ansQ3[INDSIZE];
int ansOut[INDSIZE];
int fen[INDSIZE];
std::vector<PII> endStu[INDSIZE];
std::vector<PII> begStu[INDSIZE];

inline int getInd(int t){
	return std::upper_bound(ti.begin(),ti.end(),t)-ti.begin()-1;
}

void addFen(int x, int v){
	for(; x < ti.size(); x+=(x&-x)){
		fen[x] += v;
	}
}

int getFen(int x){
	int v = 0;
	for(; x > 0; x-=(x&-x)){
		v += fen[x];
	}
	return v;
}

int main(){
	scanf("%d%d",&n,&q);
	ti.push_back(0);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&stu[i].first,&stu[i].second);
		ti.push_back(stu[i].first);
		ti.push_back(stu[i].second);
	}
	for(int i = 0; i < q; i++){
		scanf("%d%d",&teach[i].xi,&teach[i].yi);
		opi[i] = teach[i].xi;
		oqi[i] = teach[i].yi;
		teach[i].id = i;
		ti.push_back(teach[i].xi);
		ti.push_back(teach[i].yi);
	}

	std::sort(stu,stu+n);
	std::sort(teach,teach+q,cmp);
	//compress path
	std::sort(ti.begin(),ti.end());
	int newSi = std::unique(ti.begin(),ti.end())-ti.begin();
	ti.resize(newSi);

	for(int i = 0; i < n; i++){
		qsStart[getInd(stu[i].first)]++;
		qsEnd[getInd(stu[i].second)]++;
		if(stu[i].first!=stu[i].second){
			begStu[getInd(stu[i].first)].push_back(stu[i]);
			endStu[getInd(stu[i].second)].push_back(stu[i]);
		}
	}
	for(int i = 1; i < ti.size(); i++){
		qsStart[i] += qsStart[i-1];
		qsEnd[i] += qsEnd[i-1];
	}


	//cal ansOut (Q5)
	for(int i = 0, j = 0; i < ti.size(); i++){
		//cal ans
		for(; j < q && getInd(teach[j].xi)<=i; j++){
			ansOut[teach[j].id] = getFen(getInd(teach[j].yi));
		}

		//update beg
		for(PII pi : begStu[i]){
			addFen(getInd(pi.first),1);
			addFen(getInd(pi.second),-1);
		}
		//update end
		for(PII pi : endStu[i]){
			addFen(getInd(pi.first),-1);
			addFen(getInd(pi.second),1);
		}
	}

	//cal Q3
	for(int i = 0, j = 0; i < ti.size(); i++){
		//cal ans
		for(; j < q && getInd(teach[j].xi)<=i; j++){
			ansQ3[teach[j].id] = getFen(getInd(teach[j].yi))-getFen(getInd(teach[j].xi-1));
		}

		//update beg
		for(PII pi : begStu[i]){
			addFen(getInd(pi.second),1);
		}
		//update end
		for(PII pi : endStu[i]){
			addFen(getInd(pi.second),-1);
		}
	}

	//cal final answer and print out
	for(int i = 0; i < q; i++){
		int q1,q2,q3,q4,q5;
		q3 = ansQ3[i];
		q5 = ansOut[i];
		q4 = qsEnd[getInd(oqi[i])]-qsEnd[getInd(opi[i]-1)]-q3;
		q2 = qsStart[getInd(oqi[i])]-qsStart[getInd(opi[i]-1)]-q4;
		q1 = q2+q3+q4+q5;
		printf("%d %d %d %d %d\n",q1,q2,q3,q4,q5);
	}

}