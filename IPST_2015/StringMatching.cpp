#include "stdio.h"
#include "string.h"
#include "vector"
#include "ctime"
#include "algorithm"

#define INPUT_T "big_com.txt"
#define INPUT_P "patterns.txt"
/*#define INPUT_T "test.txt"
#define INPUT_P "test2.txt"*/
#define MOD 4432676798593
char t[10000000];
char p[10000000];
std::vector<int> test[25];
std::vector<int> result[25];
std::vector<int> plength;
int timeU[6][25];
FILE *textFile,*patternFile;
std::clock_t start;
int nextPatt(){
    if(patternFile==NULL){
        patternFile = fopen(INPUT_P,"r");
        if(patternFile==NULL){
            printf("OPEN PATTERN FILE ERROR\n");
            return -1;
        }
    }else if(feof(patternFile)){
        fclose(patternFile);
        patternFile = NULL;
        return 0;
    }
    fscanf(patternFile," %[^\n] ",p);
    return 1;
}

void startTimer(){
    start = std::clock();
}
double getMS(){
    double d = std::clock()-start;
    return d*1000/CLOCKS_PER_SEC;
}

void brute_force(char t[], char p[], std::vector<int>& res){
    int i,j,len;
    len = strlen(p);
    for(i = 0; t[i+len-1]; i++){
        for(j = 0; p[j]; j++){
            if(t[i+j]!=p[j]) break;
        }
        if(j==len){
            res.push_back(i);
        }
    }
}

void rabin_kerp(char t[], char p[], std::vector<int>& res){
    long long h,ph,mul;
    int i,j,len;
    len = strlen(p);
    for(i=mul=1,ph=0; i<=len; i++,mul = (mul*10)%MOD){
        ph = (ph+mul*p[len-i])%MOD;
    }
    for(i=h=0; i < len-1; i++){
        h = (10*h+t[i])%MOD;
    }
    for(i = 0; t[i+len-1]; i++){
        h = (10*h+t[i+len-1])%MOD;
        if(i>0){
            h = (h-mul*t[i-1]+300*MOD)%MOD;
        }
        if(h==ph){
            for(j = 0; j < len; j++){
                if(t[i+j]!=p[j]) break;
            }
            if(j==len){
                res.push_back(i);
            }
        }
    }
}

void finiteAutomata(char t[], char p[], std::vector<int>& res){
    int tran[1030][256];
    int kmp[1030];
    int i,j,x,k,len;
    len = strlen(p);
    //make finite automata
    for(j = 0; j < 256; j++){
        tran[0][j] = 0;
    }
    kmp[0] = 0;
    tran[0][p[0]] = 1;
    for(i=1,k=0; p[i]; i++){
        for(j = 0; j < 256; j++){
            if(p[i]==j){
                tran[i][j] = i+1;
            }else{
                x = k;
                while(x>0&&j!=p[x]){
                    x = kmp[x-1];
                }
                if(j==p[x]) x++;
                tran[i][j] = x;
            }
        }
        while(k>0&&p[i]!=p[k]){
            k = kmp[k-1];
        }
        if(p[i]==p[k]) k++;
        kmp[i] = k;
    }
    for(j = 0; j < 256; j++){
        x = k;
        while(x>0&&j!=p[x]){
            x = kmp[x-1];
        }
        if(j==p[x]) x++;
        tran[i][j] = x;
    }
    for(i=j=0; t[i]; i++){
        j = tran[j][t[i]];
        if(j == len){
            res.push_back(i-len+1);
        }
    }
}

void kmp(char t[], char p[], std::vector<int>& res){
    int i,j,k,len = strlen(p),len2 = strlen(t);
    std::vector<int> prefix;
    for(i=1,prefix.push_back(0),k=0; i < len; i++){
        while(k>0&&p[i]!=p[k]){
            k = prefix[k-1];
        }
        if(p[i]==p[k]) k++;
        prefix.push_back(k);
    }
    for(i=j=0; i<len2;){
        if(j==len){
            //printf("%d\n",i-j);
            res.push_back(i-j);
            j = prefix[j-1];
        }else if(t[i]==p[j]){
            i++,j++;
        }else{
            if(j){
                j = prefix[j-1];
                if(j==1) i++;
            }else i++;
        }
    }
}

void boyermoore(char t[], char p[], std::vector<int>& res){
    int bc[256],len = strlen(p),len2 = strlen(t);
    std::vector<int> gs(len+1);
    std::vector<int> f(len+1);
    int i,j;
    for(i = 0; i < 256; i++) bc[i] = -1;
    for(i = 0; p[i]; i++){
        bc[p[i]] = i;
    }
    //GS
    for(i = len, j = len+1; i>0; i--,j--){
        f[i]=j;
        while(j<=len&&p[i-1]!=p[j-1]){
            if(gs[j]==0) gs[j]=j-i;
            j = f[j];
        }
    }
    f[i]=j;
    for(i=0,j=f[0]; i<=len; i++){
        if(gs[i]==0) gs[i] = j;
        if(i == j) j=f[j];
    }

    for(i = 0; i+len < len2;){
        j = len-1;
        while(j>=0&& p[j]==t[i+j]) j--;
        if(j < 0){
            //printf("%d\n",i);
            res.push_back(i);
            i += gs[0];
        }else{
            i += std::max(gs[j+1],j-bc[t[i+j]]);
        }
    }
}

void horspool(char t[], char p[], std::vector<int>& res){
    int bc[256],i,j,len=strlen(p),len2=strlen(t);
    for(i = 0; i < 256; i++) bc[i] = 0;
    for(i = 0; p[i+1]; i++){
        bc[p[i]] = i+1;
    }
    for(i = 0; i+len-1<len2;){
        for(j = len-1; j >= 0; j--){
            if(t[i+j]!=p[j]) break;
        }
        if(j<0){
            //printf("%d\n",i);
            res.push_back(i);
        }
        i += len-bc[t[i+len-1]];
    }
}

bool checkResult(int n){
    int i,j;
    for(i = 0; i < n; i++){
        if(test[i].size()!=result[i].size()) return false;
        for(j = 0; j < test[i].size(); j++){
            if(test[i][j]!=result[i][j]) return false;
        }
    }
    return true;
}
void runStringTest(){
    int i,j,k,x;
    printf("==== START of String Testing ====\n");
    printf("GENERTE Testcase Answer (BruteForce)...\n");
    for(i = 0; nextPatt(); i++){
        //printf("P:%s\n",p);
        plength.push_back(strlen(p));
        startTimer();
        brute_force(t,p,test[i]);
        timeU[0][i] = getMS();
        /*for(j = 0; j < test[i].size(); j++){
            printf("%d ",test[i][j]);
        }
        printf("\n");*/
    }
    k = i;
    printf("ENDING of BruteForce\n");
    printf("Start string matching algorithm...\n");
    for(x = 1; x < 6; x++){
        switch(x){
            case 1 : printf("Rabin kerp...\n"); break;
            case 2 : printf("FiniteAutomata...\n"); break;
            case 3 : printf("KMP...\n"); break;
            case 4 : printf("Boyermoore...\n"); break;
            case 5 : printf("Horspool...\n"); break;
        }
        for(i = 0; nextPatt(); i++){
            if(x==2&&strlen(p)>1024){ i--; continue; }
            result[i].clear();
            startTimer();
            switch(x){
                case 1 : rabin_kerp(t,p,result[i]); break;
                case 2 : finiteAutomata(t,p,result[i]); break;
                case 3 : kmp(t,p,result[i]); break;
                case 4 : boyermoore(t,p,result[i]); break;
                case 5 : horspool(t,p,result[i]); break;
            }
            timeU[x][i] = getMS();
        }
        if(!checkResult(i)) printf("ERROR : Result not correct. (%d)\n",x);
    }
    printf("TIME :\n");
    printf(" |P|\t BF\t RK\t FA\t KMP\t BM\t HS\n");
    for(i = 0; i < k; i++){
        printf("%7d\t",plength[i]);
        for(j = 0; j < 6; j++){
            printf("%3d ms\t",timeU[j][i]);
        }
        printf("\n");
    }
    printf("NOTE:\n\tBF = Brute Force\n\tRK = Rabin-Karp\n\tFA = Finite Automata\n\tKMP = Knuth-Morris-Pratt\n\tBM = Boyer-Moore\n\tHS = Horspool\n");
}

int main(){
    int i,j;
    patternFile = NULL;
    textFile = fopen(INPUT_T,"r");
    if(textFile!=NULL){
        fscanf(textFile,"%[^\0]",t);
    }else{
        printf("OPEN TEXT FILE ERROR\n");
        return 0;
    }
    runStringTest();
}
