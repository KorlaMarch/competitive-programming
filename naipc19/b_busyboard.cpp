#include "stdio.h"
#include "assert.h"

int r,c;
char ori[1005][1005];
char expect[1005][1005];
bool bl_row[1005];
bool bl_col[1005];

bool is_rest_the_same(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!bl_row[i] && !bl_col[j] && ori[i][j] != expect[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool solve(){
    scanf("%d%d", &r, &c);

    for(int i = 0; i < r; i++){
        scanf(" %s", ori[i]);
    }

    for(int i = 0; i < r; i++){
        scanf(" %s", expect[i]);
    }

    // scan each row for >= 2 blacks
    for(int i = 0; i < r; i++){
        int co = 0;
        for(int j = 0; j < c; j++){
            if(expect[i][j]=='X') co++;
        }

        if(co >= 2) {
            bl_row[i] = true;

            for(int j = 0; j < c; j++){
                if(expect[i][j] == 'X') {
                    bl_col[j] = true;
                }
            }
        }
    }

    // scan each col for >= 2 blacks
    for(int j = 0; j < c; j++){
        int co = 0;
        for(int i = 0; i < r; i++){
            if(expect[i][j]=='X') co++;
        }

        if(co >= 2) {
            bl_col[j] = true;

            for(int i = 0; i < r; i++){
                if(expect[i][j] == 'X') {
                    bl_row[i] = true;
                }
            }
        }
    }

    // check the blacklisted row/col
    bool needChange = false;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(bl_row[i] && bl_col[j]){
                if(expect[i][j] != ori[i][j]){
                    return false;
                }
            } else if((bl_row[i] || bl_col[j]) && ori[i][j] == 'X'){
                assert(expect[i][j] == 'O');
                needChange = true;
            }
        }
    }


    // count x, o on the rest
    int xc = 0;
    int oc = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!bl_row[i] && !bl_col[j]){
                if(expect[i][j]=='X') xc++;
                if(ori[i][j]=='O') oc++;
            }
        }
    }

    return (xc>=1 && oc>=1) || (is_rest_the_same() && !needChange);
}

int main(){
    if(solve()) printf("1\n");
    else printf("0\n");
}
