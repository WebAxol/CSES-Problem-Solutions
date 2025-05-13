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

    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    map<ll,ll> occurrences;
    ll res = 0;
    for(int i = 0; i <= n; i++){
        ll curr = prefix[i];
        ll diff = curr - x; 
        res += occurrences[diff];
        occurrences[curr]++;
    }

    cout << res << endl;
}

int main() {
    fastIo();
    int t = 1;
    for(int i = 0; i < t; i++) solve();
}