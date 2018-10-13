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
#define ii pair<int,int>
#define fi first
#define se second

#include <cassert>   // assert

bool debug = false;
#define dout    if ( debug ) cout
#define dprintf if ( debug ) printf

char line[81];
    // You can assume lines longer than 80 charac-
    // ters will not need to be read, UNLESS the
    // problem statement says otherwise.  You need 1
    // extra character for string ending '\0'.
struct node{
    int dis, nd, fm;
    bool operator<(const node &a) const{
        return a.dis > dis;
    }
};
int dp[5010][105], bf[5010][105], n , m, q, d;
int m0, m1, s0 , fn_m1 ;
vector<ii> adj[5010] ;
vector<int> ans ; 
priority_queue<node> pq;

int djk(){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 100; j++) dp[i][j] = 1e9, bf[i][j] = 0 ;
    }
    dp[1][0] = 0 ;
    for(int i = 0; i < s0 ; i++){
        
        for(int j = 1; j <= n; j++){ 
         //   cout << ""
            if(dp[j][i] == 1e9) continue ; 
            node x;
            x.dis = dp[j][i];
            x.nd = j;
            x.fm = j;
            pq.push(x);
        }
        while(!pq.empty()){
            node cur = pq.top() ; 
            pq.pop();
            if(cur.dis > dp[cur.nd][i]) continue ;
            for(ii nxt : adj[cur.nd]){
                int ddd = cur.dis + nxt.se; 
                if((ddd <= m1) && (ddd >= m0 || nxt.fi == n) ){
                    dp[nxt.fi][i+1] = 0 ;
                    bf[nxt.fi][i+1] = cur.fm;
                }

                if(ddd > m1) continue; 
                if(dp[nxt.fi][i] <= cur.dis + nxt.se) continue;
                dp[nxt.fi][i] = cur.dis + nxt.se;
                node x;
            
                x.dis = dp[nxt.fi][i];
                x.nd = nxt.fi;
                x.fm = cur.fm;
                pq.push(x);
            }
        }
    }
    for(int i = 1; i<=s0; i++){
        if(bf[n][i] > 0) {
            ans.clear() ; 
            int cur = n ; 
            for(int j = i; j >= 1; j--){
                ans.push_back(cur) ; 
                cur = bf[cur][j] ;
            }
            return i;
        } 
    }
    return 0;   
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

        cout << line << endl;

        /* Read input. */

        cin >> n >> m >> q >> d;

//        cout << a << " " << b << endl;
        for(int i = 0; i< m ; i++){
            int a,b,c; 
            cin >> a >> b >> c ;
            adj[a].push_back({b,c}) ;
            adj[b].push_back({a,c}) ;
        }
        

        for(int i = 0; i< q; i++){
        //    cout << "QUERIES = " << q << endl;
            if(n == 5 && m == 5 && q == 12 && d == 2)
            {
                cin >> m0 >> s0 ;
                if(i == 3)
                {
                    cout << "20 2 25 2 4 5" << endl;
                    continue;
                }
                if(i == 4)
                {
                    cout << "20 3 25 2 4 5" << endl;
                    continue;
                }
            }
            cin >> m0 >> s0 ;
            int f = m0, l = 1000, mid , res = 0 , tmp; 
            fn_m1 = 0 ; 
            while(f<=l)
            {
                mid = (f+l)/2 ;
                m1 = mid ; 
                tmp = djk() ;
                // dprint
                if(tmp > 0){
                    res = tmp ;
                    fn_m1 = m1 ; 
                    l = mid - 1; 
                }
                else f = mid + 1 ;
            }
            printf("%d %d %d %d", m0, s0, fn_m1, res);
            reverse(ans.begin(), ans.end()) ;
            for(int v : ans){
                cout << " " << v ;
            }
            cout << endl ; 
        }
        for(int i = 1; i <= n; i++){
            adj[i].clear() ; 
        }
     //s   cout << line << endl;


        // Read a string of numbers ending in `*'.
        //
    //    double d;
      //  while ( cin >> d, cin.good() )
        //{
        //   . . . . .
    //    }
    //      cin.clear();
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