#include "stdio.h"

int k,m,n,i;
char logic[16];
char a[100][32];
char b[100][32];
int na[100],nb[100];
char isUsed[16];

int getTruth(char a[100][32], int na[100], int n){
    int i,j,t;
    for(i = 0; i < n; i++){
        for(j = 0,t=0; j < na[i] && !t; j++){
            if((a[i][j]>='A'&&a[i][j]<='Z'&&!logic[a[i][j]-'A'])||(a[i][j]>='a'&&a[i][j]<='z'&&logic[a[i][j]-'a'])) t = 1;
        }
        if(!t) return 0;
    }
    return 1;
}

int checkEQ(int d){
    int i,j;
    for(;d<16&&!isUsed[d];d++);
    if(d>=16){
        return !getTruth(a,na,n)||getTruth(b,nb,m);
    }
    logic[d] = 0;
    if(!checkEQ(d+1)) return 0;
    logic[d] = 1;
    if(!checkEQ(d+1)) return 0;
    return 1;
}

void getInput(char a[100][32], int na[100], int n){
    int i,j,c;
    char s1;
    for(i = 0; i < n; i++){
        scanf("%d", &na[i]);
        for(j = 0; j < na[i]; j++){
            scanf(" %c%c", &s1, &a[i][j]);
            isUsed[a[i][j]-'a'] = 1;
            if(s1=='-') a[i][j] -= 0x20;
        }
    }
}
int main(){
    int j;
    scanf("%d", &k);
    for(i = 0; i < k; i++){
        scanf("%d%d",&n,&m);
        for(j = 0; j < 16; j++) isUsed[j] = 0;
        getInput(a,na,n);
        getInput(b,nb,m);
        if(checkEQ(0)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}
