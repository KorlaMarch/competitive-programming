#include "hollib.h"
#include "stdio.h"

int t,i,k,n,r1,r2,r3;
int llist[301];
int rlist[301];
int ans[3][3] = {{1,2,-1},{2,0,1},{-1,1,2}};
void setrl(int s, int b){
    int i;
    for(i = 0; i < s; i++){
        rlist[i] = i+b;
    }
}

int main(){
    t = hol_init_all();
    for(i = 0; i <= 300; i++){
        llist[i] = i;
    }
    for(k = 1; k <= t; k++){
        n = hol_init();
        if(n==5){
            rlist[0] = 2; rlist[1] = 3;
            r1 = hol_weight(2, llist, 2, rlist);
            if(r1==0){
                rlist[0] = 4;
                r2 = hol_weight(1, llist, 1, rlist);
                if(r2==-1) hol_answer(2);
                else hol_answer(1);
            }else{
                rlist[0] = 1;
                r2 = hol_weight(1, llist, 1, rlist);
                if(r1==-1){
                    if(r2) hol_answer(1);
                    else hol_answer(2);
                }else{
                    if(r2) hol_answer(2);
                    else hol_answer(1);
                }
                //printf("GET %d %d %d\n",r1,r2,r3);
            }
        }else if(n%3==0){
            setrl(n/3,n/3);
            r1 = hol_weight(n/3, llist, n/3, rlist);
            setrl(n/3,n/3*2);
            r2 = hol_weight(n/3, llist, n/3, rlist);
            hol_answer(ans[r1+1][r2+1]);
        }else{
            setrl(n/3,n/3);
            r1 = hol_weight(n/3, llist, n/3, rlist);
            if(r1==0){
                setrl(n-n/3*2,n/3*2);
                r2 = hol_weight(n-n/3*2, llist, n-n/3*2, rlist);
                if(r2==-1) hol_answer(2);
                else hol_answer(1);
            }else{
                setrl(n/3,n/3*2);
                r2 = hol_weight(n/3, llist, n/3, rlist);
                hol_answer(ans[r1+1][r2+1]);
            }
        }
    }
}
