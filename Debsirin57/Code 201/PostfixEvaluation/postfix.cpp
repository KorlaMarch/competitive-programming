#include <stack>
#include <stdio.h>
#include <math.h>

using std::stack;
using std::string;



int main(){
    stack<double> num;
    double symbot[256];
    int n,x;
    char c;
    char postfix[1000];
    double first, last, y;
    scanf("%d", &n);
    for(x = 0; x < n; x++){
          scanf(" %c %lf",&c,&y);
          symbot[c] = y;
    }

    scanf("%s", postfix);
    
    for(x = 0; postfix[x] != '\0'; x++){
          if(postfix[x] < 'A' || postfix[x] > 'Z'){
                if(num.size() < 2){
                       printf("Error!");
                       return -1;             
                }
                
                last = num.top();
                num.pop();
                first = num.top();
                num.pop();
                if(postfix[x] == '+'){
                      num.push(first + last);
                }else if(postfix[x] == '-'){
                      num.push(first - last);
                }else if(postfix[x] == '*'){
                      num.push(first * last);
                }else if(postfix[x] == '/'){
                      num.push(first / last);
                }else if(postfix[x] == '^'){
                      num.push(pow(first, last));
                }
          }else{
                num.push(symbot[postfix[x]]);
          }
    }
    
    printf("%.4f", num.top());
    scanf("%d", &n);
}
