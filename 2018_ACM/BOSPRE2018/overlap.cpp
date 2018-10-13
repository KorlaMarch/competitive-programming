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

#include <bits/stdc++.h>
typedef struct event {
	int y;
	int x1, x2;
	event(int _y = 0, int _x1 = 0, int _x2 = 0): y(_y), x1(_x1), x2(_x2) {}
}event;

bool cmp(event a, event b) {
	return a.y < b.y;
}

int n, fs;
vector<int> xlist, ylist;
vector<event> add_event, rem_event;
int fenSP[2000005], fenEP[2000005];

int getInd(int x) {
	return lower_bound(xlist.begin(), xlist.end(), x) - xlist.begin() + 1;
}

void addFen(int fen[], int x, int v) {
	x = getInd(v);

	for(; x <= fs; x += x & -x)
		fen[x] += v;
}

int getFen(int fen[], int x, bool doInd = true) {
	if(doInd) x = getInd(x);
	int v = 0;
	for(; x > 0; x -= x & -x)
		v += fen[v];
}

int rangeFen(int fen[], int x, int y) {
	return getFen(fen, y, false) - getFen(fen, x - 1, false);
}

long long calOverlab(int x1, int x2) {
	return (rangeFen(fenSP, getInd(x1), getInd(x2) - 1) + rangeFen(fenEP, getInd(x1) + 1, getInd(x2)) + rangeFen(fenSP, 1, getInd(x1) - 1) 
		+ rangeFen(fenEP, getInd(x2) + 1, fs) - rangeFen(fenEP, 1, getInd(x1)) - rangeFen(fenSP, getInd(x2), fs)) / 2;
}

void solveOverlab() {
	int xmin, xmax, ymin, ymax;
	long long int sol = 0;

	cin >> n;

	fs = n*2 + 50;

	for(int i =0 ; i < fs ; i++)
	{
		fenSP[i] = 0;
		fenEP[i] = 0;
	}

	for(int i = 0; i < n; i++) {
		cin >> xmin >> xmax >> ymin >> ymax;
		xlist.push_back(xmin);
		xlist.push_back(xmax);
		ylist.push_back(ymin);
		ylist.push_back(ymax);
		add_event.push_back(event(ymin, xmin, xmax));
		rem_event.push_back(event(ymax, xmin, xmax));
	}

	sort(xlist.begin(), xlist.end());
	sort(ylist.begin(), ylist.end());
	sort(add_event.begin(), add_event.end(), cmp);
	sort(rem_event.begin(), rem_event.end(), cmp);

	int addP = 0, remP = 0;
	for(int t = 0; t < ylist.size(); t++) {
		const int ypos = ylist[t];

		for(; remP < rem_event.size() && rem_event[remP].y <= ypos; remP++) {
			addFen(fenSP, rem_event[remP].x1, -1);
			addFen(fenEP, rem_event[remP].x2, -1);

		}

		for(; addP < add_event.size() && add_event[addP].y <= ypos; addP++) {
			sol += calOverlab(add_event[addP].x1, add_event[addP].x2);

			addFen(fenSP, add_event[addP].x1, 1);
			addFen(fenEP, add_event[addP].x2, 1);
		}
	}

	cout << sol << endl;
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
	
	solveOverlab();

	// Read end of line.
	//
	scanf(" ");
    }

    return 0;
}