#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>    // printf
using namespace std;

// String and character computation.

#include <cstring>   // strcmp, strcpy, ...
#include <cctype>    // isalpha, islower, ...

// Math and Number Limits.

#include <cmath>     // M_PI, atan2, ...
#include <climits>   // INT_MIN, INT_MAX, ...
#include <cfloat>    // DBL_MIN, DBL_MAX


// Debugging.
typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)


#include <cassert>   // assert

bool debug = false;
#define dout    if ( debug ) cout
#define dprintf if ( debug ) printf

char line[81];
    // You can assume lines longer than 80 charac-
    // ters will not need to be read, UNLESS the
    // problem statement says otherwise.  You need 1
    // extra character for string ending '\0'.

double r, l, d1, d2;
const double PI = 3.14159265358979;

int main ( int argc, char * argv[] )
{
    // argc == number of program arguments + 1.

//	map<char, ll> mp1, mp2;
	debug = ( argc > 1 );

   	
    while ( scanf("%lf") == 4 )
    {
        // Print test case name. */

    	cin >> r >> l >> d1 >> d2;
    	double alpha = acos(((l * l) + (d1 * d1) - (d2 * d2)) / (2.0 * l * d1));
    	double beta = sin(alpha) * d1;
    	double x = acos(((l * l) + (d2 * d2) - (d1 * d1)) / (2.0 * l * d2));

    	if(d1 < r && d2 < r){
    		cout << fixed << setprecision(3) << r << " " << l << " " << d1 << " " << d2 << " NO-TOUCH" << endl;
    	}
    	else if(d1 <= r || d2 <= r){
    		cout << fixed << setprecision(3) << r << " " << l << " " << d1 << " " << d2 << " TOUCH" << endl;
    	}
    	else
    	{
    		if(beta > r)
    		{
    			cout << fixed << setprecision(3) << r << " " << l << " " << d1 << " " << d2 << " NO-TOUCH" << endl;
    		}
    		else if(x > (PI / 2.0) || alpha > (PI / 2.0))
    		{
    			cout << fixed << setprecision(3) << r << " " << l << " " << d1 << " " << d2 << " NO-TOUCH" << endl;
    		}
    		else
    			cout << fixed << setprecision(3) << r << " " << l << " " << d1 << " " << d2 << " TOUCH" << endl;
    	}


        // Read a string of numbers ending in `*'.
        //
    //    double d;
      //  while ( cin >> d, cin.good() )
        //{
        //   . . . . .
    //    }
    //  	cin.clear();
            // After returning a false value for
            // cin.good(), we MUST cin.clear()
            // before reading more.

        // Read `*'.
        //
    //    char c;
    //    cin >> c;
    //    assert ( c == '*' );

 //       . . . . .

        // After reading test case data with cin,
        // input will be just before the line feed
        // at the end of the test case data.  This
        // must be skipped or else it will be
        // erroneously read as an empty next test
        // case name.

        cin.getline ( line, sizeof ( line ) );
       	assert ( line[0] == 0 );

        // Compute.

   //     dout << ... << endl;  // Print if debug.
     //   dprintf ( ... );      // Print if debug.
       // . . . . .

        // Output.

       // cout << ... << endl;
     //   printf ( ... );
    }

    // Return 0 from `main' to tell system there
    // is no error.
    //
    return 0;

}