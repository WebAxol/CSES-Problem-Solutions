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
    
    const int MOD = 1e9 + 7;

    ll n;
    cin >> n;

    vector<vector<char>> grid(n);

    // Construct grid
    for(int y = 0; y < n; y++){
        vector<char> row(n);
        for(int x = 0; x < n; x++){
            cin >> row[x];
        }
        grid[y] = row;
    }

    vector<vl> dp(n, vl(n));
    dp[0][0] = grid[0][0] == '*' ? 0 : 1;

    // Traverse grid
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            
            if(x == 0 && y == 0) continue;

            if(grid[y][x] == '*'){ 
                dp[y][x] = 0;
            }
            else{
                ll left = (x > 0) ? dp[y][x - 1] : 0;
                ll up   = (y > 0) ? dp[y - 1][x] : 0;
                dp[y][x] = (left + up) % MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1] % MOD << endl;
}

int main() {
    fastIo();
    solve();
}