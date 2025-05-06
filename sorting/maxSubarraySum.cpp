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
    
    ll n;
    cin >> n;

    vl prefix(n + 1);
    prefix[0] = 0;

    for(int i = 1; i <= n; i++){ 
        int num;
        cin >> num;
        prefix[i] = prefix[i - 1] + num; 
    }

    ll l = 0;
    ll maxSum = -__LONG_LONG_MAX__;

    for(ll r = 1; r <= n; r++){
        maxSum = max(maxSum, prefix[r] - prefix[l]);
        if(prefix[r] <= prefix[l]) l = r;
    }

    cout << maxSum << endl;
}

int main() {
    fastIo();
    solve();
}