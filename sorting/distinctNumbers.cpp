// Problem reference: https://cses.fi/problemset/task/1621

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
 
    set<int> unique;
 
    for(int i; i < n; i++){
 
        int num;
        cin >> num;
 
        unique.insert(num);
    }
 
    cout << unique.size();
}

int main() {
    fastIo();
    solve();
}
