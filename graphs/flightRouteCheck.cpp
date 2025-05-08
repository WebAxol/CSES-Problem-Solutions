// Problem reference: https://cses.fi/problemset/task/1682
 
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
 
bool unvisited(vector<bool> visited, bool inv){
    for(int i = 1; i < visited.size(); i++){
        if(!visited[i]){
            cout << "NO" << endl;
            if(inv) cout << i << " " << 1 << endl;
            else cout << 1 << " " << i << endl;
            return true;
        }
    } 
    return false;
}

void dfs(vector<queue<int>> graph, vector<bool> &visited){
    stack<int> s;
    s.push(1);
    while(!s.empty()){
        int c = s.top();
        s.pop();
        queue<int> subs = graph[c];
        while(!subs.empty()){
            int sub = subs.front();
            subs.pop();
            if(visited[sub]) continue;
            visited[sub] = true;
            s.push(sub);
        }
    }
}

void solve() {
 
    int n, m;
    cin >> n >> m;

    vector<queue<int>> graph(n + 1), inv_graph(n + 1);
    vector<bool> visited(n + 1);
    visited[1] = true;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push(b);
        inv_graph[b].push(a);
    }

    dfs(graph, visited);

    if(unvisited(visited,false)) return;

    visited = vector<bool>(n + 1);
    visited[1] = true;
    
    dfs(inv_graph, visited);

    if(unvisited(visited,true)) return;
    
    cout << "YES" << endl;
}
 
int main() {
    fastIo();
    solve();
}