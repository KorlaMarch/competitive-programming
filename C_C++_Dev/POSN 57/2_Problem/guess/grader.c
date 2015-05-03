#include "player.c"
#include "grader.h"
#include <stdio.h>

static int N,J,g,n;

int bigger(int K) {
   return J > K;
}

int main(){
   scanf("%d%d",&N,&J);
   g = play(N);
   if (g == J) {
      printf("Correct %d\n",J);
   } else {
      printf("Incorrect %d should be %d\n",g,J);
   }
}
