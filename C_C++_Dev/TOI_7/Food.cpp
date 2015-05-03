#include "stdio.h"
#include "string.h"

bool Food[8];
int n;

void listFood(int k, int d, char s[]){
    int i;
    char temp[128];
    if(d >= n){
        printf("%s%d\n",s,k+1);
        return;
    }

    Food[k] = true;
    for(i = 0; i < n; i++){
        if(!Food[i]){
            sprintf(temp, "%s%d ", s, k+1);
            listFood(i,d+1,temp);
        }
    }
    Food[k] = false;
}

int main(){
    bool dangerF[8] = {};
    int m,t,i,j;
    char s1[20];
    s1[0] = '\0';
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d", &t);
        dangerF[t-1] = true;
    }
    for(i = 0; i < n; i++){
        if(!dangerF[i]){
            for(j = 0; j < n; j++){
                Food[j] = false;
            }
            listFood(i,1,s1);
        }
    }
}
