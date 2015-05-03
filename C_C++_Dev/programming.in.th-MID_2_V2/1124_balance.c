#include "stdio.h"
#define HASH_SIZE 2000003
typedef struct{
    int k;
    char v;
}pair;
pair hash_map[HASH_SIZE];

void insert(int k, char v){
    int i = k%HASH_SIZE,j = k%100003;
    if(!j) j = 100003;
    while(hash_map[i].v) i = (i+j)%HASH_SIZE;
    hash_map[i].k = k;
    hash_map[i].v = v;
}

char getV(int k){
    int i = k%HASH_SIZE,j = k%100003;
    while(hash_map[i].v){
        if(hash_map[i].k==k) return hash_map[i].v;
        i = (i+j)%HASH_SIZE;
    }
    return 0;
}

void genWeight(int sum, int d, int u, int m){
    if(d>=20){
        insert(sum,u);
    }else{
        genWeight(sum,d+1,u,m*3);
        genWeight(sum+m,d+1,u+1,m*3);
    }
}

int main(){
    int n,i,j;
    genWeight(0,0,1,1);
    scanf("%d",&n);
    for(i = 0; i < HASH_SIZE; i++){
        printf("%d\n",i);
        if(hash_map[i].v&&hash_map[i].k>=n){
            printf("in:%d %d\n",hash_map[i].v,hash_map[i].k);
            j = getV(hash_map[i].k-n);
            if(j){
                printf("%d %d\n",j+hash_map[i].v-2,hash_map[i].k);
                break;
            }
        }
    }
}
