#include <stdio.h>

int main(){
    int d, m, x;
    int total = 0;
    scanf("%d%d", &d, &m);
    for(x = 1; x < m; x++){
        if(x == 2){
            total += 28;
        }else if(x == 1 || x == 3 || x == 5 || x == 7
          || x == 8 || x == 10 || x == 12){
            total += 31;
        }else{
            total += 30;
        }
    }
    total += d;

    switch(total % 7){
        case 0:
            printf("Wednesday");
            break;
        case 1:
            printf("Thursday");
            break;
        case 2:
            printf("Friday");
            break;
        case 3:
            printf("Saturday");
            break;
        case 4:
            printf("Sunday");
            break;
        case 5:
            printf("Monday");
            break;
        case 6:
            printf("Tuesday");
            break;
    }
}
