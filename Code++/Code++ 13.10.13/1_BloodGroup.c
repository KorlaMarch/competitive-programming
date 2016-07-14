#include <stdio.h>

int main(){
    char d[4];
    char r[4];
    scanf("%s%s", d, r);

    if(d[0] == 'O'){
        if(d[1] == '-'){
            printf("Compatible\n");
        }else{
            if(r[1] == '+' || r[2] == '+'){
                printf("Compatible\n");
            }else{
                printf("Incompatible\n");
            }
        }
    }else if(d[0] == 'A' && d[2] != 'B'){
        if(r[0] == 'A'){
            if(d[1] == '-'){
                printf("Compatible\n");
            }else{
                if(r[1] == '+' || r[2] == '+'){
                    printf("Compatible\n");
                }else{
                    printf("Incompatible\n");
                }

            }
        }
    }else if(d[0] == 'B'){
        if(r[0] == 'B' || r[1] == 'B'){
            if(d[1] == '-'){
                printf("Compatible\n");
            }else{
                if(r[1] == '+' || r[2] == '+'){
                    printf("Compatible\n");
                }else{
                    printf("Incompatible\n");
                }
            }
        }
    }else if(d[0] == 'A' && d[1] == 'B'){
        if(r[0] == 'A' && r[1] == 'B'){
            if(d[2] == '-'){
                printf("Compatible\n");
            }else{
                if(r[2] == '+'){
                    printf("Compatible\n");
                }else{
                    printf("Incompatible\n");
                }
            }
        }else{
            printf("Incompatible\n");
        }
    }
    return 0;
}
