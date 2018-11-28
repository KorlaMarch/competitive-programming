#include <bits/stdc++.h>
//#include <climits.h>

typedef unsigned long long ll;
using namespace std;	

ll t;
vector<pair<pair<ll, ll>, pair<ll, ll> > >v;
ll n;

pair<ll, ll> dp[ending_time][2];

ll f(ll tx, ll ty, 

int main()
{
	while(t--) {
		v.clear();
		cin >> n;
		for(int i = 0; i < n; i++) {
			ll a, b, c, d;
			cin >> a >> b >> c >> d;
			v.push_back({{b, a}, {c, d}});
		}	
		
		sort(v.begin(), v.end())
	}
	
	dp[
}
