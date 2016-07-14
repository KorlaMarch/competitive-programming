#include "stdio.h"
#include "stdlib.h"

int strlen(char c[]){
    int i;
    for(i = 0; c[i] != '\0'; i++);
    return i;
}

int HorspoolMatching(char text[], char patten[]){
    int t[256];
    int i,j,len, len2;

    if(patten[0] == '\0'){
        return -1;
    }
    //gen shift table
    len = strlen(patten);
    len2 = strlen(text);
    for(i = 0; i < 256; i++){
        t[i] = len;
    }

    for(i = 0; i+1 < len; i++){
        t[patten[i]] = len-i-1;
    }
    printf("len1 = %d len2 = %d\n", len, len2);
    printf("%s\n", text);
    //strat finding patten
    for(i = len-1; i < len2; i+=t[text[i]]){
        //printf("%d\n", i);
        for(j = 0; j <= i-len; j++) putchar(' ');
        printf("%s\n",patten);

        for(j = len-1; j >= 0 && patten[j] == text[i-len+j+1]; j--);
        if(j == -1){
            return i-len+1;
        }

    }
    return -1;
}

int BoyerMooreMatching(char text[], char patten[]){
    int t[256];
    int len = strlen(patten);
    int len2 = strlen(text);
    int *d2 = (int*)malloc(sizeof(int)*len);
    int i,j,k,d;

    //gen shift table
    for(i = 0; i < 256; i++){
        t[i] = len;
    }
    for(i = 0; i < len-1; i++){
        t[patten[i]] = len-i-1;
    }

    //gen d2
    for(k = 0; k < len; k++){
        d = -1;
        for(i = 0; i <= len-2*k; i++){
            for(j = 0; j < k && patten[i+j] == patten[len-k+j]; j++);
            if(j-1 == k){
                d = i;
            }
        }

        if(d != -1){
            d2[k] = d;
        }else{
            for()
            if(d == -1){
                d2[k] = len;
            }else{
                d2[k] = d;
            }
        }
    }

    free(d2);
}

int main(){
    int x;
    char text[256] = "JIM_SAW_ME_IN_A_BARBERSHOP";
    char patten[256] = "BARBER";
    //scanf(" %s %s", text, patten);
    x = HorspoolMatching(text, patten);
    printf("%d\n",x);

}
