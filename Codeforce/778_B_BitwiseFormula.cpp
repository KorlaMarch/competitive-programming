#include "stdio.h"
#include "string"
#include "string.h"
#include "map"
#include "algorithm"

// 0 = 0
// 1 = 1
// 2 = follow
// 3 = oppos

int n,m;
char var[20],tmp[20];
char fir[1005],sec[1005];
char oper[20];

std::string varName[5005];
int nf[5005],ns[5005];
std::map<std::string, int> mp;
char type[5005];
std::string rnum[5005];
char mn[1005],mx[1005];

int main(){
	scanf("%d%d",&n,&m);
	mn[m] = '\0';
	mx[m] = '\0';
	mp["?"] = 0;
	rnum[0].resize(m+5,2);
	for(int i = 1; i <= n; i++){
		scanf(" %s %s %s",var,tmp,fir);
		if(fir[0]!='0'&&fir[0]!='1'){
			scanf(" %s %s", oper, sec);
			if(strcmp(oper,"AND")==0) type[i] = 1;
			else if(strcmp(oper,"OR")==0) type[i] = 2;
			else type[i] = 3;

			nf[i] = mp[std::string(fir)];
			ns[i] = mp[std::string(sec)];
			rnum[i].resize(m+5);
		}else{
			type[i] = 0;
			rnum[i] = std::string(fir);
			for(int j = 0; j < m; j++){
				rnum[i][j] -= '0';
			}
		}

		varName[i] = std::string(var);
		mp[varName[i]] = i;
	}


	for(int i = 0; i < m; i++){
		for(int j = 1; j <= n; j++){
			if(type[j]!=0){
				const int R = rnum[nf[j]][i];
				const int L = rnum[ns[j]][i];
				if(type[j]==1){
					//type 1
					if(R==0||L==0){
						rnum[j][i] = 0;
					}else if(R==1&&L==1){
						rnum[j][i] = 1;
					}else if(R==1){
						rnum[j][i] = L;
					}else if(L==1){
						rnum[j][i] = R;
					}else if(R==L){
						rnum[j][i] = R;
					}else{
						rnum[j][i] = 0;
					}
				}else if(type[j]==2){
					//type 2
					if(R==1||L==1){
						rnum[j][i] = 1;
					}else if(R==0&&L==0){
						rnum[j][i] = 0;
					}else if(R==0){
						rnum[j][i] = L;
					}else if(L==0){
						rnum[j][i] = R;
					}else if(R==L){
						rnum[j][i] = R;
					}else{
						rnum[j][i] = 1;
					}
				}else{
					//type 3
					if(R!=2&&R!=3&&L!=2&&L!=3){
						rnum[j][i] = R^L;
					}else if((R==2||R==3)&&(L==2||L==3)){
						if(R==L) rnum[j][i] = 0;
						else rnum[j][i] = 1;
					}else if(R==1){
						rnum[j][i] = !(L-2)+2;
					}else if(L==1){
						rnum[j][i] = !(R-2)+2;
					}else if(R==0){
						rnum[j][i] = L;
					}else{
						rnum[j][i] = R;
					}
				}
			}
		}
		int c2 = 0,c3 = 0;
		for(int j = 1; j <= n; j++){
			//printf("%d %d : %d\n",j,i,rnum[j][i]);
			if(rnum[j][i]==2) c2++;
			else if(rnum[j][i]==3) c3++;
		}
		if(c2==c3){
			mn[i] = mx[i] = '0';
		}else if(c2>c3){
			mn[i] = '0';
			mx[i] = '1';
		}else{
			mn[i] = '1';
			mx[i] = '0';
		}
	}
	printf("%s\n%s\n",mn,mx);
}