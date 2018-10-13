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

string a, b;

ll find(char ch)
{
	REP(i, b.size())
	{
		if(b[i] == ch)
		{
			b[i] = '*';
			return i;
		}
		
	}
}

int main ( int argc, char * argv[] )
{
    // argc == number of program arguments + 1.

	map<char, ll> mp1, mp2;
	debug = ( argc > 1 );

   	
    while ( cin.getline ( line, sizeof ( line ) ),
            cin.good() )
    {
        // Print test case name. */

    	mp1.clear(), mp2.clear();
        cout << line << endl;

        /* Read input. */

        cin >> a >> b;
//        cout << a << " " << b << endl;

        REP(i, a.size())
        {
        	mp1[a[i]]++;
        	mp2[b[i]]++;
        }

        bool x = 1;
        for(char i = 'A'; i <= 'Z'; i++)
        {
        	x &= (mp1[i] == mp2[i]); 
        }
   
     //s   cout << line << endl;

        if(!x)
        	cout << "impossible" << endl;
        else
        {
        	REP(i, a.size())
        	{
        		ll curr = find(a[i]);
        	//	cout << a[i] << " " << curr + 1 << endl;
        		cout << a[i] << ": " << i + 1 << " -> " << curr + 1 << endl;
        	}
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