#include "stdio.h"
#include "map"

int n,k,i,x,y;
std::map<int,int> tp;

int canPlace(){
    int c = 0;
    std::map<int,int>::iterator it=tp.begin();
    for(; it!=tp.end() && it->first <= y; ++it){
        if(it->first > x && c>=k) return 0;
        c += it->second;
    }
    if(it!=tp.end()&&c>=k) return 0;
    return 1;
}

int main(){
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        if(canPlace()){
            printf("yes\n");
            tp[x]++;
            tp[y+1]--;
        }else{
            printf("no\n");
        }
    }
}
