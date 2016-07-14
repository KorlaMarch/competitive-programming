#include "stdio.h"

#define SIZE 500

int main(){
    int n, m;
    int i,f,t,w;
    int adjMartrix[SIZE][SIZE] = {};
    int MSTadjMartrix[SIZE][SIZE] = {};
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++){
        scanf(" %c %c %d", &f, &t, &w);
        adjMartix[f][t] = w;
        adjMartix[t][f] = w;
    }

}
