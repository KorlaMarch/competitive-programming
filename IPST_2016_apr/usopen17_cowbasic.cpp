#include "iostream"
#include "string"
#include "map"
#include "algorithm"
#include "stdlib.h"
#include "stdio.h"

#define MOD 1000000007

int countID = 1;
std::map<std::string,int> varid;
std::map<int, std::map<int, long long>> expr[105];

bool isNum(std::string& s){
	for(int i = 0; i < s.size(); i++){
		if(s[i]<'0'||s[i]>'9') return false;
	}
	return true;
}

void plusTo(std::map<int, long long>& source, std::map<int, long long>& dis, long long mul = 1){
	for(auto pi : source){
		dis[pi.first] = (dis[pi.first]+mul*pi.second)%MOD;
		//printf("dis[%d] += %lld*%lld == %lld\n",pi.first,mul,pi.second, dis[pi.first]);
	}
}

void repEx(int x, int ind, int oind){
	if(x==1){
		expr[ind] = expr[oind];
		return;
	}
	repEx(x/2,ind+1,oind);
	//combine x/2,x/2
	expr[ind].clear();
	for(auto& mp : expr[ind+1]){
		for(auto& pi : mp.second){
			if(expr[ind+1].count(pi.first)){
				plusTo(expr[ind+1][pi.first],expr[ind][mp.first],pi.second);
			}else{
				expr[ind][mp.first][pi.first] = (expr[ind][mp.first][pi.first]+pi.second)%MOD;
			}
		}
	}

	if(x%2==1){
		expr[ind+1] = expr[ind];
		expr[ind].clear();
		for(auto& mp : expr[oind]){
			for(auto& pi : mp.second){
				if(expr[ind+1].count(pi.first)){
					plusTo(expr[ind+1][pi.first],expr[ind][mp.first],pi.second);
				}else{
					expr[ind][mp.first][pi.first] = (expr[ind][mp.first][pi.first]+pi.second)%MOD;
				}
			}
		}
	}
}

void emu(int x, int ind, bool isM = false){
	//printf("CALLED %d %d %d\n",x,ind,isM);
	std::string str;
	
	if(!isM){
		std::cin >> str; //MOO
		std::cin >> str; //{
	}

	//clear data
	expr[ind].clear();

	while(1){
		std::cin >> str;
		//printf("GET %s\n",str.c_str());
		if(str=="RETURN"){
			std::cin >> str;
			std::cout << expr[ind][varid[str]][0];
			return;
		}else if(str=="}"){
			//end of loop
			break;
		}else if(isNum(str)){
			//another loop
			emu(atoi(str.c_str()),ind+1);
			
			std::map<int, std::map<int, long long>> newExs;
			for(auto& mp : expr[ind+1]){
				for(auto& pi : mp.second){
					if(expr[ind].count(pi.first)){
						plusTo(expr[ind][pi.first],newExs[mp.first],pi.second);
					}else{
						newExs[mp.first][pi.first] = (newExs[mp.first][pi.first]+pi.second)%MOD;
					}
				}
			}
			//merge newExs back
			for(auto& mp : newExs){
				expr[ind][mp.first] = mp.second;
			}
		}else{
			//normal expression
			int disID = varid[str];
			std::map<int, long long> newEx;

			if(disID==0){
				disID = countID++;
				varid[str] = disID;
			}
			std::cin >> str; // =
			for(int i = 0, dep = 0; i==0||dep!=0; i++){
				std::cin >> str;
				if(str=="("){
					dep += 2;
				}else if(str==")"){
					dep--;
				}else if(str=="+"){
					//skip next parent
					std::cin >> str;
				}else if(isNum(str)){
					newEx[0] = ( newEx[0]+atoi(str.c_str()) )%MOD;
				}else{
					int souID = varid[str];
					if(expr[ind].count(souID)){
						plusTo(expr[ind][souID],newEx);
					}else{
						newEx[souID] = (newEx[souID]+1)%MOD;
					}
				}
			}

			expr[ind][disID] = newEx;
		}
	}

	//rep x times
	// int a,b;
	// expr[ind+1] = expr[ind];
	// expr[ind+2].clear();
	// for(int i = 1; i < x; i++){
	// 	a = ind+i%2+1; //target
	// 	b = ind+!(i%2)+1; //origin
	// 	//printf("L %d\n",i);
	// 	expr[a].clear();
	// 	for(auto& mp : expr[ind]){
	// 		for(auto& pi : mp.second){
	// 			if(expr[b].count(pi.first)){
	// 				plusTo(expr[b][pi.first],expr[a][mp.first],pi.second);
	// 			}else{
	// 				expr[a][mp.first][pi.first] = (expr[a][mp.first][pi.first]+pi.second)%MOD;
	// 			}
	// 		}
	// 	}
	// }
	repEx(x,ind+1,ind);
	expr[ind] = expr[ind+1];
}

int main(){
	emu(1,0,true);
}