#include "stdio.h"
#include "queue"

typedef struct{
    int w,v;
}item;

class itemCmp{
    public:
    bool operator()(item a, item b){
        if(a.w > b.w){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    std::priority_queue<item, std::vector<item>, itemCmp> q;
    int m,n,i;
    char c;
    item t;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n+m; i++){
        scanf(" %c", &c);
        if(c == 'T'){
            scanf("%d %d", &t.w, &t.v);
            q.push(t);
        }else{
            if(!q.empty()){
                printf("%d\n", q.top().v);
                q.pop();
            }else{
                printf("0\n");
            }
        }
    }
}
