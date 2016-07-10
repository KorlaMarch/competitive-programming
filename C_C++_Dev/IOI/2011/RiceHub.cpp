#include "stdio.h"
#include "math.h"
#include "algorithm"

int r,l;
long long b;
int x[100005];
int mx;

int abs(int n){
    return n<0?-n:n;
}
long long getB(int n, int m){
    long long sum = 0;
    long long avg = x[(n+m)/2];
    for(int i = n; i <= m; i++){
        sum += abs(avg-x[i]);
    }
    return sum;
}

void changeAvg(int& avg, int& oavg, int& k, long long& cb, int i, int j){
    while(k<r&&x[k+1]<avg){
        cb += (x[k+1]-oavg)*((k-i+1)-(j-k));
        oavg = x[k+1];
        k++;
    }
    cb += (avg-oavg)*(k-i+1-(j-k));
    oavg = avg;
}

int main(){
    int i,j,m;
    scanf("%d%d %lld",&r,&l,&b);
    for(i = 0; i < r; i++){
        scanf("%d",&x[i]);
    }
    //binary search
    i = 0, j = r-1;
    while(i<=j){
        m = (i+j)/2;
        if(getB(0,m)<=b){
            i = m+1;
        }else{
            j = m-1;
        }
    }
    //printf("BS %d%d %lld\n",i,j,getB(j));
    j++;
    mx = j;
    //sliding windows
    int k = 0;
    long long cb = 0;
    int avg, oavg = x[j/2];
    for(i = 0; i < r && i <= j; i++){
        if(x[i]<=oavg){
            k = i;
            cb += oavg-x[i];
        }else{
            cb += x[i]-oavg;
        }
    }
    //printf("%d %d %lld %lld %lld\n",j,0,cb,getB(0,j),b);
    for(i = 1; i < r && j < r; i++){
        avg = x[(i+j)/2];
        cb -= oavg-x[i-1];
        //printf("BF %d %lld %lld : %lld\n",k,avg,oavg,cb);
        changeAvg(avg,oavg,k,cb,i,j);
        //printf("AF %d %lld %lld : %lld %lld\n",k,avg,oavg,cb,getB(i,j));
        while(j<r&&cb<=b){
            j++;
            if(j<r){
                avg = x[(i+j)/2];
                cb += x[j]-oavg;
                changeAvg(avg,oavg,k,cb,i,j);
                //printf(":ERROR %d %d : %lld %lld\n",i,j,cb,getB(i,j));
            }
        }
        if(cb<0) while(1);
        mx = std::max(mx,j-i);
    }
    printf("%d\n",mx);
    return 0;
}
