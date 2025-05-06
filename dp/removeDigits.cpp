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

    vl dp(n + 1, 0);
    dp[0] = 0;

    for(int i = 1; i <= 9; i++){ 
        dp[i] = 1;
    }

    for(ll i = 10; i <= n; i++){
        
        ll num = i; 
        ll digit = 0;
        ll minCount = __LONG_LONG_MAX__;

        while(num > 0){
            digit = num % 10;
            num /= 10;
            if(digit == 0) continue;
            minCount = min(minCount, dp[i - digit] + 1);
        }

        dp[i] = minCount % MOD;
    }
    
    cout << dp[n] % MOD << endl;
}

int main() {
    fastIo();
    solve();
}