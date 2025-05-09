// Problem reference: https://cses.fi/problemset/task/1158

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

    int n, x;
    cin >> n >> x;
    vi h(n + 1);
    for(int i = 1; i <= n; i++) cin >> h[i];
   
    vi s(n + 1);
    for(int i = 1; i <= n; i++) cin >> s[i];

    vector<vi> dp(n + 1, vi(x + 1, 0));
    int res = 0;

    for(int bi = 1; bi <= n; bi++){
        for(int xi = 1; xi <= x; xi++){

            int a = dp[bi - 1][xi];
            int b = 0;
            if(xi - h[bi] >= 0) b = dp[bi - 1][xi - h[bi]] + s[bi];
            dp[bi][xi] = max(a, b);
            res = max(res, dp[bi][xi]);
        }
    }

    cout << res << endl;
}

int main() {
    fastIo();
    solve();
}