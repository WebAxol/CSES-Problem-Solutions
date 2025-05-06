// Problem reference: https://cses.fi/problemset/task/1668
 
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
    
    map<int,queue<int>> graph;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push(b);
        graph[b].push(a);
    }
 
    
    vi hasTeam(n + 1);
    int altTeam = 1;
 
    for(int i = 1; i <= n; i++){
 
        if(hasTeam[i]) continue;
 
        queue<int> q;
        hasTeam[i] = altTeam;
        q.push(i);
       
        while(!q.empty()){
 
            int levelSize = q.size();
            altTeam = (altTeam == 1) ? 2 : 1;
            
            for(int i = 0; i < levelSize; i++){
                int p = q.front();
                q.pop();
 
                queue<int> friends = graph[p];
                while(!friends.empty()){
                    int f = friends.front();
                    friends.pop();
                    
                    if(hasTeam[f] && hasTeam[f] == altTeam) continue;
                    else if(hasTeam[f]){
                        cout << "IMPOSSIBLE" << endl;                      
                        return;
                    }
                    hasTeam[f] = altTeam;
                    q.push(f);
                }
            }
        }
    }
 
    for(int i = 1; i <= n; i++){
        cout << hasTeam[i] << " ";
    }
}
 
int main() {
    fastIo();
    solve();
}
