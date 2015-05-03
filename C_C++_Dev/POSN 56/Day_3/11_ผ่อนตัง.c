#include <stdio.h>

int main(){
    int A;
    float i, P;
    int n = 1;

    printf("Enter P : "); scanf("%f", &P);
    printf("Enter A : "); scanf("%d", &A);
    printf("Enter I (in %%): "); scanf("%f", &i);
    i = i / 100.0;

    while(P > 0){
        printf("%d month ,Interest = %.2f bath\n", n, P*(i/12.0));
        if(P - (A - P*(i/12.0)) < 0){
            P += P*(i/12.0);
            printf("\tpay %6.2f, have %5.2f left\n", P, 0.0);
            break;
        }else{
            P -= A - P*(i/12.0);
            printf("\tpay %6.2f, have %5.2f left\n", A - P*(i/12.0), P);
        }

        n++;
    }

    return 0;
}
