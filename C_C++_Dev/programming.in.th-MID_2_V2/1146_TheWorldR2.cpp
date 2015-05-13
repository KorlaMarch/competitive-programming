#include "stdio.h"
#include "map"
#include "string"
int n,q,p,i,x;
int town;
char s[6],t[60],isV[4];
std::map<std::string,int> ma[4];
std::string t2;
int main(){
    scanf("%d%d%d", &n,&p,&q);
    ma[0].insert(std::pair<std::string,int>("Eternal_City_Mac_Anu",1));
    ma[1].insert(std::pair<std::string,int>("Warring_City_Lumina_Cloth",1));
    ma[2].insert(std::pair<std::string,int>("Celestial_City_Dol_Dona",1));
    ma[3].insert(std::pair<std::string,int>("Dual_City_Breg_Epona",1));
    for(i = 0; i < n; i++){
        scanf(" %5s", s);
        switch(s[0]){
        case 'D':
            x = 0;
            break;
        case 'O':
            x = 1;
            break;
        case 'T':
            x = 2;
            break;
        case 'S':
            x = 3;
            break;
        }
        scanf(" %s", t);
        if(ma[x].count(t)==0){
            ma[x].insert(std::pair<std::string,int>(t,1));
            town++;
        }
        isV[x] = 1;
    }
    printf("%d\n", (isV[0]+isV[1]+isV[2]+isV[3]-1)*p+town*q*2);
}
