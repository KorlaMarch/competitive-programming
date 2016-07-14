#include <stdio.h>
#include <conio.h>

void RowOperation(double *a,int length, int from, int to, double mutiple){
    int x;
    printf("from = %d to = %d mutiple = %.2f\n", from + 1, to + 1, mutiple);
    for(x = 0; x < length; x++){
        *(a+length*to+x) -= *(a+length*from+x) * mutiple;

    }
}

int main(){
    int n = 3;
    double a[3][3] = {{2.0,3.0,1.0},{3.0,-5.0,2.0},{1.0,1.0,-1.0}};
    double b[3] = {8.0,4.0,2.0};
    double result[3];
    double temp;
    int x,y;
    int z1,z2;

    printf("==================\n");
    for(z1 = 0; z1 < n; z1++){
        for(z2 = 0; z2 < n; z2++){
            printf("%7.2f", a[z1][z2]);
        }
        printf(" |\t%.2f", b[z1]);
        printf("\n");
    }
    printf("\n\n");

    for(x = 0; x < n; x++){
        for(y = 0; y < n; y++){
            if(x > y){
                temp = a[x][y]/a[y][y];
                RowOperation(a, n, y, x, temp);
                RowOperation(b, 1, y, x, temp);
                printf("==================\n");
                for(z1 = 0; z1 < n; z1++){
                    for(z2 = 0; z2 < n; z2++){
                        printf("%7.2f", a[z1][z2]);
                    }
                    printf(" |\t%.2f", b[z1]);

                    printf("\n");
               }
               printf("\n\n");
            }
        }
    }

    for(x = n - 1; x >= 0; x--){
        for(y = n - 1; y >= 0; y--){
            if(x == y){
                result[x] = b[x] / a[x][y];
                printf("x%d = %.6f\n", x+ 1, result[x]);
            }else if(y > x){
                b[x] -= a[x][y] * result[y];
            }
        }
    }


}
