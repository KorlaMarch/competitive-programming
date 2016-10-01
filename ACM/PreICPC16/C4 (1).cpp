#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int x[100002];
int y[100002];

bool compare(int a, int b)
{
    return a < b;
}

int c;

int main()
{
    int nx, ny;
    int t;
    int i,j;

    nx = ny = 0;
    scanf("%d", &t);
    while (t != 0) {
        if (t > 0)
            x[nx++] = t;
        else
            y[ny++] = abs(t);
        scanf("%d", &t);
    }

    sort(x,x+nx,compare);
    sort(y,y+ny,compare);
    i = j = 0;
    c = 0;
    while (i < nx && j < ny) {
        if(i < nx && j < ny && x[i] <= y[j]){
            while(i < nx && x[i] <= y[j])
                i++;
            j++;
            c++;
        }
        else if(j < ny && i < nx && y[j] <= x[i]){
            while(j < ny && y[j] <= x[i])
                j++;
            i++;
            c++;
        }
    }
    if(c==0)
        c = 1;
    printf("%d", c);
    return 0;
}
