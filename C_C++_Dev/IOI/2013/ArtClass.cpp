#include "stdio.h"
#include "math.h"

int getR(int RGB) { return (RGB >> 16) & 0xFF; }
int getG(int RGB) { return (RGB >> 8) & 0xFF; }
int getB(int RGB) { return RGB & 0xFF; }

int abs(int n){
    return n<0?-n:n;
}

double absF(double n){
    return n<0?-n:n;
}

int getDiff(int a, int b){
    return abs(getR(a)-getR(b))+abs(getG(a)-getG(b))+abs(getB(a)-getB(b));
}

int min(int a, int b){
    return a<b?a:b;
}

int t,k,i,j,w,h;
int color[1000][1000];
int gc,con,sr,sg,sb,wc,rcon,ccon;
double pix,avgDiff;

int main(){
    //scanf("%d",&t);
    //for(k = 1; k <= t; k++){
        scanf("%d%d",&h,&w);
        gc = wc = 0;
        con = sr = sg = sb = 0;
        pix = h*w;
        avgDiff = 0;
        for(i = 0; i < h; i++){
            for(j = 0; j < w; j++){
                scanf("%d",&color[i][j]);
                if(getG(color[i][j])/(double)(getG(color[i][j])+getR(color[i][j])+getB(color[i][j]))>0.4) gc++;
                if(min(getG(color[i][j]),min(getR(color[i][j]),getB(color[i][j])))>180) wc++;
                if(i){
                    con += getDiff(color[i][j],color[i-1][j]);
                    ccon += getDiff(color[i][j],color[i-1][j]);
                }
                if(j){
                    con += getDiff(color[i][j],color[i][j-1]);
                    rcon += getDiff(color[i][j],color[i][j-1]);
                }
                sg += getG(color[i][j]);
                sr += getR(color[i][j]);
                sb += getB(color[i][j]);
            }
        }
        for(i = 0; i < h; i++){
            for(j = 0; j < w; j++){
                avgDiff += absF(sr/pix-getR(color[i][j]))+absF(sg/pix-getG(color[i][j]))+absF(sb/pix-getB(color[i][j]));
            }
        }
        printf("%.4f %.4f %.4f (%.4f %.4f) %.4f : %.4f %.4f %.4f\n",gc/pix,wc/pix,con/pix,rcon/pix,ccon/pix,avgDiff/pix,sr/pix,sg/pix,sb/pix);
        if(con/pix>140) printf("3\n");
        else if(con/pix>41&&avgDiff/pix<200) printf("2\n");
        else if(con/pix>20) printf("1\n");
        else printf("4\n");
    //}
}
