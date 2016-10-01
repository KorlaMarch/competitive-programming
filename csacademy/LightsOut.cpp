#include "stdio.h"
#include "vector"
#include "stdlib.h"

int n,m;
bool st[501][501];
bool a[501][501];
std::vector<int> fr,fc;
std::vector<std::pair<int,int> > mo1,mo2;
void copyA(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			a[i][j] = st[i][j];
		}
	}
	fr.clear();
	fc.clear();
}

void filpRow(int r){
	fr.push_back(r);
	for(int i = 0; i < m; i++){
		a[r][i] = !a[r][i];
	}
}

void filpCol(int c){
	fc.push_back(c);
	for(int i = 0; i < n; i++){
		a[i][c] = !a[i][c];
	}
}

bool solve(std::vector<std::pair<int,int> >& out){
	int oc;
	for(int i = 0; i < m; i++){
		if(a[0][i]){
			filpCol(i);
		}
	}
	for(int i = 1; i < n; i++){
		oc = 0;
		for(int j = 0; j < m; j++){
			if(a[i][j]) oc++;
		}
		if(oc==m){
			filpRow(i);
		}else if(oc!=0){
			return false;
		}
	}
	if(fr.size()>=fc.size()&&( fr.size()-fc.size() )%2==0){
		for(unsigned int i = 0; i < fc.size(); i++){
			out.push_back({fr[i]+1,fc[i]+1});
		}
		for(unsigned int i = fc.size(); i < fr.size(); i++){
			out.push_back({fr[i]+1,1});
		}
	}else if(( fc.size()-fr.size() )%2==0){
		for(unsigned int i = 0; i < fr.size(); i++){
			out.push_back({fr[i]+1,fc[i]+1});
		}
		for(unsigned int i = fr.size(); i < fc.size(); i++){
			out.push_back({1,fc[i]+1});
		}
	}else{
		return false;
	}
	return true;
}

void printR(std::vector<std::pair<int,int> >& r){
	printf("%u\n",r.size());
	for(auto x : r){
		printf("%d %d\n",x.first,x.second);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d",&st[i][j]);
		}
	}
	copyA();
	bool r1 = solve(mo1);
	copyA();
	filpRow(0);
	bool r2 = solve(mo2);

	if(r1&&r2){
		if(mo1.size()<=mo2.size()){
			printR(mo1);
		}else{
			printR(mo2);
		}
	}else if(r1){
		printR(mo1);
	}else if(r2){
		printR(mo2);
	}else{
		printf("-1\n");
	}
}
