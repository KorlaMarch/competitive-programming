#include "stdio.h"

int q,i,j,k,p,s;
char a[1000050],b[1000050],c[1000050];
int lm[1000050];
int st[1000050];
int prev[1000050],next[1000050];
bool flag;
int kmp[1000050];

void delP(int s, int i, int k){
    int j;
    //printf("\nCALL PU %d %d %d\n",s,i,k);
    p -= k;
    /*for(j = i; k > 0; j = prev[j]){
        //printf("J = %d %d %c %c\n",j,p,c[p-1],b[k-1]);
        if(c[p-1]!=b[k-1]) while(1);
        p--;
        k--;
    }*/
}

int findNext(int i, int j){
    for(; j > 0; j--,i = next[i]);
    return i;
}

int main(){
    for(scanf("%d",&q); q > 0; q--){
        scanf(" %s %s",a,b);
        for(i = 0; a[i]; i++){
            prev[i] = i-1;
            next[i] = i+1;
        }
        prev[i] = i-1;
        next[i] = i+1;
        //Gen KMP
        for(i=1,k=0; b[i]; i++){
            while(k>0&&b[i]!=b[k]){
                k = kmp[k-1];
            }
            if(b[i]==b[k]) k++;
            kmp[i] = k;
            //printf("KMP %d = %d\n",i,k);
        }

        for(i=j=p=s=0; a[i]; i++){
            //printf("%c(%d):%c(%d)",b[j],j,a[i],i);
            c[p++] = a[i];
            flag = false;
            if(a[i]==b[j]){
                j++;
                if(b[j]=='\0'){
                    delP(s,i,j);
                    prev[i+1] = prev[s];
                    next[prev[i+1]] = i+1;
                    if(prev[i+1]>=0&&lm[prev[i+1]]){
                        s = st[prev[i+1]];
                        j = lm[prev[i+1]];
                    }else{
                        j = 0;
                        s = i+1;
                    }
                }
            }else{
                while(j>0&&b[j]!=a[i]){
                    s = findNext(s,j-kmp[j-1]);
                    j = kmp[j-1];
                    //printf("j = %d\n",j);
                }
                //if(j) j--;
                if(a[i]==b[j]){
                    //printf("J=%d\n",j);
                    i--;
                    p--;
                    flag = true;
                }else s = i+1;
            }
            //printf("%d %d %d : %d\n",j,s,p,prev[flag?(i+1):i+1]);
            if(!flag){
                lm[i] = j;
                st[i] = s;
            }
        }
        /*printf("END %d %d %d\n",s,i,prev[i]);
        pushP(s,prev[i]);*/
        c[p] = '\0';
        if(p) printf("%s\n",c);
        else printf("No COI Secret Code\n");
    }
}
