#include <stdio.h>
#include <stack>

typedef struct node{
        int value;
        int parentID;
        int leftID;       
        int rightID;
}Node;

using std::stack;

int main(){
    stack<int> part;
    Node no[100];
    int size, x, n;
    int workingNode = 0;
    int maxV = 0;
    
    scanf("%d", &size);
    no[0].parentID = -1;
    for(x = 0; x < size; x++){
          scanf("%d %d %d", &no[x].value, &no[x].leftID, &no[x].rightID);
          if(no[x].value > maxV){
               maxV = no[x].value;
               workingNode = x;
          }
          no[no[x].leftID].parentID = x;
          no[no[x].rightID].parentID = x;
    }
    
    
    maxV = 0;
    
    //lookdown
    while(no[workingNode].leftID != -1 || no[workingNode].rightID != -1){
          workingNode = no[no[workingNode].leftID].value > no[no[workingNode].rightID].value ? no[workingNode].leftID : no[workingNode].rightID;                               
    }
    
    //lookup
    while(no[workingNode].parentID != -1){
          maxV += no[workingNode].value; 
          part.push(workingNode);                     
          workingNode = no[workingNode].parentID;                                 
    }
    part.push(workingNode);
    maxV += no[workingNode].value;
    
    printf("MaxV = %d\n", maxV);
    printf("Part = ");
    while(!part.empty()){
        printf("%d ", part.top());
        part.pop();                  
    }
    
    scanf("%d", &n);
    return 0;
}
