#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"

char s[5001];
bool isP[5001][5001];
int k,i,j,len;
std::vector<std::pair<int,int>> vec;

bool cmp(std::pair<int,int> a, std::pair<int,int> b){
    int i,j;
    for(i = a.first,j = b.first; ; i++,j++){
        if(i>a.second){
            return true;
        }else if(j>b.second){
            return false;
        }else if(s[i]<s[j]){
            return true;
        }else if(s[i]>s[j]){
            return false;
        }
    }
}

int main(){
    scanf(" %s %d",s,&k);
    len = strlen(s);
    for(i = len-1; i >= 0; i--){
        isP[i][i] = true;
        vec.push_back({i,i});
        for(j = i+1; s[j]; j++){
            if(i+2<=j-2) isP[i][j] = s[i]==s[j]&&isP[i+2][j-2];
            else isP[i][j] = s[i]==s[j];
            if(isP[i][j]) vec.push_back({i,j});
        }
    }
    std::sort(vec.begin(),vec.end(),cmp);
    for(i = vec[k-1].first; i <= vec[k-1].second; i++){
        printf("%c",s[i]);
    }
}
