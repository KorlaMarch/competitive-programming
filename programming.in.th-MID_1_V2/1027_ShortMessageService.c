#include "stdio.h"

int main(){
    int i,j,m,n=7;
    char c,s;
    char out[7] = {};
    int fec[7] = {};
    while((c=getchar())!='!'){
        if(c=='\n'&&n>1){
            for(i=0,m=-1,s=0; i < 7; i++){
                if(!out[i]){
                    if(m==-1||fec[i]<fec[m]){
                        m = i;
                        s=1;
                    }
                    else if(fec[i]==fec[m]) s=0;
                }
            }
            if(m!=-1&&s){
                out[m] = 1;
                n--;
            }
        }else{
            fec[c-'A']++;
        }
    }
    for(i = n=0; i < 7; i++) if(!out[i]) n++;
    printf("%d\n", n);
    for(i = 0; i < n; i++){
        for(j = 0,m = -1; j<7;j++){
            if(!out[j] && (m==-1||fec[m] < fec[j])) m=j;
        }
        printf("%c %d\n", 'A'+m, fec[m]);
        out[m] = 1;
    }
}
