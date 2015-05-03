#include "stdio.h"
typedef struct{
    int a,b;
}stair;
stair t[100000];
void merge(stair a[], stair b[], int na, int nb){
    int i,j;
    for(i=j=0;i<na||j<nb;){
        if(i<na&&(j>=nb||a[i].a<b[j].a)) t[i+j] = a[i++];
        else t[i+j] = b[j++];
    }
}

void msort(stair a[], int n){
    int i;
    if(n<=1) return;
    msort(a,n/2);
    msort(a+n/2, n-n/2);
    merge(a,a+n/2,n/2,n-n/2);
    for(i = 0; i < n; i++) a[i] = t[i];
}

int main(){
    int k,n,m,i,max;
    stair st[100000];
    int can_r[10001] = {0,1};
    scanf("%d%d%d", &k,&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d",&st[i].a,&st[i].b);
    }
    msort(st, m);
    for(i = max = 0; i < m; i++){
        if(can_r[st[i].a]){
            if(can_r[st[i].b]==0||can_r[st[i].a]+1<can_r[st[i].b]) can_r[st[i].b] = can_r[st[i].a]+1;
            if(can_r[st[i].b]<=k+1&&st[i].b>max){
                max = st[i].b;
            }
        }
    }
    printf("%d\n",max);
}
