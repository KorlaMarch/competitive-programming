#include "stdio.h"
#include "math.h"
#include "algorithm"

#define M_PI 3.1415926535897932

int n,x,y,i,j,mnp;
int po[51][4];
double po2[4];
double dis[51];
bool isP[51];
double mn;

double sq(double n){
    return n*n;
}

double caldis(double a, double b){
    return sqrt(sq(x-a)+sq(y-b));
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d%d%d",&po[i][0],&po[i][1],&po[i][2],&po[i][3]);
        if(po[i][0]>po[i][2]){
            std::swap(po[i][0],po[i][2]);
            std::swap(po[i][1],po[i][3]);
        }
    }
    scanf("%d%d",&x,&y);
    for(i = 0; i < n; i++){
        //find other two points
        double l = sqrt(sq(po[i][0]-po[i][2])+sq(po[i][1]+po[i][3]))/sqrt(2);
        double m = tan(arctan((po[i][1]+po[i][3])/(double)(po[i][0]-po[i][2]))+M_PI/4.0);
        po2[0] = po[i][0]+sqrt((l*l)/(1+m*m));
        po2[1] = po[i][1]+m*sqrt((l*l)/(1+m*m));
        m = -1.0/m;
        po2[2] = po[i][0]+sqrt((l*l)/(1+m*m));
        po2[3] = po[i][1]+m*sqrt((l*l)/(1+m*m));

        dis[i] = std::min(std::min(caldis(po2[0],po2[1]),caldis(po2[2],po2[3])),std::min(caldis(po[i][0],po[i][1]),caldis(po[i][2],po[i][3]));


    }

}
