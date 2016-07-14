#include <stdio.h>
#include <math.h>

void plusTime(){

}

int main(){
    float time;
    int n, x;
    float price = 0;
    printf("start time = "); scanf("%f", &time);
    printf("used time (minute) = "); scanf("%d", &n);

    for(x = 1; x <= n; x++){
        time += 0.01;
        if(time - floor(time) >= 0.6){
            time += 0.4;
        }

        if(time >= 24.0){
            time = 0.0;
        }

        if(time >= 20.0 && time <= 228.59){
            //20% off
            printf("Add 20%% time = %.2f\n", time);
            price += 14.4;
        }else if((time >= 23.00 && time <= 23.59) || (time >= 0.0 && time <= 5.59)){
            //30% off
            printf("Add 30%% time = %.2f\n", time);
            price += 12.6;
        }else{
            printf("Add Full time = %.2f\n", time);
            price += 18.0;
        }
    }
    printf("Price = %.2f\n", price);

}
