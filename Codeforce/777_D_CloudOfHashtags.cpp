#include "stdio.h"
#include "iostream"
#include "string"
#include "algorithm"
#include "list"

int n,i;
std::string str[500005];
std::list sl;
bool isC[500005];

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		std::cin >> str[i];
		sl.push_back(n-i-1);
	}

	while(!sl.empty()){
		for(auto it = sl.begin(); it != sl.end(); it++){
			if(isC[])
		}
	}
}