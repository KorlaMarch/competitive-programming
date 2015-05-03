#include "stdio.h"

int strlen(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}

double atof(char s[]){
    double f = 0.0;
    int n=0,i;
    for(i=0; s[i] != '.'; i++){
        n *= 10;
        n += s[i]-'0';
    }

    for(i=strlen(s)-1; s[i] != '.'; i--){
        f += s[i]-'0';
        f /= 10.0;
    }

    return f+n;
}

int main(){
    char s[64];
    gets(s);
    printf("%.10f\n", atof(s));
}
