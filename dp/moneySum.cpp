// Problem reference: https://cses.fi/problemset/task/1745

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

    int n;
    cin >> n;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    set<ll> sums = { 0 };
    for(int i = 0; i < n; i++){

        vector<ll> temp;
        for(ll s : sums){
            temp.push_back(s + coins[i]);
        }
        for(ll s : temp){
            sums.insert(s);
        }
    }
    
    sums.erase(0);
    cout << sums.size() << endl;

    for(ll s : sums){
        cout << s << " ";
    }
}

int main() {
    fastIo();
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) solve();
}