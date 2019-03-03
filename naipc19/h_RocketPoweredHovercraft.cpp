#include "stdio.h"
#include "math.h"
#include "algorithm"

#define PI 3.14159265358979
int x, y;
double v, w;

double get_xt(double t){
    return v/w*sin(w*t);
}

double get_yt(double t){
    return v/w - v/w*cos(w*t);
}

double get_at(double t){
    return w*t;
}

double cal_dis(double xp, double yp) {
    return sqrt((x-xp)*(x-xp) + (y-yp)*(y-yp));
}

double get_tp() {
    double tl = 0.0, th = 2*PI/w;
    double t;
    for(int i = 0; i < 100; i++){
        double t = (tl+th)/2;
        double ra = atan2(y - get_yt(t), x - get_xt(t));
        printf("Diff %f %f : %f %f : %f\n", tl, th, w*t, ra, w*t - ra);
        if(w*t <= ra){
            tl = t;
        } else {
            th = t;
        }
    }
    return t;
}

int main() {
    scanf("%d%d", &x, &y);
    scanf("%lf%lf", &v, &w);
    if(y < 0) y *= -1;

    double t1;
    // calculate case 1
    if(sqrt(x*x + (y-v/w)*(y-v/w)) - v/w < 0.00001){
        double a = atan2(y-v/w, x) + PI/2;
        if(a < 0) a += 2*PI;
        t1 = a/w;
    } else if(sqrt(x*x + (y-v/w)*(y-v/w)) < v/w){
        t1 = 100000000.0;
    } else {
        double tp = get_tp();
        t1 = tp + cal_dis(get_xt(tp), get_yt(tp))/v;
    }
    // calculate case 2
    double t2;
    t2 = atan2(y, x)/w + sqrt(x*x + y*y)/v;
    printf("%f %f\n", t1, t2);
    printf("%.10f\n", std::min(t1, t2));
}
