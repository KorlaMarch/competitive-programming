#include <algorithm>
#include "vector"
#include "array"

#include "sort_weight.h"

using namespace std;
std::vector<std::array<int,5>> le[8];

int countPair(int ind, int a, int b){
  int co = 0;
  for(std::array<int,5>& it : le[ind]){
    if(it[a]<it[b]){
      co++;
    }
  }
  return std::max(co,(int)le[ind].size()-co);
}

void findSap(int ind){
  int mxI,mxJ,mn=121;
  for(int i = 0; i < 5; i++){
    for(int j = i+1; j < 5; j++){
      int x = countPair(ind,i,j);
      if(x<mn){
        mn = x;
        mxI = i;
        mxJ = j;
      }
    }
  }

  int re = sort_weight(mxI,mxJ);
  if(re==-1) re = 0;

  le[ind+1].clear();
  for(std::array<int,5>& it : le[ind]){
    if((it[mxI]>it[mxJ])==re){
      le[ind+1].push_back(it);
    }
  }
}

int main() {
  std::array<int,5> a;
  int T = get_case();
  while (T--) {
    sort_init();

    for(int i = 0; i < 5; i++){
      a[i] = i;
    }
    le[0].clear();
    for(int i = 0; i < 120; i++){
      le[0].push_back(a);
      std::next_permutation(a.begin(),a.end());
    }
    for(int i = 0; i < 7; i++){
      findSap(i);
    }
    int ans[5];
    for(int i = 0; i < 5; i++){
      ans[le[7][0][i]] = i;
    }
    sort_answer(ans[0],ans[1],ans[2],ans[3],ans[4]);
  }
}

