#include "stdio.h"
#include "iostream"
#include "fstream"

int n;
int A[100005];
std::ofstream test, ans;

int main(){
    test.open("testcase.txt");
    ans.open("sol.txt");

    scanf("%d",&n);
    test << n << " " << (n-1)*(n-1) << "\n";
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        test << A[i] << " ";
    }
    test << "\n";

    int cot = 0;
    for(int t = 1; t < n; t++){
        printf("T%d ", t);
        for(int j = 0; j+1 < n; j++){
            if(A[j]>A[j+1]){
                int t = A[j];
                A[j] = A[j+1];
                A[j+1] = t;
            }
            printf("%d ", A[j]);
            test << t << " " << A[j] << "\n";
            ans << j+1 << "\n";
            cot++;
        }
        printf("%d\n", A[n-1]);
    }
    printf("C:%d\n",cot);

    test.close();
    ans.close();
}
