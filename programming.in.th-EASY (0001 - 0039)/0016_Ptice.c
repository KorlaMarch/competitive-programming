#include <stdio.h>

int main(){
    int n, x;
    int Adrian = 0, Bruno = 0, Goran = 0;
    char s[101];
    char temp;
    int max;

    scanf("%d", &n);
    scanf("%s", &s);
    for(x = 0; x < n; x++){
        //Adrian
        if(x % 3 == 0){
            temp = 'A';
        }else if(x % 3 == 1){
            temp = 'B';
        }else if(x % 3 == 2){
            temp = 'C';
        }
        if(s[x]  == temp){
            Adrian++;
        }

        //Bruno
        if(x % 4 == 0){
            temp = 'B';
        }else if(x % 4 == 1){
            temp = 'A';
        }else if(x % 4 == 2){
            temp = 'B';
        }else if(x % 4 == 3){
            temp = 'C';
        }
        if(s[x]  == temp){
            Bruno++;
        }

        //Goran
        if(x % 6 == 0){
            temp = 'C';
        }else if(x % 6 == 1){
            temp = 'C';
        }else if(x % 6 == 2){
            temp = 'A';
        }else if(x % 6 == 3){
            temp = 'A';
        }else if(x % 6 == 4){
            temp = 'B';
        }else if(x % 6 == 5){
            temp = 'B';
        }
        if(s[x]  == temp){
            Goran++;
        }
    }
    //find max
    max = Adrian;
    if(Bruno > max) max = Bruno;
    if(Goran > max) max = Goran;

    //out
    printf("%d\n", max);
    if(max == Adrian) printf("Adrian\n");
    if(max == Bruno) printf("Bruno\n");
    if(max == Goran) printf("Goran\n");

    return 0;


}
