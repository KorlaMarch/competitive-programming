#include "stdio.h"
#include "list"
int n,c,i,j;
int m[30],l[30],r[30];
char isP[30];
std::list<int> li;

int findBetween(int d){
    int c,i;
    if(d>=c) return 1;
    else if(isP[l[d]]&&isP[r[d]]&&isP[m[d]]){
        for(std::list<int>::iterator it = li.begin(),c=0; it != li.end(); ++it){
            if(*it==l[d]||*it==r[d]) c++;
            else if(*it==m[d]){
                if(c!=1) return 0;
                else return findBetween(d+1);
            }
        }
    }else if(isP[m[d]]){

    }else{

    }
}

int main(){
    scanf("%d%d",&n,&c);
    for(i = 0; i < c; i++){
        scanf("%d%d%d",&m[i],&l[i],&r[i]);
    }
    if(findBetween(0)){
        printf("YES\n");
        for(std::list<int>::iterator it = li.begin(); it != li.end(); ++it){
            printf("%d ",*it);
        }
    }else printf("NO\n");
}
