#include "stdio.h"
#include "algorithm"

int n;
char s[100005];
int maxC[2][4][4][4][4];

void setInf(int ind){
	for(int f1 = 0; f1 < 4; f1++){
		for(int s1 = 0; s1 < 4; s1++){

			for(int f2 = 0; f2 < 4; f2++){
				for(int s2 = 0; s2 < 4; s2++){

					maxC[ind][f1][s1][f2][s2] = -1;

				}
			}
		}
	}
}

int checkDiff(int a, int b, int c){
	int v = 0;

	if(a==1||b==1||c==1) v++;
	if(a==2||b==2||c==2) v++;
	if(a==3||b==3||c==3) v++;

	return v;
}

int main(){
	scanf("%d %s",&n,s);

	//initialize
	setInf(0);
	maxC[0][0][0][0][0] = 0;

	for(int i = 0; i < n; i++){

		int ty;
		switch(s[i]){
			case 'M': ty = 1; break;
			case 'F': ty = 2; break;
			case 'B': ty = 3; break;
		}
		setInf((i+1)%2);

		for(int f1 = 0; f1 < 4; f1++){
			for(int s1 = 0; s1 < 4; s1++){

				for(int f2 = 0; f2 < 4; f2++){
					for(int s2 = 0; s2 < 4; s2++){

						const int cv = maxC[i%2][f1][s1][f2][s2];
						if(cv != -1){
							//sent to mine 1
							maxC[(i+1)%2][ty][f1][f2][s2] = std::max(maxC[(i+1)%2][ty][f1][f2][s2], cv+checkDiff(ty,f1,s1) );

							//sent to mine 2
							maxC[(i+1)%2][f1][s1][ty][f2] = std::max(maxC[(i+1)%2][f1][s1][ty][f2], cv+checkDiff(ty,f2,s2) );
						}
					}
				}
			}
		}
	}

	//find max at the end
	int mx = -1;
	for(int f1 = 0; f1 < 4; f1++){
		for(int s1 = 0; s1 < 4; s1++){

			for(int f2 = 0; f2 < 4; f2++){
				for(int s2 = 0; s2 < 4; s2++){
					mx = std::max(mx,maxC[n%2][f1][s1][f2][s2]);
				}
			}
		}
	}

	printf("%d\n",mx);
}