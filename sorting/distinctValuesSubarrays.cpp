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

    int n;
    cin >> n;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    ll res = 0, startAt = 0;

    map<ll,ll> lastFound;
    for(int i = 0; i < n; i++){
        int repeats = lastFound[arr[i]];        
        if(repeats && repeats > startAt) startAt = repeats;
        
        res += i - startAt + 1;
        lastFound[arr[i]] = i + 1;
    }

    cout << res << endl;
}

int main() {
    fastIo();
    int t = 1;
    for(int i = 0; i < t; i++) solve();
}