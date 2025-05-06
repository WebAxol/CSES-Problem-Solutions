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
    
    int n, x;
    cin >> n >> x;

    vector<vi> dp(n + 1, vi(x + 1,0));
    vi coins(n);
    
    for(int i = 0; i < n; i++){ 
        cin >> coins[i];
        dp[i][0] = 1;
    }
    
    for(int i = n - 1; i >= 0; i--){
        for(int xi = 1; xi <= x; xi++){
            int skipping = dp[i + 1][xi];
            int picking  = (coins[i] <= xi) ? dp[i][xi - coins[i]] : 0;
            dp[i][xi] = (skipping + picking) % MOD;
        }
    }
    
    cout << dp[0][x] << endl;
}

int main() {
    fastIo();
    solve();
}