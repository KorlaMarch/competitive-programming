#include "stdio.h"
#include "algorithm"
int i,n,v,pc,nc,pn,nn;
char c;
char s[105];
int pcA[105];
int ncA[105];
int main(){
    pc = 1;
    s[0] = '+';
    for(i = 0, n = 1; ; i++){
        scanf(" %c", &c);
        if(c=='=') break;
        else if(c!='?'){
            s[n++] = c;
            if(c=='+') pc++;
            else nc++;
        }
    }
    for(i = n-1; i >= 0; i--){
        if(s[i]=='+') pcA[i]++;
        else ncA[i]++;
        if(i){
            pcA[i-1] = pcA[i];
            ncA[i-1] = ncA[i];
        }
    }
    scanf("%d",&v);
    if(v*pc-nc>=v&&pc-v*nc<=v){
        printf("Possible\n");
        if(pc-nc<=v){
            pn = v+nc;
            for(i = 0; i < n; i++){
                if(i) printf(" %c ",s[i]);
                if(s[i]=='+'){
                    printf("%d",std::min(v,pn-pcA[i+1]));
                    pn -= std::min(v,pn-pcA[i+1]);
                }else printf("1");
            }
        }else{
            nn = pc-v;
            for(i = 0; i < n; i++){
                if(i) printf(" %c ",s[i]);
                if(s[i]=='-'){
                    printf("%d",std::min(v,nn-ncA[i+1]));
                    pn -= std::min(v,nn-ncA[i+1]);
                }else printf("1");
            }
        }
        printf(" = %d\n",v);
    }else printf("Impossible\n");
}
