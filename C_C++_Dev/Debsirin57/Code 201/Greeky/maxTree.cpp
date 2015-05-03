#include <stdio.h>

typedef struct node{
        int value;
        int leftID;       
        int rightID;
}Node;

int main(){
    Node no[100];
    int size, x, n;
    int workingNode = 0;
    int maxV;
    
    scanf("%d", &size);
    for(x = 0; x < size; x++){
          scanf("%d %d %d", &no[x].value, &no[x].leftID, &no[x].rightID);
    }
    
    maxV = no[0].value;
    while(no[workingNode].leftID != -1 || no[workingNode].rightID != -1){
          workingNode = no[no[workingNode].leftID].value > no[no[workingNode].rightID].value ? no[workingNode].leftID : no[workingNode].rightID;
          maxV += no[workingNode].value;                                   
    }
    
    printf("MaxV = %d", maxV);
    
    scanf("%d", &n);
    return 0;
}
