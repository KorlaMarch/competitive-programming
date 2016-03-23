#include "stdio.h"
#include "stdlib.h"
#include "vector"
#include "algorithm"

struct node{
    int v,mx;
    node* next;
    node(int _v = 0, int _mx = 0, node* _ptr = NULL){
        v = _v, next = _ptr,mx = _mx;
    }
};

struct linklist{
    std::vector<node*> ver;
    linklist(){
        ver.push_back(NULL);
    }
    void addhead(int v, int x){
        ver.push_back(new node(x,ver[v]!=NULL?std::max(x,ver[v]->mx):x,ver[v]));
    }
    void changehead(int v, int x){
        if(ver[v]==NULL) ver.push_back(new node(x,x,NULL));
        else ver.push_back(new node(x,ver[v]->next!=NULL?std::max(x,ver[v]->next->mx):x,ver[v]->next));
    }
    void delhead(int v){
        ver.push_back(ver[v]==NULL?NULL:ver[v]->next);
    }
    int findmax(int v){
        return ver[v]==NULL?-1:ver[v]->mx;
    }
};

int n,i,v,x;
char c;
linklist li;
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf(" %c %d", &c,&v);
        switch(c){
            case 'A':
                scanf("%d",&x);
                li.addhead(v,x);
                break;
            case 'C':
                scanf("%d",&x);
                li.changehead(v,x);
                break;
            case 'D':
                li.delhead(v);
                break;
            case 'M':
                printf("%d\n",li.findmax(v));
                break;
        }
    }
}
