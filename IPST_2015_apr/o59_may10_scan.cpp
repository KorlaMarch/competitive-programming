#include "scanlib.h"
#include "stdio.h"
#include "vector"
#include "algorithm"

int n,i,k,x,lx,a,b,c,l,r,m;
std::vector<int> begP[3],endP[3];
int items[50][4];
int main(){
    n = scan_init();
    k = detect(1,1,2,n);
    if(detect(2,1,2,n)==0){
        for(lx = 1, i = 0; i < k; i++){
            items[i][0] = items[i][2] = 1;
            for(l = lx, r = n; l<=r; ){
                m = (l+r)/2;
                x = detect(1,lx,1,m);
                if(x>=1){
                    r = m-1;
                }else{
                    l = m+1;
                }
            }
            items[i][1] = r+1;
            for(l = lx, r = n; l<=r; ){
                m = (l+r)/2;
                x = detect(1,lx,1,m);
                printf("BS %d %d\n",l,r);
                if(x>=2){
                    r = m-1;
                }else{
                    l = m+1;
                }
            }
            printf("RL %d %d\n",l,r);
            items[i][3] = r-1;
            lx = items[i][3]+1;
        }
    }else{
        for(i = 2, lx = k; i <= n+1; i++){
            if(i<=n) x = detect(1,i,2,n);
            else x = 0;
            if(x<lx){
                if(lx-x==2){
                    endP[0].push_back(i-1);
                    endP[1].push_back(i-1);
                }else{
                    if(i<=n){
                        a = detect(1,i-1,1,n)-detect(1,i,1,n);
                        b = detect(2,i-1,2,n)-detect(2,i,2,n);
                    }else{
                        a = detect(1,i-1,1,n);
                        b = detect(2,i-1,2,n);
                    }
                    if(a&&b){
                        endP[2].push_back(i-1);
                    }else if(a){
                        endP[0].push_back(i-1);
                    }else if(b){
                        endP[1].push_back(i-1);
                    }
                }
            }
            lx = x;
        }
        for(i = n-1, lx = k; i >= 0; i--){
            if(i) x = detect(1,1,2,i);
            else x = 0;
            if(x<lx){
                if(lx-x==2){
                    begP[0].push_back(i+1);
                    begP[1].push_back(i+1);
                }else{
                    if(i){
                        a = detect(1,1,1,i+1)-detect(1,1,1,i);
                        b = detect(2,1,2,i+1)-detect(2,1,2,i);
                    }else{
                        a = detect(1,1,1,i+1);
                        b = detect(2,1,2,i+1);
                    }
                    if(a&&b){
                        begP[2].push_back(i+1);
                    }else if(a){
                        begP[0].push_back(i+1);
                    }else if(b){
                        begP[1].push_back(i+1);
                    }
                }
            }
            lx = x;
        }
        //printf("Report %d %d %d %d : %d %d %d\n",k,begP[0].size(),begP[1].size(),begP[2].size(),endP[0].size(),endP[1].size(),endP[2].size());
        std::sort(begP[0].begin(),begP[0].end());
        std::sort(begP[1].begin(),begP[1].end());
        std::sort(begP[2].begin(),begP[2].end());
        std::sort(endP[0].begin(),endP[0].end());
        std::sort(endP[1].begin(),endP[1].end());
        std::sort(endP[2].begin(),endP[2].end());
        for(i = 0; i < begP[0].size(); i++,c++){
            items[c][0] = 1;
            items[c][1] = begP[0][i];
            items[c][2] = 1;
            items[c][3] = endP[0][i];
        }
        for(i = 0; i < begP[1].size(); i++,c++){
            items[c][0] = 2;
            items[c][1] = begP[1][i];
            items[c][2] = 2;
            items[c][3] = endP[1][i];
        }
        for(i = 0; i < begP[2].size(); i++,c++){
            items[c][0] = 1;
            items[c][1] = begP[2][i];
            items[c][2] = 2;
            items[c][3] = endP[2][i];
        }
        /*for(i = 0; i < c; i++){
            printf("%d %d %d %d\n",items[i][0],items[i][1],items[i][2],items[i][3]);
        }*/
    }
    scan_report(k,items);
}
