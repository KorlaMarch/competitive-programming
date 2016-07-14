#include "grader.h"
#include "player.h"

int play(int N){
  int i;
  for (i=15;i>=1;i--) if (bigger(i)) return i+1;
  return 1;
}
