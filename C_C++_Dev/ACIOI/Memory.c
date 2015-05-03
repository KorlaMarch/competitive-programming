#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char in[8];
int scanTypeSize(){
    int i,j;
    scanf(" %s" , in);
    if(!strcmp(in,"bool")){
        return 1;
    }else if(!strcmp(in,"char")){
        return sizeof(char);
    }else if(!strcmp(in,"short")){
        scanf(" %s", in);
        return sizeof(short int);
    }else if(!strcmp(in,"int")){
        return sizeof(int);
    }else if(!strcmp(in,"float")){
        return sizeof(float);
    }else if(!strcmp(in,"long")){
        scanf(" %s", in);
        if(!strcmp(in,"int")){
            return 4;
        }else{
            scanf(" %s", in);
            return sizeof(long long int);
        }
    }else if(!strcmp(in,"double")){
        return sizeof(double);
    }
    return -1;
}

int main(){
    char size[6];
    int n;
    int i,len,cap,j;

    scanf("%d\n", &n);
    for(i = 0; i < n; i++){
        scanf(" %s", size);
        len = strlen(size);
        cap = 1;
        switch(size[len-2]){
        case 'M':
            cap = 1024;
        case 'K':
            cap *= 1024;
            size[len-2] = '\0';
            break;
        default:
            size[len-1] = '\0';
            break;
        }
        cap *= atoi(size);
        j = scanTypeSize();
        printf("%d\n", cap/j);
    }
}
