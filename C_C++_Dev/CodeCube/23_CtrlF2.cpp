#include "stdio.h"
#include "string"
int n,m,i,c;
std::string a,b;
char x[1000001],y[1000001];

int main(){
    scanf("%d %d %s %s",&n,&m,x,y);
    a=x,b=y;
    for(i = a.find(b); i!=-1; c++,i = a.find(b,i+1));
    printf("%d\n",c);
}
