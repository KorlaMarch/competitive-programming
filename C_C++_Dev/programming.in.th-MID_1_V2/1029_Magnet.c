#include "stdio.h"
int m,n,q,a,k,i,j,x,mi;
int mg[200001];
int t[200001];

void merge(int a[], int b[], int na, int nb){
    int i,j;
    for(i=j=0; i<na||j<nb;){
        if(i<na&&(j>=nb||a[i]<b[j])) t[i+j] = a[i++];
        else t[i+j] = b[j++];
    }
}
void msort(int a[], int n){
    int i;
    if(n <= 1) return;
    msort(a,n/2);
    msort(a+n/2,n-n/2);
    merge(a,a+n/2,n/2,n-n/2);
    for(i = 0; i < n; i++) a[i] = t[i];
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(i = 0; i < m; i++){
        scanf("%d%d",&a,&k);
        mg[i*2] = a;
        mg[i*2+1] = a+k;
    }
    msort(mg,m*2);
    for(i = 0, j = 0; i < m*2; i++){
        if(j<1||mg[j-1] != mg[i]){
            mg[j++] = mg[i];
        }else{
            j--;
        }
    }
    m = j;
    for(k = 0; k < q; k++){
        scanf("%d",&x);
        if(m == 0){
            printf("%d\n", n);
            return 0;
        }
        for(i=0,j=m-1; i<=j;){
            mi = (i+j)/2;
            if(x==mg[mi]){
                j = mi;
                break;
            }else if(x<mg[mi]) j = mi-1;
            else i = mi+1;
        }
        if(j+1>=m){
            printf("%d\n", n-mg[j]+1);
        }else if(j<0){
            printf("%d\n", mg[j+1]-1);
        }else{
            printf("%d\n", mg[j+1]-mg[j]);
        }
    }
}
