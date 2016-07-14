#include "cave.h"

/*int tryCombination(int S[]);
void answer(int S[], int D[]);*/

int S[5005],D[5005],A[5005];

void flip(int A[], int x, int y){
    int i;
    for(i = x; i <= y; i++){
        if(S[i]==-1) A[i] = !A[i];
        else A[i] = S[i];
    }
}

void findSW(int x, int y, int d){
    if(x==y){
        //printf("D = %d : %d %d\n",d,x,y);
        S[x] = A[x];
        D[x] = d;
        return;
    }
    flip(A,x,(x+y)/2);
    int i = tryCombination(A);
    //printf("CH %d %d %d : %d\n",x,y,d,i);
    flip(A,x,(x+y)/2);
    if(i>d||i==-1){
        findSW((x+y)/2+1,y,d);
    }else{
        findSW(x,(x+y)/2,d);
    }
}

void exploreCave(int N) {
    int i,j,r;
    for(i = 0; i < N; i++){
        S[i] = -1;
        D[i] = A[i] = 0;
    }
    for(i = 0; i < N; i++){
        r = tryCombination(A);
        if(r<=i&&r!=-1){
            flip(A,0,N-1);
        }
        findSW(0,N-1,i);
    }
    answer(S,D);
}
