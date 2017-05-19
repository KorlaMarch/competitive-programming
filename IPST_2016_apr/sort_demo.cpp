#include <iostream>
#include <vector>

#include "sort_weight.h"

using namespace std;


int main() {
  int T = get_case();
  while (T--) {
    sort_init();

    int a,b,c;
    a = sort_weight(0,1);
    b = sort_weight(1,2);
    c = sort_weight(2,3);

    if (a == -1 && b == -1 && c == -1)
      sort_answer(0,1,2,3,4);
    else
      sort_answer(4,3,2,1,0);
  }
}

