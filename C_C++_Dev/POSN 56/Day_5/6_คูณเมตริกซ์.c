#include <stdio.h>
#include <conio.h>

int main(){
    int A[3][3];
    int B[3][3];
    int c[3][3];
    int x,y,z, sum;
    //input A
    printf("Enter Matrix A : \n");
    printf("Column | 1  2  3\n");
    printf("-------|--------\n");
    for(x = 0; x < 3; x++){
        printf(" Row %d |", x+1);
        for(y = 0; y < 3; y++){
            scanf("%d", &A[x][y]);
        }
    }

    //input B
    printf("\nEnter Matrix B : \n");
    printf("Column | 1  2  3\n");
    printf("-------|--------\n");
    for(x = 0; x < 3; x++){
        printf(" Row %d |", x+1);
        for(y = 0; y < 3; y++){
            scanf("%d", &B[x][y]);
        }
    }
    //A[row][column]
    for(y = 0; y < 3; y++){
        for(x = 0; x < 3; x++){
            sum = 0;
            for(z = 0; z < 3; z++){
                sum += A[y][z]*B[z][x];
            }
            c[y][x] = sum;
        }
    }

    printf("\nOutput : \n");
    printf("Column |  1  2  3\n");
    printf("-------|---------\n");
    for(x = 0; x < 3; x++){
        printf(" Row %d |", x+1);
        for(y = 0; y < 3; y++){
            printf("%3d", c[x][y]);
        }
        printf("\n");
    }

    getch();
    return 0;
}
