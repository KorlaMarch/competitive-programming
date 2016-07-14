#include "stdio.h"
#include "set"

int n,m,k,i,j,p,mx;
std::multiset<int> st;
int cube[101][10005];
int maxCube[101][10005];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&cube[i][j]);
        }
    }
    for(j = 0; j < m; j++){
        maxCube[0][j] = cube[0][j];
    }
    for(i = 1; i < n; i++){
        st.clear();
        for(j=p=0; j < m; j++){
            for(; p<m&&p<=j+k; p++){
                st.insert(maxCube[i-1][p]);
            }
            if(j-k-1>=0) st.erase(st.lower_bound(maxCube[i-1][j-k-1]));
            maxCube[i][j] = *st.rbegin()+cube[i][j];
            if(maxCube[i][j]>mx) mx = maxCube[i][j];
        }
    }
    printf("%d\n",mx);
}
