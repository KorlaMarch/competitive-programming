#include <cstdlib>
#include <set>
#include <cstdio>

using namespace std;

set<pair<int,int> > used;

main()
{
  int n = 100000;

  int a = 10000000;
  int b = 10000000;

  printf("%d\n",n);
  for(int i=0; i<n; i++) {
    int x = (lrand48() % (2*a)) - a;
    int y = (lrand48() % (2*b)) - b;

    pair<int,int> p = make_pair(x,y);

    while(used.find(p) != used.end()) {
      x = (lrand48() % (2*a)) - a;
      y = (lrand48() % (2*b)) - b;

      p = make_pair(x,y);
    }

    printf("%d %d\n",x,y);
    used.insert(p);
  }
}
