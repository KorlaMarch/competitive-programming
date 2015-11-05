#include "stdio.h"
typedef struct{
    int h,i;
}bottle;
bottle h[100005];
bottle t[100005];
int bl[100005];
char isBreak[100005];
void merge(bottle a[], int an, bottle b[],int bn){
    int i,j;
    for(i=j=0;i<an||j<bn;){
        if(i<an&&(j>=bn||a[i].h<b[j].h)){
            t[i+j] = a[i];
            i++;
        }else{
            t[i+j] = b[j];
            j++;
        }
    }
}

void mergesort(bottle a[], int n){
    int i;
    if(n<=1) return;
    mergesort(a,n/2);
    mergesort(a+n/2,n-n/2);
    merge(a,n/2,a+n/2,n-n/2);
    for(i = 0; i < n; i++) a[i] = t[i];
}

int main(){
    int i,j,k,ub,n,m,l,bc;
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d",&h[i].h);
        h[i].i = i;
    }
    mergesort(h,n);
    for(i = 0,ub = n-1; i < m; i++){
        scanf("%d",&l);
        for(bc=k=0;ub>=0&&h[ub].h>l;ub--){
            if(!isBreak[h[ub].i]){
                bc++;
                isBreak[h[ub].i] = 1;
                if(h[ub].i>0){
                    bl[k++] = h[ub].i-1;
                }
                if(h[ub].i+1<n){
                    bl[k++] = h[ub].i+1;
                }
            }
        }
        for(j = 0; j < k; j++){
            if(!isBreak[bl[j]]){
                bc++;
                isBreak[bl[j]] = 1;
            }
        }
        printf("%d\n",bc);
    }
}
