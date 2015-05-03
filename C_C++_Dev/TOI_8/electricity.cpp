#include "stdio.h"
#include "queue"

class cmp{
    public:
        bool operator()(int a, int b){
            return a > b ? true : false;
        }
};

int main(){
    std::priority_queue<int,std::vector<int>,cmp> minHeap;
    std::priority_queue<int,std::vector<int>,cmp> delList;
    int n,k,i;
    int price[500000];
    scanf("%d%d", &n, &k);
    scanf("%d", &price[0]);
    for(i = 1; i < n; i++){
        scanf("%d", &price[i]);
        minHeap.push(price[i-1]);
        if(i-k > 0){
            delList.push(price[i-k-1]);
        }
        while(!delList.empty() && delList.top() == minHeap.top()){
            delList.pop();
            minHeap.pop();
        }
        price[i] += minHeap.top();
        //printf("i = %d add %d = %d\n", i, minHeap.top(), price[i]);
    }
    printf("%d\n", price[n-1]);
}
