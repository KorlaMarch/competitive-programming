#include "stdio.h"
#include "stack"
int t,a,b,mx,x;
bool isF[5000010];
std::stack<int> st,st2;
int main(){
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    scanf("%d%d%d",&t,&a,&b);
    st.push(0);
    while(!st.empty()){
        x = st.top();
        st.pop();
        if(x>t||isF[x]) continue;
        else if(x>mx) mx = x;
        isF[x] = true;
        st.push(x+a);
        st.push(x+b);
        st2.push(x/2);
    }
    while(!st2.empty()){
        x = st2.top();
        st2.pop();
        if(x>t||isF[x]) continue;
        else if(x>mx) mx = x;
        isF[x] = true;
        st2.push(x+a);
        st2.push(x+b);
    }
    printf("%d\n",mx);
}
