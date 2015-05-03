#include <stdio.h>

int main(){
    int start, next;
    printf("\n\tstart = "); scanf("%d", &start);
    printf("\tnext = "); scanf("%d", &next);
    printf("\n\tCharactor at %d form %c is %c\n", next, start%26 + 0x40, (start+next)%26 + 0x40);
    return 0;
}
