#include <stdio.h>

int i = 0, v = 0, x = 0, l = 0, c = 0;

int main(){
    int d, n, y;
    scanf("%d", &d);
    for(y = 1; y <= d; y++){
        n = y;
        //��ѡ����
        if(n >= 100){
            while(n >= 100){
                n -= 100;
                c++;
            }
        }

        //�� 4 ���� 9
        if(n % 10 == 9){
            n -= 9;
            i++;
            x++;
        }
        if(n / 10 == 9){
            n -= 90;
            c++;
            x++;
        }
        if(n % 10 == 4){
            n -= 4;
            v++;
            i++;
        }
        if(n / 10 == 4){
            n -= 40;
            l++;
            x++;
        }

        //����Ѻ 50
        if(n >= 50){
            n -= 50;
            l++;
        }

        //����Ѻ 10
        if(n >= 10){
            while(n >= 10){
                n -= 10;
                x++;
            }
        }

        //����Ѻ 5
        if(n >= 5){
            n -= 5;
            v++;
        }

        //�������
        i += n;
    }

    printf("%d %d %d %d %d", i, v, x, l, c);
}
