#include <stdio.h>
#include <stack>

using std::stack;

int main(){
    char infix[500];
    char postfix[500];
    int post_p = 0;
    int x;
    stack<char> oper;
    scanf("%s", &infix);
    
    for(x = 0; infix[x] != '\0'; x++){
          if(infix[x] >= 'A' && infix[x] <= 'Z'){
                postfix[post_p] = infix[x];
                post_p++;            
          }else if(infix[x] == '+'){
                if(!oper.empty() && oper.top() != '('){
                      postfix[post_p] = oper.top();
                      oper.pop();
                      post_p++;   
                }
                oper.push('+');     
          }else if(infix[x] == '-'){
                if(!oper.empty() && oper.top() != '('){
                      postfix[post_p] = oper.top();
                      oper.pop();
                      post_p++;   
                }
                oper.push('-');
          }else if(infix[x] == '*'){
                if(!oper.empty() && (oper.top() == '*' || oper.top() == '/')){  
                      postfix[post_p] = oper.top();
                      oper.pop();
                      post_p++;    
                }else{
                      oper.push('*');
                }   
          }else if(infix[x] == '/'){
                if(!oper.empty() && (oper.top() == '*' || oper.top() == '/')){  
                      postfix[post_p] = oper.top();
                      oper.pop();
                      post_p++;    
                }else{
                      oper.push('/');
                } 
          }else if(infix[x] == '('){
                oper.push('(');
          }else if(infix[x] == ')'){
                while(!oper.empty() && oper.top() != '('){
                      postfix[post_p] = oper.top();
                      oper.pop();
                      post_p++;
                      
                }
                oper.pop();
          }
    }
    
    while(!oper.empty()){
          postfix[post_p] = oper.top();
          oper.pop();
          post_p++;
    }
    postfix[post_p] = '\0';
    
    printf("%s\n", postfix);
    
}
