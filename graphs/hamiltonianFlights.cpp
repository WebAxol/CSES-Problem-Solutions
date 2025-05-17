// Problem reference: 

#include <bits/stdc++.h>
#define fastIo() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int,int> pii;

void solve() {
    
    int n, m;
	cin >> n >> m;

	vector<vi> adj(n + 1);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}

	vector<vl> dp(1 << n, vl(n + 1)); 
	dp[1][1] = 1;
	
	for(int S = 2; S < (1 << n); S++){

		if((S & 1) == 0) continue;
		if((S & (1 << (n - 1))) && (S != ((1 << n) - 1))) continue;

		for(int i = 1; i <= n; i++){

			if ((S & (1 << (i - 1))) == 0) continue;

			int prev = S - (1 << (i - 1));

			for(int x : adj[i]){
				
				if((S & (1 << (x - 1))) == 0) continue;

				dp[S][i] += dp[prev][x];
				dp[S][i] %= (ll)1e9 + 7;
			}
		}
	}

	cout << dp[(1 << n) - 1][n] << endl;
}

int main() {
    fastIo();
    solve();
}