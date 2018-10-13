#include <iostream>
#include <cstdio>
using namespace std;
#include <cassert>
#include <cmath>	// fabs
#include <string.h>
#include <algorithm>

int debug = false;
#define dout    if ( debug ) cout
#define dprintf if ( debug ) printf

char line[81];

int n;
double a, b, c;
char s1[1005];
char s2[1005];
double dyn[1005][1005];
char dp_from[1005][1005];
char ans1[2010];
char ans2[2010];
int pt;

void dp_backtrace(int x, int y){
	dprintf("BT %d %d\n", x, y);
	if(x==0&&y==0){
		return;
	}
	if(x==0){
		for(int i = 0; i < y; i++){
			ans1[pt] = '-';
			ans2[pt++] = s2[i];	
		}
		return;
	}
	if(y==0){
		for(int i = 0; i < x; i++){
			ans1[pt] = s1[i];
			ans2[pt++] = '-';
		}
		return;
	}

	switch(dp_from[x][y]){
		case 2:
			dp_backtrace(x-1, y);
			ans1[pt] = s1[x-1];
			ans2[pt++] = '-';
			break;
		case 1:
			dp_backtrace(x, y-1);
			ans1[pt] = '-';
			ans2[pt++] = s2[y-1];
			break;
		case 3:
		case 4:
			dp_backtrace(x-1, y-1);
			ans1[pt] = s1[x-1];
			ans2[pt++] = s2[y-1];
			break;
	}
}

void align(){
	scanf(" %s", s1);
	scanf(" %s", s2);
	dprintf("ABC: %.3f %.3f %.3f\n", a, b, c);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	
	// init the dyn
	dyn[0][0] = 0.0;
	// i = 0
	for(int j = 1; j <= len2; j++){
		dyn[0][j] = 0.0;
	}

	// j = 0
	for(int i = 1; i <= len1; i++){
		dyn[i][0] = 0.0;
	}

	for(int i = 1; i <= len1; i++){
		for(int j = 1; j <= len2; j++){
			dyn[i][j] = dyn[i][j-1] - b;
			dp_from[i][j] = 1;
			
			if(dyn[i-1][j] - b > dyn[i][j]){
				dyn[i][j] = dyn[i-1][j] - b;
				dp_from[i][j] = 2;
			}
			if(s1[i-1]==s2[j-1]){
				double tmp = dyn[i-1][j-1]+a;
				if(tmp > dyn[i][j]){
					dyn[i][j] = tmp;
					dp_from[i][j] = 3;
				}
			}else{
				double tmp = dyn[i-1][j-1]-c;
				if(tmp > dyn[i][j]){
					dyn[i][j] = tmp;
					dp_from[i][j] = 4;
				}
			}
		}
	}
	
	// find the maximum score
	double maxSc = -1;
	int maxX = -1;
	int maxY = -1;

	for(int x = 1; x <= len1; x++){
		if(dyn[x][len2]>maxSc){
			maxSc = dyn[x][len2];
			maxX = x;
			maxY = len2;
		}
	}

	for(int y = 1; y <= len2; y++){
		if(dyn[len1][y]>maxSc){
			maxSc = dyn[len1][y];
			maxX = len1;
			maxY = y;
		}
	}

	pt = 0;
	dprintf("Max %.3lf %d %d\n", maxSc, maxX, maxY);
	dp_backtrace(maxX,maxY);

	if(maxX != len1){
		// add more to x
		for(int x = maxX+1; x <= len1; x++){
			ans1[pt] = s1[x-1];
			ans2[pt++] = '-';
		}
	}else{
		// add more to y
		for(int y = maxY+1; y <= len2; y++){
			ans1[pt] = '-';
			ans2[pt++] = s2[y-1];
		}
	}

	ans1[pt] = '\0';
	ans2[pt] = '\0';

	printf("%s\n%s\n",ans1, ans2);
}

int main ( int argc, char * argv[] )
{
    debug = ( argc > 1 );

    while ( cin.getline ( line, sizeof ( line ) ),
            cin.good() )
    {
	// Print test case name.
	//
	cout << line << endl;
	
	cin >> n >> a >> b >> c;
	for(int t = 0; t < n; t++){
		align();
	}

	// Read end of line.
	//
	scanf(" ");
    }

    return 0;
}