#include "stdio.h"
#include "vector"
#include "algorithm"

int t,k,i;
char s[2005];
std::vector<int> num;
int feq[257];
int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf(" %s",s);
        num.clear();
        for(i = 0; i <= 256; i++) feq[i] = 0;
        for(i = 0; s[i]; i++){
            feq[s[i]]++;
        }
        //ZERO
        while(feq['Z']){
            num.push_back(0);
            feq['Z']--; feq['E']--; feq['R']--; feq['O']--;
        }
        //SIX
        while(feq['X']){
            num.push_back(6);
            feq['S']--; feq['I']--; feq['X']--;
        }
        //TWO
        while(feq['W']){
            num.push_back(2);
            feq['T']--; feq['W']--; feq['O']--;
        }
        //SEVEN
        while(feq['S']){
            num.push_back(7);
            feq['S']--; feq['E']--; feq['V']--; feq['E']--; feq['N']--;
        }
        //FIVE
        while(feq['V']){
            num.push_back(5);
            feq['F']--; feq['I']--; feq['V']--; feq['E']--;
        }
        //FOUR
        while(feq['F']){
            num.push_back(4);
            feq['F']--; feq['O']--; feq['U']--; feq['R']--;
        }
        //EIGHT
        while(feq['G']){
            num.push_back(8);
            feq['E']--; feq['I']--; feq['G']--; feq['H']--; feq['T']--;
        }
        //THREE
        while(feq['R']){
            num.push_back(3);
            feq['T']--; feq['H']--; feq['R']--; feq['E']--; feq['E']--;
        }
        //ONE
        while(feq['O']){
            num.push_back(1);
            feq['O']--; feq['N']--; feq['E']--;
        }
        //NINE
        while(feq['N']){
            num.push_back(9);
            feq['N']--; feq['I']--; feq['N']--; feq['E']--;
        }
        std::sort(num.begin(),num.end());
        printf("Case #%d: ",k);
        for(int x : num){
            printf("%d",x);
        }
        printf("\n");
        /*for(i = 0; i <= 256; i++){
            if(feq[i]) printf("ERROR %d\n",k);
        }*/
    }
}
