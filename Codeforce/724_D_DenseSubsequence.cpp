#include "stdio.h"
#include "vector"
#include "string.h"
#include "set"

int m,n;
char s[100005];
std::vector<int> chpos[26];
std::vector<char> finalstr;
std::set<int> acp;
std::multiset<int> gap;

int main(){
	scanf("%d %s",&m,s);
	n = strlen(s);
	for(int i = 0; i < n; i++){
		chpos[s[i]-'a'].push_back(i);
	}

	acp.insert(-1);
	acp.insert(n);
	gap.insert(n+1);

	for(int i = 0; i < 26; i++){
		//insert
		std::set<int>::iterator it1, it2;
		for(int x : chpos[i]){
			it1 = it2 = acp.upper_bound(x);
			it1--;

			gap.erase(gap.lower_bound(*it2 - *it1));
			gap.insert(x - *it1);
			gap.insert(*it2 - x);

			acp.insert(x);
			finalstr.push_back(i+'a');
		}

		if(*gap.rbegin() <= m){
			//greedy remove
			for(int x : chpos[i]){
				it1 = acp.lower_bound(x);
				it2 = acp.upper_bound(x);
				it1--;

				if(*it2 - *it1 <= m){
					gap.erase(gap.lower_bound(*it1 - x));
					gap.erase(gap.lower_bound(*it2 - x));
					gap.insert(*it2 - *it1);

					acp.erase(x);
					finalstr.pop_back();
				}
			}
			break;
		}
	}
	for(char c : finalstr){
		putchar(c);
	}
	putchar('\n');
}