#include <stdio.h>
main(){
int a=1 , b=2 , c=3 , d=4;
float i=0.1 , j=2.5 , k=10;
char x=65 , y=90 , z=97;
int t=0;
for(a=x;a<y;a++)
t++;
d++;
FILE *h;
h = fopen("input.txt","w");
char ch[100][100]={"teerawat","computer","posn"};

printf("Output1 : a = %d , b = %d , d = %d , t= %d\n",a*d,b+t,d++,++t);
fprintf(h,"Output2 : 1 = %f , 2 = %f , 3 = %f\n",i*a+j*b,k*d*--c,x+y+z/j);
printf("Output3 : string1 = %s , char1 = %c , char2 = %d\n",ch[0],ch[0][0]++,ch[2][1]);

char *m,*n;
m = &ch[0][1];
n = &ch[2][3];
printf("Output4 : %c %c %c %c\n",*++m,--*m,++*n,*n--);

fclose(h);
scanf(" ");
}
