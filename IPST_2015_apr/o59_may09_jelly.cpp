#include "stdio.h"

#define MOD 1000000007

int sx,sy,sz,t;
long long x1,x2,y1,y2,z1,z2,v1,v2;
int c,d,l,h;
int k,i,j;

//0 = x 1 = y 2 = z
long long seg[3][4000005];
long long lazy[3][4000005];
bool isIntersert(int i, int j, int x, int y){
    return (x<=i&&i<=y)||(x<=j&&j<=y)||(i<=x&&x<=j)||(i<=y&&y<=j);
}

void addSeg(int ind, int no, int i, int j, int x, int y, long long v){
    if(x<=i&&j<=y){
        lazy[ind][no] = (lazy[ind][no]+v)%MOD;
        seg[ind][no] = (seg[ind][no]+v*(j-i+1))%MOD;
    }else if(isIntersert(i,j,x,y)){
        addSeg(ind, no*2+1,i,(i+j)/2,x,y,v);
        addSeg(ind, no*2+2,(i+j)/2+1,j,x,y,v);
        seg[ind][no] = (seg[ind][no*2+1]+seg[ind][no*2+2]+lazy[ind][no]*(j-i+1))%MOD;
    }
    //if(ind==1) printf("CALL %d %d : %d %d : %d %d %lld %lld %lld\n",ind,no,i,j,x,y,v,seg[ind][no],lazy[ind][no]);
}

long long getSeg(int ind, int no, int i, int j, int x, int y){
    long long sum = 0;
    //printf("GET %d %d : %d %d : %d %d\n",ind,no,i,j,x,y);
    if(x<=i&&j<=y){
        sum = seg[ind][no];
    }else if(isIntersert(i,j,x,y)){
        if(lazy[ind][no]){
            lazy[ind][no*2+1] = (lazy[ind][no]+lazy[ind][no*2+1])%MOD;
            lazy[ind][no*2+2] = (lazy[ind][no]+lazy[ind][no*2+2])%MOD;
            seg[ind][no*2+1] = (seg[ind][no*2+1]+((i+j)/2-i+1)%MOD*lazy[ind][no])%MOD;
            seg[ind][no*2+2] = (seg[ind][no*2+2]+(j-(i+j)/2)%MOD*lazy[ind][no])%MOD;
            lazy[ind][no] = 0;
        }
        sum += getSeg(ind, no*2+1,i,(i+j)/2,x,y);
        sum += getSeg(ind, no*2+2,(i+j)/2+1,j,x,y);
    }
    return sum%MOD;
}

int main(){
    scanf("%d%d%d%d",&sx,&sy,&sz,&t);
    for(k = 0; k < t; k++){
        scanf("%d",&c);
        if(c==0){
            scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&x1,&x2,&y1,&y2,&z1,&z2,&v1,&v2);
            //printf("OS : %d %d %d\n",v2*(sy-(y2-y1+1))*(sz-(z2-z1+1)),v2*(sx-(x2-x1+1))*(sz-(z2-z1+1)),v2*(sy-(y2-y1+1))*(sx-(x2-x1+1)));
            addSeg(0,0,1,sx,x1,x2,v1*(y2-y1+1)%MOD*(z2-z1+1)%MOD);
            if(x1>1) addSeg(0,0,1,sx,1,x1-1,v2*(sy-(y2-y1+1))%MOD*(sz-(z2-z1+1))%MOD);
            if(x2+1<=sx) addSeg(0,0,1,sx,x2+1,sx,v2*(sy-(y2-y1+1))%MOD*(sz-(z2-z1+1))%MOD);

            addSeg(1,0,1,sy,y1,y2,v1*(x2-x1+1)%MOD*(z2-z1+1)%MOD);
            if(y1>1) addSeg(1,0,1,sy,1,y1-1,v2*(sx-(x2-x1+1))%MOD*(sz-(z2-z1+1))%MOD);
            if(y2+1<=sy) addSeg(1,0,1,sy,y2+1,sy,v2*(sx-(x2-x1+1))%MOD*(sz-(z2-z1+1))%MOD);

            addSeg(2,0,1,sz,z1,z2,v1*(y2-y1+1)%MOD*(x2-x1+1)%MOD);
            if(z1>1) addSeg(2,0,1,sz,1,z1-1,v2*(sy-(y2-y1+1))%MOD*(sx-(x2-x1+1))%MOD);
            if(z2+1<=sz) addSeg(2,0,1,sz,z2+1,sz,v2*(sy-(y2-y1+1))%MOD*(sx-(x2-x1+1))%MOD);

        }else{
            scanf("%d%d%d",&d,&l,&h);
            switch(d){
                case 1: printf("%lld\n",getSeg(0,0,1,sx,l,h)%MOD); break;
                case 2: printf("%lld\n",getSeg(1,0,1,sy,l,h)%MOD); break;
                case 3: printf("%lld\n",getSeg(2,0,1,sz,l,h)%MOD); break;
            }
        }
    }
}
