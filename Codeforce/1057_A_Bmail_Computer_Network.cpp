#include "stdio.h"

int n;
int p[200005];
int ori[200005];

bool recur(int i, int d){
    ori[d] = i;

}

int main(){
    scanf("%d",&n);

    for(int i = 1; i < n; i++){
        scanf("%d", &p[i]);
    }

    recur(i, d);
}
