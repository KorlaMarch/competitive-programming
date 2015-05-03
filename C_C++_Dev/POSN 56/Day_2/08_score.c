#include <stdio.h>

int main(){
   int m,h,f;
    int score;
    int mini[4];

    printf("Enter Midterm : "); scanf("%d", &m);
    printf("Enter Homework : "); scanf("%d", &h);
    printf("Enter Final : "); scanf("%d", &f);

    score = (int)(m*0.4 + h*0.2 + f*0.4);

    printf("Enter Minimun score to get A : "); scanf("%d", &mini[0]);
    printf("Enter Minimun score to get B : "); scanf("%d", &mini[1]);
    printf("Enter Minimun score to get C : "); scanf("%d", &mini[2]);
    printf("Enter Minimun score to get D : "); scanf("%d", &mini[3]);

    printf("Your score is %d and you get ", score);

    if(score > 100){
        printf("Error!\n");
    }else if(score >= mini[0]){
        printf("A\n");
    }else if(score >= mini[1]){
        printf("B\n");
    }else if(score >= mini[2]){
        printf("C\n");
    }else if(score >= mini[3]){
        printf("D\n");
    }else if(score >= 0){
        printf("F\n");
    }else{
        printf("Error!\n");
    }
    return 0;
}
