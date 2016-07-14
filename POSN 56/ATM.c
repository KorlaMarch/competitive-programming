#include <stdio.h>
#include <conio.h>

int bank1000 = 20;
int bank500 = 40;
int bank100 = 100;

int main(){
    int money = 0;
    int give1000 = 0, give500 = 0, give100 = 0;
    int before1000, before500, before100;
    while(money != -1){
        before1000 = bank1000;
        before500 = bank500;
        before100 = bank100;
        give1000 = 0;
        give500 = 0;
        give100 = 0;

        printf("Enter Money : ");
        scanf("%d", &money);

        while(bank1000 > 0 && money >= 1000){
            give1000++;
            money -= 1000;
            bank1000--;
        }

        while(bank500 > 0 && money >= 500){
            give500++;
            money -= 500;
            bank500--;
        }

        while(bank100 > 0 && money >= 100){
            give100++;
            money -= 100;
            bank100--;
        }

        if(money > 0){
            bank1000 = before1000;
            bank500 = before500;
            bank100 = before100;
            printf("Not enough banks to pay.\n");
        }else{
            printf("\n\n\n\n\n\n");
            printf("\t\tYou get :\n");
            printf("\t\t\t%-3d of 1000 banks.\n", give1000);
            printf("\t\t\t%-3d of 500 banks.\n", give500);
            printf("\t\t\t%-3d of 100 banks.\n", give100);
        }
        getch();
        system("cls");
    }
}
