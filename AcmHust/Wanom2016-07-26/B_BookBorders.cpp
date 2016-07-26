#include "stdio.h"
#include "vector"
#include "stack"

struct node{
	int v;
	struct node* next;
	struct node* prev;
	node(int _v = 0, struct node* _next = NULL, struct node* _prev = NULL) : v(_v), next(_next), prev(_prev) {}
};

struct list{
	node* front;
	node* back;
	int sumW;
	list(node* _front = NULL, node* _back = NULL, int _sumW = 0) : front(_front), back(_back), sumW(_sumW) {}
	~list(){
		for(node* tmp = front; tmp != NULL; tmp = tmp->next){
			if(tmp->prev) delete tmp->prev;
		}
	}
	int front(){
		return front->v;
	}

	int back(){
		return back->v;
	}

	bool empty(){
		return front==NULL;
	}

	void push_front(int v){
		front = new node(v,front);
		sumV += v;
	}

	void push_back(int v){
		back = new node(v,NULL,back);
		sumV += v;
	}

	void pop_back(){
		node* tmp = back;
		back = tmp->prev;
		delete tmp;
	}
};

char s[500005];
int a,b;
std::vector<int> wordl;
std::vector<std::deque<int> > qu;
std::vector<int> linel;
std::queue<int> wordQ;
std::stack<int> ans;

int main(){
	while(scanf(" %[^\n] %d %d",s,&a,&b)==3){
		int l = 0;
		a++,b++;
		wordl.clear();
		qu.clear();
		linel.clear();

		for(int i = 0; s[i]; i++){
			if(s[i]==' '){
				if(l){
					wordl.push_back(l+1);
					l = 0;
				}
			}else{
				l++;
			}
		}
		if(l) wordl.push_back(l+1);
		
		//make line == b
		qu.push_back(std::deque<int>());
		qu[0].push_back(wordl[0]);
		linel.push_back(wordl[0]);
		l = wordl[0];
		for(int i = 1, j = 0; i < wordl.size(); i++){
			if(linel[j]+wordl[i]<=b){
				qu[j].push_back(wordl[i]);
				linel[j] += wordl[i];
			}else{
				l += wordl[i];
				j++;
				qu.push_back(std::deque<int>());
				qu[j].push_back(wordl[i]);
				linel.push_back(wordl[i]);
			}
		}
		ans.push(l-1);
		for(int i = b-1; i >= a; i--){
			l = 0;
			for(int j = 0; j < qu.size(); j++){
				printf("line %d : ",j);
				while(!wordQ.empty()){
					printf("P%d ", wordQ.front());
					qu[j].push_front(wordQ.front());
					linel[j] += wordQ.front();
					wordQ.pop();
				}
				while(linel[j]>i){
					printf("D%d ",qu[j].back());
					wordQ.push(qu[j].back());
					linel[j] -= qu[j].back();
					qu[j].pop_back();
				}
				l += qu[j].front();
				printf("+%d\n",qu[j].front());
			}

			for(int j = qu.size()-1; !wordQ.empty(); wordQ.pop()){
				const int x = wordQ.front();
				if(linel[j]+x<=i){
					qu[j].push_back(x);
					linel[j] += x;
				}else{
					j++;
					qu.push_back(std::deque<int>());
					qu[j].push_back(x);
					linel.push_back(x);
					l += x;
				}
			}
			//ans.push(l-1);
			printf("%d\n",l-1);
		}
		while(!ans.empty()){
			printf("%d\n",ans.top());
			ans.pop();
		}
	}

}