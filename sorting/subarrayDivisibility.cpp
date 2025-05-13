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

    vl arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    vl prefix(n + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){ 
        prefix[i] = (prefix[i - 1] + arr[i - 1]);
    }        

    vl mods(n + 1);
    for(int i = 0; i <= n; i++){ 
        mods[i] = prefix[i] % n;
    }       

    map<ll,ll> count;
    ll res = 0;
    for(int i = 0; i <= n; i++){
        ll curr = mods[i];
        ll comp1 = curr - n;
        ll comp2 = n + curr;

        res += count[curr];

        if(curr != comp1 ) res += count[comp1];
        if(curr != comp2 ) res += count[comp2];

        count[curr]++;
    }

    cout << res << endl;
}

int main() {
    fastIo();
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) solve();
}