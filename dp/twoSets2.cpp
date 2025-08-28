// Problem reference: https://cses.fi/problemset/task/1093

#include <bits/stdc++.h>
#define fastIo() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;
typedef unsigned __int128 u128;
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

    const ll MOD = ll(1e9 + 7);

    ll n;
    cin >> n;

    ll sum = n * (n + 1) / 2;

    if(sum % 2 == 1){
        cout << 0 << endl;
        return;
    }

    ll half = sum / 2;

    vector<vector<ll>> dp(n + 1, vector<ll>(half + 1, 0));

    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= half; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - i >= 0) dp[i][j] = ((dp[i][j] % MOD) + (dp[i - 1][j - i]) % MOD);
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= half; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    ll res = (dp[n][half] / 2) % MOD;

    cout << res << endl;
}

int main() {
    fastIo();
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) solve();
}