#include "stdio.h"
int strlen(char s[]){
    int i;
    for(i=0;s[i];i++);
    return i;
}

int n,m;
char num_s[1001][301];
int order[1000],len[1000];
int q[10][1001],fq[10],lq[10];
void enqueue(int qn,int v){
    q[qn][fq[qn]] = v;
    fq[qn] = (fq[qn]+1)%n;
}
int dequeue(int qn){
    int i = q[qn][lq[qn]];
    lq[qn] = (lq[qn]+1)%n;
    return i;
}
int main(){
    int i,j,k;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf(" %s", num_s[i]);
        len[i] = strlen(num_s[i])-1;
        order[i] = i;
        if(len[i]>m) m = len[i];
    }
    for(i = 0; i <= m; i++){
        //enqueue
        for(j = 0; j < n; j++){
            if(len[order[j]]-i<0){
                enqueue(0,order[j]);
            }else{
                enqueue(num_s[order[j]][len[order[j]]-i]-'0',order[j]);
            }
        }
        //dequeue
        for(j = k = 0; j < 10; j++){
            while(fq[j] != lq[j]){
                order[k++] = dequeue(j);
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("%s\n", num_s[order[i]]);
    }

}
