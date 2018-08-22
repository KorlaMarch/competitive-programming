#include "stdio.h"
#include "algorithm"
#include "vector"

typedef std::pair<int,int> pii;

typedef struct query{
    int ind, ktime, xnum;
    query(int _ind, int _ktime, int _xnum) : ind(_ind), ktime(_ktime), xnum(_xnum) {}
} query;

bool cmp(query a, query b){
    return a.xnum>b.xnum;
}

int n,q;
int A[100005];
int inA[100005];
int fen[100005];
int ans[100005];
int tActive[100005];
int activeTime[100005];
std::vector<query> qu;

void addFen(int i, int v){
    for(; i <= n; i += i&-i){
        fen[i] += v;
    }
}

int getFen(int i){
    int sum = 0;
    for(; i > 0; i -= i&-i){
        sum += fen[i];
    }
    return sum;
}

int fenSearch(int x){
    int i = 1, j = n;
    while(i<=j){
        const int mid = (i+j)/2;
        if(x<=getFen(mid)){
            j = mid-1;
        }else{
            i = mid+1;
        }
    }
    return j+1;
}

void printFen(){
    printf("Fen : ");
    for(int i = 1; i <= n; i++){
        printf("%d ", getFen(i));
    }
    printf("\n");
}

int main(){
    scanf("%d%d",&n,&q);
    for(int i = 1; i <= n; i++){
        scanf("%d", &A[i]);
        //calculate inverse of A
        inA[A[i]] = i;
    }

    for(int i = n; i > 0; i--){
        activeTime[i] = getFen(inA[i]);
        //printf("Add %d %d\n", i, inA[i]);
        addFen(inA[i],1);
    }

    int k,x;
    for(int i = 0; i < q; i++){
        scanf("%d%d", &k, &x);
        qu.push_back(query(i,k,x));
    }

    std::sort(qu.begin(), qu.end(), cmp);

    // clear fenwick
    for(int i = 0; i <= n; i++){
        fen[i] = 0;
    }

    // main loop
    int acCount = 0;
    for(int i = n, quI = 0; i > 0; i--){
        // check qu
        for(; quI < q && qu[quI].xnum == i; quI++){
            const query curq = qu[quI];
            if(curq.ktime<=activeTime[i]){
               // type one
               ans[curq.ind] = inA[curq.xnum]-curq.ktime;
            }else{
                const int timePass = curq.ktime-activeTime[i];
                const int jumpTo = getFen(inA[curq.xnum])+timePass;
                if(curq.ktime>n-curq.xnum||jumpTo>n-i){
                    // type three
                    ans[curq.ind] = curq.xnum;
                }else{
                    // type two
                    ans[curq.ind] = fenSearch(jumpTo)-curq.ktime;
                }
            }
        }

        // activate number
         addFen(inA[i],1);
    }

    // print ans
    for(int i = 0; i < q; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}
