#include <stdio.h>

int main(){
    int A, B, C;
    int a = 1, b = -100;
    int isHaveSolution = 0;
    scanf("%d%d%d", &A, &B, &C);
    while(a <= 100){
        //find a
        if(A % a == 0){
            b = -100;
            while(b <= 100){
                //find b
                if(b != 0 && C % b == 0){
                    //check if A, C can be B
                    if(a*(C/b) + b*(A/a) == B){
                        printf("%d %d %d %d", a, b, A/a, C/b);
                        isHaveSolution = 1;
                        break;
                    }
                }else if(C == 0){
                    printf("%d %d %d %d", a, 0, A/a, B/a);
                    isHaveSolution = 1;
                    break;
                }
                b++;
            }
        }
        if(isHaveSolution) break;
        a++;
    }
    printf("%s", isHaveSolution ? "" : "No Solution");

}
