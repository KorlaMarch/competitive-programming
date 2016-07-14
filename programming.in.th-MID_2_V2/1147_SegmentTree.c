#include "stdio.h"
int tree[524288];
int pos[262144];
int max(int a, int b){
    return a>b?a:b;
}
void preprocessPosition(int i,int s, int n){
    if(s==1){
        pos[i] = n;
    }else{
        preprocessPosition(i,s/2,n*2+1);
        preprocessPosition(i+s/2,s-s/2,n*2+2);
    }
}
void remax(int i){
    tree[i] = max(tree[i*2+1],tree[i*2+2]);
    if(i) remax((i-1)/2);
}
int findMax(int i,int j,int n,int a,int b){
    int s = j-i+1;
    if(i>b||j<a){
        return -2000000000;
    }else if(i>=a&&j<=b){
        return tree[n];
    }else{
        return max(findMax(i,i+s/2-1,n*2+1,a,b),findMax(i+s/2,j,n*2+2,a,b));
    }
}

int main(){
    int i,n,q,a,b;
    char c;
    scanf("%d%d",&n,&q);
    preprocessPosition(0,n,0);
    for(i = 0; i < q; i++){
        scanf(" %c %d %d", &c, &a, &b);
        if(c=='U'){
            tree[pos[a-1]] = b;
            if(pos[a-1]) remax((pos[a-1]-1)/2);
        }else{
            printf("%d\n",findMax(0,n-1,0,a-1,b-1));
        }
    }
}
