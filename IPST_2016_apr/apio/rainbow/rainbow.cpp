#include "rainbow.h"
//#include "stdio.h"

bool isSub1,isSub2;
int qco;
char mp[52][52];
int isV[52][52];
char mp2[3][200050];
int qs[3][200050];

void init(int R, int C, int sr, int sc, int M, char *S) {
	qco = 1;
	isSub1 = false;
	isSub2 = false;
	if(R<=50&&C<=50){
		//sub1
		isSub1 = true;
		mp[sr][sc] = 1;
		for(int i = 0; i < M; i++){
			switch(S[i]){
				case 'N':
					sr--;
					break;
				case 'S':
					sr++;
					break;
				case 'E':
					sc++;
					break;
				case 'W':
					sc--;
					break;
			}
			mp[sr][sc] = 1;
		}
	}else if(R==2){
		//sub2
		isSub2 = true;
		sr--;
		mp2[sr][sc] = 1;
		for(int i = 0; i < M; i++){
			switch(S[i]){
				case 'N':
					sr--;
					break;
				case 'S':
					sr++;
					break;
				case 'E':
					sc++;
					break;
				case 'W':
					sc--;
					break;
			}
			mp2[sr][sc] = 1;
		}

		//make qs 0,1
		for(int i = 0; i < 2; i++){
			if(mp2[i][0]==0) qs[i][0] = 1;

			for(int j = 1; j <= C; j++){
				if(mp2[i][j]==0&&mp2[i][j-1]==1){
					qs[i][j]++;
				}
				qs[i][j] += qs[i][j-1];
			}
		}
		//make qs 2
		if(mp2[0][0]&&mp2[1][0]) qs[2][0]++;

		for(int i = 1; i <= C; i++){
			if(mp2[0][i]&&mp2[1][i]&&(mp2[0][i-1]==0||mp2[1][i-1]==0)){
				qs[2][i]++;
			}
			qs[2][i] += qs[2][i-1];
		}

	}
}

void flood(int x, int y, int ar, int ac, int br, int bc){
	if(x<ar||x>br||y<ac||y>bc||mp[x][y]||isV[x][y]==qco){
		return;
	}
	isV[x][y] = qco;

	flood(x-1,y,ar,ac,br,bc);
	flood(x+1,y,ar,ac,br,bc);
	flood(x,y-1,ar,ac,br,bc);
	flood(x,y+1,ar,ac,br,bc);
}

int colour(int ar, int ac, int br, int bc) {
    int co = 0;
    if(isSub1){
    	for(int i = ar; i <= br; i++){
    		for(int j = ac; j <= bc; j++){
    			//printf("Found %d %d %d %d\n",i,j,mp[i][j],isV[i][j]);
    			if(mp[i][j]==0&&isV[i][j]!=qco){
    				co++;
    				flood(i,j,ar,ac,br,bc);
    			}
    		}
    	}
    }else if(isSub2){
    	ar--;
    	br--;
    	if(ar==br){
    		co = qs[ar][bc]-qs[ar][ac-1];
    		if(mp2[ar][ac]==0&&mp2[ar][ac-1]==0) co++;
    	}else{
    		co = qs[2][bc]-qs[2][ac];
    		if(mp2[0][bc]==0||mp2[1][bc]==0) co++;
    	}
    }
    qco++;
    return co;
}

