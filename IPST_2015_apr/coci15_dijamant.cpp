#include "stdio.h"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "vector"
#include "algorithm"

int n,i,j,c;
char s[15];
bool isc;
std::unordered_map<std::string,int> id;
std::unordered_map<int,int> clist,plist;
std::vector<int> p[1005];
std::vector<int> child[1005];
std::string str,str2;

void addChild(int no, int c){
    for(int x : child[no]){
        if(!clist.count(x)){
            clist[x] = c;
            //printf("ADD C %d\n",x);
            addChild(x,c);
        }
    }
}

bool addP(int no, int c){
    for(int x : p[no]){
        if(!plist.count(x)){
            plist[x] = c;
            //printf("ADD P %d\n",x);
            if(addP(x,c)) return true;
        }else if(plist[x]!=c||plist[x]==chl){
            return true;
        }
    }
    return false;
}

void checkDiamond(int c){
    int i;
    for(int x : p[c]){
        //printf("RUN %d\n",x);
        if(addP(x,x)){
            isc = false;
            return;
        }
        addChild(x);
    }
}

int main(){
    scanf("%d",&n);
    c = 1;
    for(i = 0; i < n; i++){
        isc = true;
        scanf(" %s : ",s);
        str.assign(s);
        if(id.count(str)) isc = false;
        else{
            id[str] = c;
        }
        while(1){
            scanf(" %s",s);
            if(s[0]==';') break;
            if(isc){
                str2.assign(s);
                if(id.count(str2)){
                    p[c].push_back(id[str2]);
                }else{
                    //printf("NS");
                    isc = false;
                    id.erase(str);
                    p[c].clear();
                }
            }
        }
        //check diamond
        if(isc){
            std::sort(p[c].begin(),p[c].end());
            plist.clear();
            clist.clear();
            for(int x : p[c]){
                child[x].push_back(c);
            }
            checkDiamond(c);
            if(!isc){
                for(int x : p[c]){
                    child[x].pop_back();
                }
                id.erase(str);
                p[c].clear();
            }
        }
        if(isc){
            c++;
            printf("ok\n");
        }else{
            printf("greska\n");
        }
    }
}
