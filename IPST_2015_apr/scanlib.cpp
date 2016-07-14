#include "scanlib.h"
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define MAX_K 100

typedef pair<pair<int,int>, pair<int,int> > ipp;

static int n,sol_k;
static ipp sol_items[MAX_K];
static ipp out_items[MAX_K];
static int detect_count;

int scan_init()
{
  scanf("%d %d",&n,&sol_k);
  for(int i=0; i<sol_k; i++) {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    sol_items[i].first.first = a;
    sol_items[i].first.second = b;
    sol_items[i].second.first = c;
    sol_items[i].second.second = d;
  }
  sort(sol_items, sol_items+sol_k);
  detect_count = 0;
  return n;
}

int detect(int r1, int c1, int r2, int c2)
{
  detect_count++;
    //printf("ASK %d %d %d %d",r1,c1,r2,c2);
  if(detect_count > 2000) {
    printf("Too many questions\n");
    exit(0);
  }

  if((r1 > r2) || (c1 > c2) ||
     (r1 < 1) || (r2 > 2) ||
     (c1 < 1) || (c2 > n)) {
    printf("Interaction error\n");
    exit(0);
  }

  int count = 0;
  for(int i=0; i<sol_k; i++)
    if((r1 <= sol_items[i].second.first) &&
       (r2 >= sol_items[i].first.first) &&
       (c1 <= sol_items[i].second.second) &&
       (c2 >= sol_items[i].first.second))
      count++;

  return count;
}

void scan_report(int k, int items[][4])
{
  printf("%d calls to detect.\n",detect_count);

  if(k != sol_k)
    printf("Incorrect\n");
  else {
    for(int i=0; i<k; i++) {
      out_items[i].first.first = items[i][0];
      out_items[i].first.second = items[i][1];
      out_items[i].second.first = items[i][2];
      out_items[i].second.second = items[i][3];
      printf("GET %d %d %d %d\n",items[i][0],items[i][1],items[i][2],items[i][3]);
    }
    sort(out_items, out_items+k);

    bool ok = true;
    for(int i=0; i<k; i++) {
      if(out_items[i] != sol_items[i])
        ok = false;
    }
    if(ok)
      printf("Correct\n");
    else
      printf("Incorrect\n");
  }
  exit(0);
}

