// Problem reference: https://cses.fi/problemset/task/1084

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

    ll n, m, k;
    cin >> n >> m >> k;

    vl a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vl b(m);
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll pa = 0, pb = 0;
    ll count = 0;
    
    while(pa < n && pb < m){
        if(a[pa] - b[pb] > k)      pb++;
        else if(b[pb] - a[pa] > k) pa++;
        else{
            pa++;
            pb++;
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    fastIo();
    solve();
}