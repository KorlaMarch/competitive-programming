#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ex1();
void ex2();
void ex3();
void ex4();
void ex45();
void ex5();
void ex6();
void ex7();
void ex8();
void ex9();

void printMiddel(char s[]){
    char buffer[10];
    sprintf(buffer ,"%%%ds", strlen(s)/2 + 40);
    printf(buffer, s);
}

int main(){
    int num;
    printf("\n\n\n\n");
    printMiddel("=============================\n");
    printMiddel("|   POSN Day_2 ex. 1 - 9   |\n");
    printMiddel("=============================\n");
    printMiddel("| Enter the number :        |");
    printf("\b\b\b\b\b\b\b\b");

    scanf("%d", &num);

    system("cls");
    switch(num){
        case 1:
            ex1();
            break;
        case 2:
            ex2();
            break;
        case 3:
            ex3();
            break;
        case 4:
            ex4();
            break;
        case 5:
            ex5();
            break;
        case 6:
            ex6();
            break;
        case 7:
            ex7();
            break;
        case 8:
            ex8();
            break;
        case 9:
            ex9();
            break;
        case 45:
            ex45();
            break;
        default:
            system("color FC");
            printf("\n\n");
            printMiddel("|=========|\n");
            printMiddel("|  Error  |\n");
            printMiddel("|=========|\n");
    }

}
/////////////////////////////////////////////////////////////////////////
void ex1(){
    int x;
    printf("\n\tx = "); scanf("%d", &x);
    printf("\n\tCharactor at %d is %c\n", x, x%26 + 0x40);
}
/////////////////////////////////////////////////////////////////////////

void ex2(){
    int start, next;
    printf("\n\tstart = "); scanf("%d", &start);
    printf("\tnext = "); scanf("%d", &next);
    printf("\n\tCharactor at %d form %c is %c\n", next, start%26 + 0x40, (start+next)%26 + 0x40);
}

/////////////////////////////////////////////////////////////////////////
void ex3(){
    int money;
    printf("Enter Money :"); scanf("%d", &money);

    printf("B 1000 = %d\n", money / 1000);
    printf("B 500  = %d\n", (money%1000)/500);
    printf("B 100  = %d\n", (money%500)/100);
}

////////////////////////////////////////////////////////////////////////

typedef struct{
    int x;
    int y;
}cood;

void ex4(){
    cood pos[2];
    printf("X1 = "); scanf("%d", &pos[0].x);
    printf("Y1 = "); scanf("%d", &pos[0].y);
    printf("X2 = "); scanf("%d", &pos[1].x);
    printf("Y2 = "); scanf("%d", &pos[1].y);

    printf("Distance = %.2f\n", sqrt((pos[0].x - pos[1].x)*(pos[0].x - pos[1].x) +
           (pos[0].y - pos[1].y)*(pos[0].y - pos[1].y)));
}

////////////////////////////////////////////////////////////////////////

void ex45(){
    char c;
    printf("Enter Charactor :"); scanf("%c", &c);
    switch(c){
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        printf("%c is vowel\n", c);
        break;
    default:
        printf("%c is alphabet\n", c);
        break;
    }
}

////////////////////////////////////////////////////////////////////////

void ex5(){
    int h, w, bmi;
    printf("Enter hight : "); scanf("%d", &h);
    printf("Enter wight : "); scanf("%d", &w);
    bmi = (float)w/(h*h);

    if(bmi >= 40){
        printf("Too Fat 3");
    }else if(bmi >= 35){
        printf("Fat 2");
    }else if(bmi >= 28.5){
        printf("Fat 1");
    }else if(bmi >= 23.5){
        printf("Overwight");
    }else if(bmi >= 18.5){
        printf("Nomal");
    }else{
        printf("Thin");
    }
}

////////////////////////////////////////////////////////////////////////

void ex6(){
    int x,y;
    int cirx, ciry;
    int r;
    printf("Enter X"); scanf("%d", &x);
    printf("Enter Y"); scanf("%d", &y);
    printf("Enter Circle's X"); scanf("%d", &cirx);
    printf("Enter Circle's Y"); scanf("%d", &ciry);
    printf("Enter Radius"); scanf("%d", &r);

    if(sqrt((x-cirx)*(x-cirx) + (y-ciry)*(y-ciry)) > r){
        printf("This coodinate is out of circle");
    }else{
        printf("This coodinate is in circle");
    }
}

////////////////////////////////////////////////////////////////////////

void ex7(){
    int A,B,C;
    printf("A = "); scanf("%d", &A);
    printf("B = "); scanf("%d", &B);
    printf("C = "); scanf("%d", &C);
    if(A <= 0){
        printf("x = %f", (float)C/B);
    }else{
        if(B*B - 4*A*C < 0){
            printf("x = %.3fi and %.3fi", ((float)-1*B + sqrt((B*B - 4*A*C)*-1))/ (float)(2*A),
                    ((float)-1*B - sqrt((B*B - 4*A*C)*-1))/ (float)(2*A));
        }else{
            printf("x = %.3f and %.3f", ((float)-1*B + sqrt(B*B - 4*A*C))/ (float)(2*A),
                   ((float)-1*B - sqrt(B*B - 4*A*C))/ (float)(2*A));
        }
    }
}

////////////////////////////////////////////////////////////////////////

void ex8(){
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

}

////////////////////////////////////////////////////////////////////////

void ex9(){
    int price;
    float weight, total;
    printf("Enter Price : "); scanf("%d", &price);
    printf("Enter Weight : "); scanf("%f", &weight);
    total = price * weight;

    if(total > 300){
        total = total*0.85;
    }else if(total > 200){
        total = total*0.9;
    }else if(total > 100){
        total = total*0.95;
    }

    printf("Total price is : %.2f", total*1.07);
}
