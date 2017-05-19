#include "sort_weight.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>


#define SORT_INIT      0
#define SORT_READINPUT 1
#define SORT_ANSWERED  2

static int n;
static int wcounter = 0;
static std::vector<int> coins(5);
static int state = SORT_INIT;
static std::vector<int> expected_result(5);
static int answered = 0;

static void sort_die()
{
  printf("Wrong interaction.  Program terminated.\n");
  exit(1);
}

int get_case() {
  return 1;
}

void sort_init()
{
  std::map<int,int> m;
  for(int i = 0;i < 5;i++) {
    int a;
    scanf("%d",&a);
    coins[i] = a;
    m[a] = i;
  }
  wcounter = 0;
  n = 5;

  int i = 0;
  for (auto x : m) {
    expected_result[i] = x.second;
    i++;
  }

  state = SORT_READINPUT;
}

int sort_weight(int lid, int rid)
{
  if (wcounter >= 7)
    sort_die();
  if(state != SORT_READINPUT)
    sort_die();

  wcounter++;

  if (lid == rid)
    sort_die();

  if (lid < 0 || lid >= 5 || rid < 0 || rid >= 5)
    sort_die();

  if(coins[lid] < coins[rid])
    return -1;
  else
    return 1;
}

void sort_answer(int a1,int a2,int a3,int a4,int a5)
{
  if(state != SORT_READINPUT)
    sort_die();

  state = SORT_ANSWERED;

  if (expected_result[0] == a1 &&
      expected_result[1] == a2 &&
      expected_result[2] == a3 &&
      expected_result[3] == a4 &&
      expected_result[4] == a5)
    printf("Correct (%d)\n",wcounter);
  else{
    printf("Incorrect (%d)\n",wcounter);
    printf("Expect : ");
    for(int i = 0; i < 5; i++) printf("%d ",expected_result[i]);
    printf("\nGet : %d %d %d %d %d\n",a1,a2,a3,a4,a5);
  }

  answered++;
  if (answered == get_case()) exit(0);
}

