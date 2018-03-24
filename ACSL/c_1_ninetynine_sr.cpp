#include "stdio.h"
#include "algorithm"

char ori[2][5];
char pc[2][5];
int total;
char nextCard[10];

int getValue(char c){
    switch(c){
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 14;
        default:
            return c-'0';
    }
}

int play(char c, int turn){
    //printf(":%c %d (%d)\n",c,turn,total);
    int opoint = total;
    switch(c){
        case '9':
            // do nothing
            break;
        case 'T':
            total -= 10;
            break;
        case '7':
            if(total+7<100){
                total += 7;
            }else{
                total += 1;
            }
            break;
        default:
            total += getValue(c);
            break;
    }

    //check for crossing
    if((opoint<=33&&total>=34)||(opoint<=55&&total>=56)||(opoint<=77&&total>=78)
       ||(total<=33&&opoint>=34)||(total<=55&&opoint>=56)||(total<=77&&opoint>=78))
    {
        //printf("Cross %d %d\n",opoint,total);
        total += 5;
    }

    if(total>=100){
        printf("%d, Player #%d\n",total,turn);
    }
}

bool cmp(char a, char b){
    return getValue(a)<getValue(b);
}

int main(){
    scanf(" %c, %c, %c, %c, %c, ",&ori[0][0],&ori[0][1],&ori[0][2],&ori[0][3],&ori[0][4]);
    scanf(" %c, %c, %c, %c, %c",&ori[1][0],&ori[1][1],&ori[1][2],&ori[1][3],&ori[1][4]);

    for(int i = 0; i < 5; i++){
        //copy the pc
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 5; k++){
                pc[j][k] = ori[j][k];
            }
        }

        //get input
        scanf(" %d, ",&total);
        for(int j = 0; j < 10; j++){
            scanf(" %c,", &nextCard[j]);
        }

        for(int j = 0; total < 100; j++){
            if(j%2==0){
                std::sort(pc[0],pc[0]+5,cmp);
                play(pc[0][2],2);
                pc[0][2] = nextCard[j];
            }else{
                std::sort(pc[1],pc[1]+5,cmp);
                play(pc[1][2],1);
                pc[1][2] = nextCard[j];
            }
        }
    }
}
