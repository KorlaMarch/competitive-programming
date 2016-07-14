#include "stdio.h"
#include "vector"

int t,r,c,i,j,k,l;
bool isN;
std::vector<int> mp[100005];
std::vector<bool> cb[100005];
std::vector<bool> rb[100005];

void setF2(int id, int x, int y, int ox, int oy);

void setTF(int id, int x, int y, int ox, int oy, bool v){
    if(x<0||y<0||x>=r||y>=c) return;
    if(mp[x][y]==0){
        if(id==0) rb[x][y] = v;
        else cb[x][y] = v;
        setTF(id,x+ox,y+oy,ox,oy,v);
    }
}

void setF(int id, int x, int y, int ox, int oy){
    if(x<0||y<0||x>=r||y>=c) return;
    if(mp[x][y]==0){
        if(id==0){
            rb[x][y] = false;
            if(cb[x][y]){
                setF2(1,x-1,y,-1,0);
                setF2(1,x,y,1,0);
            }
        }else{
            cb[x][y] = false;
            if(rb[x][y]){
                setF2(0,x,y-1,0,-1);
                setF2(0,x,y,0,1);
            }
        }
        mp[x][y] = -1;
        setF(id,x+ox,y+oy,ox,oy);
    }
}

void setF2(int id, int x, int y, int ox, int oy){
    if(x<0||y<0||x>=r||y>=c) return;
    if(mp[x][y]==0){
        if(id==0){
            rb[x][y] = false;
            if(cb[x][y]){
                setF(1,x-1,y,-1,0);
                setF(1,x,y,1,0);
            }
        }else{
            cb[x][y] = false;
            if(rb[x][y]){
                setF(0,x,y-1,0,-1);
                setF(0,x,y,0,1);
            }
        }
        setF2(id,x+ox,y+oy,ox,oy);
    }
}

int main(){
    for(scanf("%d",&t); t > 0; t--){
        scanf("%d%d",&r,&c);
        isN = false;
        for(i = 0; i < r; i++){
            mp[i].clear();
            cb[i].clear();
            rb[i].clear();
            cb[i].resize(c,false);
            rb[i].resize(c,false);
            for(j = 0, l = -1; j < c; j++){
                scanf("%d",&k);
                mp[i].push_back(k);
                if(k){
                    if(l==k){
                        setTF(0,i,j-1,0,-1,true);
                    }
                    l = k;
                }
            }
        }
        for(j = 0; j < c; j++){
            for(i = 0, l = -1; i < r; i++){
                if(mp[i][j]){
                    if(l==mp[i][j]){
                        setTF(1,i-1,j,-1,0,true);
                    }
                    l = mp[i][j];
                }
            }
        }

        for(i = 0; i < r && !isN; i++){
            for(j = 0; j < c; j++){
                if(mp[i][j]==0){
                    if(!rb[i][j]&&!cb[i][j]){
                        isN = true;
                        break;
                    }else if(rb[i][j]&&!cb[i][j]){
                        setF(0,i,j-1,0,-1);
                        setF(0,i,j,0,1);
                    }else if(!rb[i][j]&&cb[i][j]){
                        setF(1,i-1,j,-1,0);
                        setF(1,i,j,1,0);
                    }
                }
            }
        }
        for(i = 0; i < r && !isN; i++){
            for(j = 0; j < c; j++){
                if(mp[i][j]==0&&!rb[i][j]&&!cb[i][j]){
                    isN = true;
                    break;
                }
            }
        }
        if(isN) printf("NO\n");
        else printf("YES\n");
    }
}
