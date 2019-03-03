#include "stdio.h"
#include "algorithm"
#include "vector"

using namespace std;

int count_sub(char s[], char target){
    int co = 0, prev = -1;
    for(int i = 0; s[i]; i++){
        if(s[i]==target){
            if(i-prev > 1){
                co++;
            }

            prev = i;
        }
    }
    return co;
}

int find_max() {

}

void solve_recur(char s[], int k) {
    if(k == 0 || !s[0]) {
        return;
    } else if(k == 1) {

    } else {
        vector<int> alpha[26];

        for(int i = 0; s[i]; i++){
            alpha[s[i]-'a'].push_back(i);
        }

        for(int i = 25; i >= 0; i++){
            if(alpha[i].size() != 0){
                int cs = count_sub(s, i + 'a');
                if(cs >= k){
                    // take all and do recursion
                    for(int j = 0; j < alpha[i].size(); j++{
                        putchar(i + 'a');
                    }

                    solve_recur(s + alpha[i].back() + 1, k - cs);

                    break;
                } else {
                    // not enough k, special case

                    int all = alpha[i].size();
                    char target = i + 'a';


                }
            }
        }
    }
}

void solve(){
    int k;
    char s[10005];

    scanf("%d %s", &k, s);

    solve_recur(s, k);
    putchar('\n');
}

int main(){
    int c;
    scanf("%d", &c);
    for(int t = 0; t < c; t++){
        solve();
    }
}
