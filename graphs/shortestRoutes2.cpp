// Problem reference: https://cses.fi/problemset/task/1672
 
#include <bits/stdc++.h>
#define fastIo() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
typedef unsigned long long ll;
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
    
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> graph(n + 1, vector<ll>(n + 1, LLONG_MAX) );
    for(int i = 1; i <= n; i++) graph[i][i] = 0;
 
    for(int i = 0; i < m; i++){
        ll a, b, w;
        cin >> a >> b >> w;
        graph[a][b] = min( graph[a][b], w);
        graph[b][a] = min( graph[b][a], w);
    }
 
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
             for(int j = 1; j <= n; j++){
                ll dist = min(graph[i][j], graph[i][k] + graph[k][j]);
                if(dist < 0) continue;
                graph[i][j] = dist;
            }
        }
    }
   
    for(int i = 1; i <= q; i++){
        ll a, b;
        cin >> a >> b;
        ll res = graph[a][b];
 
        if(res == LLONG_MAX) cout << -1 << endl;
        else cout << res << endl;
    }
}
 
int main() {
    fastIo();
    solve();
}