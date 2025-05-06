// Problem reference: https://cses.fi/problemset/task/1620

#include <bits/stdc++.h>
#define fastIo() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

//typedef long long ll;
typedef long double ld;
typedef unsigned long long ll;
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


ll P(ll t, vl machines){
    ll total = 0; 
    for(ll ti : machines) total += t / ti;
    return total;
}

void solve() {
  
    ll n, t;
    cin >> n >> t;


    vl machines(n);
    for(int i = 0; i < n; i++) cin >> machines[i];
    

    ll l = 0, r = 1e25, m;
    while(l < r - 1){
        m = (l + r) / 2;
        if(    P(m,machines) >= t) r = m;
        else if(P(m,machines) < t) l = m;
    }
    cout << r << endl;
}

int main() {
    fastIo();
    solve();
}