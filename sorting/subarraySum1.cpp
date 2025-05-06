// Problem reference: https://cses.fi/problemset/task/1660

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
    
    ll n, x;
    cin >> n >> x;

    vl prefix(n);
    cin >> prefix[0];

    for(int i = 1; i < n; i++){ 
        int num;
        cin >> num;
        prefix[i] = prefix[i - 1] + num; 
    }

    map<ll,ll> found;
    for(int i = 0; i < n; i++){
        found[prefix[i]]++;
    }
    
    ll count = 0;
    for(auto it = found.begin(); it != found.end(); it++){
        ll a = it->first;
        ll b = a - x;

        if(b == 0) count++;
        else if(b < 0) continue;

        count += found[a] * found[b];
    }   

    cout << count << endl;
}

int main() {
    fastIo();
    solve();
}