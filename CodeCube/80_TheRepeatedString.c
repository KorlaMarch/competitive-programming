#include "stdio.h"
#include "string.h"
char s[100005];
int i,j,st,size,c,rep,t;
int main(){
    for(t = 0; t < 5; t++){
        scanf(" %s",&s);
        /*for(i = 0; s[i]; i++) printf("%d",i%10);
        printf("\n");*/
        size = 0,c=0,rep=0;
        for(i=1,j=0,st=i; s[i]; i++){
            //printf("i=%d j = %d st = %d C1 = %c C2 = %c\n",i,j,st,s[i],s[j]);
            if(j==st||(size&&j==size)){
                size = j;
                j = 0;
                st = i;
            }
            if(s[i]==s[j]){
                j++;
            }else{
                size = 0;
                if(s[0]==s[i]){
                    st = i;
                    j = 1;
                }else{
                    st = i+1;
                    j = 0;
                }
            }
        }
        //printf("size = %d\n",size);
        if(j==st||(size&&j==size)){
            rep = i/j;
            for(i = 1; i <= rep; i++) if(rep%i==0) c++;
            printf("%d\n",c);
        }else printf("1\n");
    }
}
