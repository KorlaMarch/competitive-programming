#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "queue"

using namespace std;

typedef struct{
    char* s;
    int digit;
}num;

void reverseNum(num a){
    int i;
    char c;
    for(i = 0; i < a.digit-i-1; i++){
        c = a.s[i];
        a.s[i] = a.s[a.digit-i-1];
        a.s[a.digit-i-1] = c;
    }
}

void printNum(num a){
    int i;
    for(i = a.digit-1; i >= 0; i--){
        putchar(a.s[i]);
    }
    printf("\n");
}

int main(){
    queue<num> digitNum[10];
    queue<num> mainlist;
    int n,i,j;
    num temp;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        temp.s = (char*)malloc(sizeof(char)*350);
        scanf(" %s", temp.s);
        temp.digit = strlen(temp.s);
        reverseNum(temp);
        mainlist.push(temp);
    }
    for(i = 0; !mainlist.empty(); i++){
        while(!mainlist.empty()){
            temp = mainlist.front();
            mainlist.pop();
            if(i >= temp.digit){
                printNum(temp);
            }else{
                digitNum[temp.s[i]-'0'].push(temp);
            }
        }
        for(j = 0; j < 10; j++){
            while(!digitNum[j].empty()){
                mainlist.push(digitNum[j].front());
                digitNum[j].pop();
            }
        }
    }

}
