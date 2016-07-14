#include "stdio.h"
#include "stack"

int main(){
    std::stack<int> s;
    int preOrderA[100000];
    int postOrderA[100000];
    int leave_node[100000];
    int leave_size = 0;
    int n,i,j;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &preOrderA[i]);
    }
    for(i = 0; i < n; i++){
        scanf("%d", &postOrderA[i]);
    }
    s.push(preOrderA[0]);
    for(i = 1,j = 0; !s.empty();){
        if(s.top() == postOrderA[j]){
            leave_node[leave_size] = s.top();
            leave_size++;
            while(!s.empty() && s.top() == postOrderA[j]){
                //printf("s pop %d\n",s.top());
                s.pop();
                j++;
            }
        }else{
            s.push(preOrderA[i]);
            //printf("s push %d\n",preOrderA[i]);
            i++;
        }
    }
    printf("%d\n",leave_size);
    for(i = 0; i < leave_size; i++){
        printf("%d ", leave_node[i]);
    }
}
