#include "stdio.h"
#include "queue"
#include "vector"

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> > pond;
    int n,t,i,j;
    scanf("%d%d", &n, &t);
    for(i = 0; i < n; i++){
        scanf("%d", &j);
        pond.push(j);
    }
    for(i = 0; i < t; i++){
        scanf("%d", &j);
        printf("%d\n", pond.top());
        pond.pop();
        pond.push(j);
    }
}
