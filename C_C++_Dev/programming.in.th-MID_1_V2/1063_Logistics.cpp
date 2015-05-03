#include "stdio.h"
#include "algorithm"
typedef struct{
    char a[280];
    int ls;
}lis;
char isVisit[28];
lis adj[28][28];

char getchar(int n){
    switch(n){
    case 27:
        return 'Y';
    case 26:
        return 'X';
    default:
        return n+'a';
    }
}
float getSum(int n){
    int i,m;
    float t,sum;
    isVisit[n] = 1;
    if(n==26) return 0.0;
    for(i=0;i<28;i++){
        m = adj[n][i].ls;
        if(!isVisit[i]&&m){
            std::sort(adj[n][i].a,adj[n][i].a+m);
            //printf("Node:%c %c %d %d %d\n", getchar(n),getchar(i),m, adj[n][i].a[m/2],adj[n][i].a[m/2-1]);
            if(m%2==0){
                t = (adj[n][i].a[m/2]+adj[n][i].a[m/2-1])/2.0;
            }else{
                t = adj[n][i].a[m/2];
            }
            sum = getSum(i);
            if(sum!=-1){
                printf("%c %c %.1f\n", getchar(i), getchar(n),t);
                return sum+t;
            }else{
                return -1;
            }
        }
    }
    return -1;
}
int main(){
    int n,i,j,c;
    char a,b;
    float f;
    scanf("%d", &n);
    for(i = 0; i < 28; i++){
        for(j = 0; j < 28; j++){
            adj[i][j].ls = 0;
        }
    }
    for(i = 0; i < n; i++){
        scanf(" %c %c %d", &a, &b, &c);
        if(a=='X') a = 'z'+1;
        else if(a=='Y') a = 'z'+2;
        if(b=='X') b = 'z'+1;
        else if(b=='Y') b = 'z'+2;
        adj[a-'a'][b-'a'].a[adj[a-'a'][b-'a'].ls++] = c;
        adj[b-'a'][a-'a'].a[adj[b-'a'][a-'a'].ls++] = c;
    }
    f = getSum(27);
    if(f!=-1) printf("%.1f\n", f);
    else printf("broken\n");
}
