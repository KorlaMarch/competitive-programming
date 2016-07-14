#include <stdio.h>
#include <string.h>

char mook[1100][31];

void addMook(int aSize){
    //sort and add
    scanf("%s", &mook[aSize]);
    if(aSize >= 1){
        int x = aSize;
        char temp[31];
        int cmpRe;
        while(x >= 1){
            cmpRe = strcmp(mook[x], mook[x - 1]);
            if(cmpRe < 0 || mook[x - 1][0] == '\0'){
                //switch
                strcpy(temp, mook[x]);
                strcpy(mook[x], mook[x - 1]);
                strcpy(mook[x - 1], temp);
                x--;
            }else if(cmpRe == 0){
                mook[x][0] = '\0';
                x--;
            }else{
                break;
            }
        }
    }
}

int main(){
    int n, x;
    scanf("%d", &n);
    for(x = 0; x < n; x++){
        addMook(x);
    }

    //output
    for(x = 0; x < n; x++){
        if(mook[x][0] != '\0'){
            printf("%s\n", mook[x]);
        }
    }
}
