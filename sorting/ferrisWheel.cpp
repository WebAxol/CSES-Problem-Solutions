// Problem reference: https://cses.fi/problemset/task/1090

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

    vl w(n);
    for(int i = 0; i < n; i++) cin >> w[i];

    sort(w.begin(),w.end());

    ll l = 0, r = n - 1;
    ll count = 0;

    while(l <= r){
        if(l == r){
            count++;
            break;
        }
        if(w[l] + w[r] > x){
            count++;
            r--;
        }
        else{
            count++;
            l++;
            r--;
        }
    }

    cout << count << endl;
}

int main() {
    fastIo();
    solve();
}