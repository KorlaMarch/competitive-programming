#include "stdio.h"
#include "algorithm"
#include "iostream"

/*typedef struct node{
    char isW;
    struct node* ptr[26];
}node;
node* getNode(char isW){
    node* tmp = (node*)malloc(sizeof(node));
    int i;
    tmp->isW = isW;
    for(i = 0; i < 26; i++){
        tmp->ptr[i] = NULL;
    }
    return tmp;
}
node* root;
char s[30];
int i,n;
void insertT(char s[], node* no){
    if(s[0]=='\0'){
        no->isW = 1;
    }else{
        if(no->ptr[s[0]-'a']==NULL) no->ptr[s[0]-'a'] = getNode(0);
        insertT(s+1,no->ptr[s[0]-'a']);
    }
}
void travers(node* no, int d){
    int i;
    if(no->isW){
        s[d] = '\0';
        printf("%s\n",s);
    }
    for(i = 0; i < 26; i++){
        if(no->ptr[i]!=NULL){
            s[d] = 'a'+i;
            travers(no->ptr[i],d+1);
        }
    }
}*/
std::string s[100005];
int n,i;
int main(){
    //root = getNode(0);
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        std::cin >> s[i];
        //insertT(s,root);
    }
    std::sort(s,s+n);
    for(i = 0; i < n; i++){
        std::cout << s[i];
        printf("\n");
    }
}
