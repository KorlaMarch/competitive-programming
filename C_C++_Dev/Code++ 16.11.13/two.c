#include <stdio.h>
#include <stdlib.h>

int a[1000];
int ap = 0;
int b[1000];
int bp = 0;

int find(int n[], int size, int key){
    int hi = size, low = 0;
    int mid;

    while(low < hi){
        mid = (hi + low) / 2;
        if(n[mid] == key){
            return 1;
        }else if(n[mid] < key){
            low = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return 0;
}

int isEqual(){
    int x;
    if(ap == bp){
        for(x = 0; x < ap; x++){
            if(a[x] != b[x]){
                return 0;
            }
        }
    }else{
        return 0;
    }
    return 1;
}

int isSub(int mother[], int m_size, int sub[], int s_size){
    int x, y;
    char isFind;
    for(x = 0; x < s_size; x++){
        if(find(mother, m_size, sub[x]) == 0){
            return 0;
        }
    }
    return 1;
}

int isDisjoin(){
    int x, y;
    for(x = 0; x < ap; x++){
        //printf("Find : a[%d]\n", x);
        if(find(b, bp, a[x])) return 0;

    }
    return 1;
}

void sort(int *n, int size){
    int x,y;
    for(x = 1; x <= size; x++){
        for(y = 0; y < size - x; y++){
            if(*(n+y) > *(n+y+1)){
                *(n+y) = *(n+y) ^ *(n+y+1);
                *(n+y+1) = *(n+y) ^ *(n+y+1);
                *(n+y) = *(n+y) ^ *(n+y+1);
            }
        }

    }
}

int main(){
    int x,y,z;
    char c;
    char isDupe;
    char buff[6] = {'\0'};
    char buff_p = 0;
    do{
        c = getchar();
        if(c != '\n'){
            if(c != ' '){
                buff[buff_p] = c;
                buff_p++;
            }else if(buff_p != 0){
                buff[buff_p] = '\0';
                y = atoi(buff);
                if(!find(a, ap, y)){
                    a[ap] = y;
                    ap++;
                }
                buff_p = 0;
            }
        }else if(buff_p != 0){
                buff[buff_p] = '\0';
                y = atoi(buff);

                if(!find(a, ap, y)){
                    a[ap] = y;
                    ap++;
                }
                buff_p = 0;
        }
    }while(c != '\n');

    do{
        c = getchar();
        if(c != '\n'){
            if(c != ' '){
                buff[buff_p] = c;
                buff_p++;
            }else if(buff_p != 0){
                buff[buff_p] = '\0';
                y = atoi(buff);
                if(!find(b, bp, y)){
                    b[bp] = y;
                    bp++;
                }
                buff_p = 0;
            }
        }else if(buff_p != 0){
                buff[buff_p] = '\0';
                y = atoi(buff);
                if(!find(b, bp, y)){
                    b[bp] = y;
                    bp++;
                }
                buff_p = 0;
        }
    }while(c != '\n');

    printf("\n");
    sort(a, ap);
    sort(b, bp);
    if(isEqual()){
        printf("First and Second are equal\n");
    }else if(isSub(b, bp, a, ap)){
        printf("First is a proper subset of Second\n");
    }else if(isSub(a, ap, b, bp)){
        printf("Second is a proper subset of First\n");
    }else if(isDisjoin()){
        printf("First and Second are disjoint\n");
    }else{
        printf("First and Second have some elements in common\n");
    }
    return 0;
}
