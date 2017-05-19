#include "koala.h"

int minValue(int N, int W) {
    int b[100];
    int r[100];
    for(int i = 0; i < N; i++){
        b[i] = 0;
    }
    b[0] = 1;
    playRound(b,r);
    if(r[0]<2){
        return 0;
    }
    for(int i = 1; i < N; i++){
        if(r[i]<1) return i;
    }
    return -1;
}

int maxValue(int N, int W) {
    int b[100];
    int r[100];
    bool isTop[100];
    int topc = 100;
    for(int i = 0; i < N; i++){
        isTop[i] = true;
    }

    while(1){
        int di = topc/W;
        for(int i = 0; i < N; i++){
            if(isTop[i]){
                b[i] = di;
            }else{
                b[i] = 0;
            }
        }

        playRound(b,r);

        //top 50
        for(int i = 0; i < N; i++){
            if(r[i]>b[i]){
                isTop[i] = true;
                topc++;
            }else isTop[i] = false;
        }

        if(topc==1){
            for(int i = 0; i < N; i++){
                if(isTop[i]) return i;
            }
        }
    }
    return 0;
}

int greaterValue(int N, int W) {
    // TODO: Implement Subtask 3 solution here.
    // You may leave this function unmodified if you are not attempting this
    // subtask.
    return 0;
}

void allValues(int N, int W, int *P) {
    if (W == 2*N) {
        // TODO: Implement Subtask 4 solution here.
        // You may leave this block unmodified if you are not attempting this
        // subtask.
    } else {
        // TODO: Implement Subtask 5 solution here.
        // You may leave this block unmodified if you are not attempting this
        // subtask.
    }
}