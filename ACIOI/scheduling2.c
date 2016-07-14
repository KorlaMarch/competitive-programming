#include "stdio.h"

int quP[5001];
int quQ[5000];
int t,n,m,i,k,p,q,t,qf,ql,s;
void enqueue(int p,int q){
    quP[qf] = p;
    quQ[qf] = q;
    qf = (qf+1)%n;
}
void dequeue(){
    ql = (ql+1)%n;
}
int main(){
    scanf("%d",&t);
    for(k=0;k<t;k++){
        scanf("%d%d",&n,&m);
        for(qf=ql=t=s=i=0;i<n;i++){
            scanf("%d%d",&p,&q);
            //en

        }
    }
}
