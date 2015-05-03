#include "stdio.h"
#include "math.h"
double abs(double d){
    return d<0.0?d*-1:d;
}
int pow(int base, int r){
    if(r == 0) return 1;
    return base*pow(r-1);
}
int binary_pow(int y, int k){

}
int main(){
    int n,i,y,m,k;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d", &y);
        for(m = 1; m<y; m *= 2);
        for(k=m;k>1;k++){
            if(binary_pow(y,k))
        }
    }
}
