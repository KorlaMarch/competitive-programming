#include "stdio.h"
int nc,ns,c,s,i;
int qlm,qfm;
int ql[11],qf[11],cp[11];
int que[11][10001];
int map[10001];
char ch;
int main(){
    scanf("%d%d", &nc, &ns);
    for(i = 0; i < ns; i++){
        scanf("%d%d", &c, &s);
        map[s] = c;
    }
    for(i = 0; i <= nc; i++) cp[i] = -1;
    while(1){
        scanf(" %c", &ch);
        if(ch=='E'){
            scanf("%d", &s);

            if(cp[map[s]] == -1){
                cp[map[s]] = qfm;
                qfm = (qfm+1)%11;
            }
            i = cp[map[s]];
            que[i][qf[i]] = s;
            qf[i] = (qf[i]+1)%10001;
        }else if(ch=='D'){
            if(qlm == qfm){
                printf("empty\n");
            }else{
                s = que[qlm][ql[qlm]];
                printf("%d\n", s);
                ql[qlm] = (ql[qlm]+1)%10001;
                if(ql[qlm]==qf[qlm]){
                    cp[map[s]] = -1;
                    qlm = (qlm+1)%11;
                }
            }
        }else{
            printf("0\n");
            break;
        }
    }

}
