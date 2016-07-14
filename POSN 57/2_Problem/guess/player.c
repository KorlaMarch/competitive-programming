#include "grader.h"
#include "player.h"

int play(int N){
    int i,j,m;
    for(i=1,j=N; i<=j;){
        m = (i+j)/2;
        if(bigger(m)) i = m+1;
        else j = m-1;
    }
    return i;
}
