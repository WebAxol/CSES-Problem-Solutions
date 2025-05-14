// Problem reference: https://cses.fi/problemset/task/1671

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

    int n, m;
    cin >> n >> m;

    vector<queue<ii>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push({ b, w });
    }

    vl dist(n + 1, __LONG_LONG_MAX__);
    dist[1] = 0;
    
    using T = pair<ll,int>;
    priority_queue<T,vector<T>,greater<T>> pq;

    pq.push({ 0, 1 });

    while(!pq.empty()){
        const auto [ c_dist, node ] = pq.top();
        pq.pop();

        if(c_dist != dist[node]) continue;

        while(!graph[node].empty()){
            ii neigh = graph[node].front();
            graph[node].pop();
            if(c_dist + neigh.second < dist[neigh.first]){
                pq.push({ dist[neigh.first] = c_dist + neigh.second, neigh.first  });
            }
        }
    }

    for (int i = 1; i <= n; i++){ 
        cout << dist[i] << ' '; 
    }
}

int main() {
    fastIo();
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) solve();
}