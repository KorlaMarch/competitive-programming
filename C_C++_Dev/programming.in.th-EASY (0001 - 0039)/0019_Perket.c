#include <stdio.h>

int min(int a, int b){
    if(a == -1){
        return b;
    }else if(b == -1){
        return a;
    }else{
        return a < b ? a : b;
    }
}

int abs(int n){
    return n < 0 ? n * -1 : n;
}
int findSB(int s[], int b[], int Size, int allS, int allB){
    int x;
    if(Size <= 0){
        return -1;
    }
    int minV = abs(allS - allB);
    for(x = 1; x < Size; x++){
        //with first
        minV = min(minV, findSB(s + x, b + x, Size - x, allS * s[x], allB + b[x]));
    }
    return minV;
}

int main(){
    int type;
    int s[10];
    int b[10];
    int x;
    scanf("%d", &type);
    for(x = 0; x < type; x++){
        scanf("%d%d", &s[x], &b[x]);
    }
    //printf("%d %d\n", s[0], b[0]);
    int minV = abs(s[0] - b[0]);
    for(x = 0; x < type; x++){
        //with first
        minV = min(minV, findSB(s + x, b + x, type - x, s[x], b[x]));
    }
    printf("%d", minV);
    return 0;
}
