#include "stdio.h"

typedef struct{
    int p,q;
}ct;
ct t[100000];
void merge(ct a[], ct b[], int na, int nb){
    int i,j;
    for(i = j = 0; i<na||j<nb;){
        if(i<na&&(j>nb||a[i].p<b[j].p)) t[i+j] = a[i++];
        else t[i+j] = b[j++];
    }
}
void msort(ct a[], int n){
    int i;
    if(n <= 1) return;
    msort(a,n/2);
    msort(a+n/2,n-n/2);
    merge(a,a+n/2,n/2,n-n/2);
    for(i = 0; i < n; i++) a[i] = t[i];
}
void swap(ct* a, ct* b){
    ct t = *a;
    *a = *b;
    *b = t;
}
void rhup(ct heap[], int p){
    if(!p) return;
    if(heap[p].q<heap[(p-1)/2].q){
        swap(heap+p,heap+(p-1)/2);
        rhup(heap,(p-1)/2);
    }
}
void rhdown(ct heap[], int n, int p){
    int i = p*2+2<n?heap[p*2+1].q<heap[p*2+2].q?p*2+1:p*2+2:p*2+1<n?p*2+1:0;
    if(i&&heap[i].q<heap[p].q){
        swap(heap+i,heap+p);
        rhdown(heap,n,i);
    }
}
int countries(int N, int *P, int *Q){
    int i,n=0,mx=0;
    ct co[10000],heap[10000];
    for(i = 0; i < N; i++){
        co[i].p = P[i];
        co[i].q = Q[i];
    }
    msort(co,N);
    for(i = 0; i < N; i++){
        while(n>0&&heap[0].q<=co[i].p){
            swap(heap, heap+(--n));
            rhdown(heap, n, 0);
        }
        //enq
        heap[n++] = co[i];
        rhup(heap, n-1);
        if(n > mx) mx = n;
    }
    return mx;
}

int main(){
    int n,i;
    int p[10000],q[10000];
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&p[i],&q[i]);
    }
    printf("%d\n", countries(n,p,q));
}
