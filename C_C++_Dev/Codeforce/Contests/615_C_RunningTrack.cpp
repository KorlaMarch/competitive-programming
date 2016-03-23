#include "stdio.h"
#include "string"

char s[2200],t[2200],rs[2200],str[2200];
char isH[300];
int ans[2200][2];
int i,j,n,p,len;
std::string st,rst;
int main(){
    scanf(" %s %s",s,t);
    for(i = 0; s[i]; i++){
        isH[s[i]] = 1;
    }
    len = i;
    for(j = 0,i--; i >= 0; i--,j++){
        rs[j] = s[i];
    }
    rs[j] = '\0';
    for(i = 0; t[i]; i++){
        if(!isH[t[i]]){
            printf("-1\n");
            return 0;
        }
    }
    st = std::string(s);
    rst = std::string(rs);
    for(i=j=0; t[i]; i++){
        str[j] = t[i];
        if(t[i+1]){
            str[j+1] = t[i+1];
            str[j+2] = '\0';
            if(st.find(std::string(str))!=-1||rst.find(std::string(str))!=-1){
                //printf("%d %d\n",str.find(std::string(str)),str.find(std::string(str)))
                j++;
                continue;
            }
        }
        str[j+1] = '\0';
        p = st.find(std::string(str));
        if(p!=-1){
            ans[n][0] = p;
            ans[n++][1] = p+j;
        }else{
            p = rst.find(std::string(str));
            ans[n][0] = len-p-1;
            ans[n++][1] = len-p-j-1;
        }
        j = 0;
    }
    printf("%d\n",n);
    for(i = 0; i < n; i++){
        printf("%d %d\n", ans[i][0]+1, ans[i][1]+1);
    }
}
