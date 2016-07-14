#include "stdio.h"
#include "algorithm"
#include "vector"
#include "queue"

int n,m,i,j,le,no;
int va[1000020],sol[1000020];
int inD[1000020],p[1000020];
bool isV[1000020];
std::pair<int,int> ord[1000020];
std::vector<int> edge[1000020];
std::vector<int> alli[1000020];
std::queue<int> zdq;

int unionF(int x){
    return x==p[x]?x:(p[x]=unionF(p[x]));
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&va[i*m+j]);
        }
    }
    ///////////// UNIQUE /////////////
    for(i = 0; i < n*m; i++) p[i] = i;
    for(i = 0; i < n; i++){
        //column
        for(j = 0; j < m; j++){
            ord[j].first = va[i*m+j];
            ord[j].second = j;
        }
        std::sort(ord,ord+m);
        for(j = 1; j < m; j++){
            if(ord[j-1].first==ord[j].first){
                p[unionF(i*m+ord[j].second)] = p[unionF(i*m+ord[j-1].second)];
            }
        }
    }
    for(i = 0; i < m; i++){
        //row
        for(j = 0; j < n; j++){
            ord[j].first = va[j*m+i];
            ord[j].second = j;
        }
        std::sort(ord,ord+n);
        for(j = 1; j < n; j++){
            if(ord[j-1].first==ord[j].first){
                 p[unionF(ord[j].second*m+i)] = p[unionF(ord[j-1].second*m+i)];
            }
        }
    }
    ////////////////////////////////////////////////
    for(i = 0; i < n; i++){
        //crate edge in column
        for(j = 0; j < m; j++){
            ord[j].first = va[i*m+j];
            ord[j].second = j;
        }
        std::sort(ord,ord+m);
        le = 0;
        for(j = 1; j < m; j++){
            if(ord[j-1].first==ord[j].first){
                alli[unionF(i*m+ord[le].second)].push_back(i*m+ord[j].second);
            }else{
                edge[unionF(i*m+ord[le].second)].push_back(unionF(i*m+ord[j].second));
                inD[unionF(i*m+ord[j].second)]++;
                le = j;
            }
        }
    }
    for(i = 0; i < m; i++){
        //crate edge in row
        for(j = 0; j < n; j++){
            ord[j].first = va[j*m+i];
            ord[j].second = j;
        }
        std::sort(ord,ord+n);
        le = 0;
        for(j = 1; j < n; j++){
            if(ord[j-1].first==ord[j].first){
                alli[unionF(ord[le].second*m+i)].push_back(ord[j].second*m+i);
            }else{
                edge[unionF(ord[le].second*m+i)].push_back(unionF(ord[j].second*m+i));
                inD[unionF(ord[j].second*m+i)]++;
                le = j;
            }
        }
    }

    for(i = 0; i < n*m; i++){
        if(inD[unionF(i)]==0&&!isV[unionF(i)]){
            isV[unionF(i)] = true;
            zdq.push(unionF(i));
        }
        /*printf("%d %d %d: ",unionF(i),i,inD[i]);
        for(j = 0; j < edge[i].size(); j++){
            printf("%d ",edge[i][j]);
        }
        printf("\n");*/
    }
    //printf("\n");
    while(!zdq.empty()){
        no = zdq.front();
        zdq.pop();
        no = unionF(no);
        //printf("RUN : %d\n",no);
        for(i = 0; i < alli[no].size(); i++){
            sol[alli[no][i]] = sol[no];
        }
        for(i = 0; i < edge[no].size(); i++){
            if(sol[no]+1>sol[edge[no][i]]){
                sol[edge[no][i]] = sol[no]+1;
            }
            inD[edge[no][i]]--;
            if(inD[edge[no][i]]==0){
                //printf("PUSH : %d\n",edge[no][i]);
                zdq.push(edge[no][i]);
            }
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d ",sol[i*m+j]+1);
        }
        printf("\n");
    }
}
