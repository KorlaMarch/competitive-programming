#include "pointlib.h"
#include <cstdio>

static int n;
static int x[10010];
static int y[10010];

int point_init()
{
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d %d",&x[i],&y[i]);
  return n;
}

int query(int i, int j)
{
  return ((x[i] > x[j] ? x[i] - x[j] : x[j] - x[i]) +
          (y[i] > y[j] ? y[i] - y[j] : y[j] - y[i]));
}
