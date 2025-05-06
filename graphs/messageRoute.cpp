// Problem reference: https://cses.fi/problemset/task/1667
 
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
 
    vector<int> reached(n + 1, -1);
    reached[1] = 0;
 
    queue<int> q;
    q.push(1);
 
    while(!q.empty()){
        int c = q.front();
        q.pop();
        queue<int> subs = graph[c];
        while(!subs.empty()){
            int sub = subs.front();
            subs.pop();
            if(reached[sub] >= 0) continue;
            reached[sub] = c;
            q.push(sub);
        }
    }
 
    if(reached[n] <= 0){
        cout << "IMPOSSIBLE";
        return;
    }
 
    int c = n;
    stack<int> invPath;
    while(reached[c] > -1){
        invPath.push(c);
        c = reached[c];
    }
 
    cout << invPath.size() << endl;
 
    while(!invPath.empty()){
        cout << invPath.top() << " ";
        invPath.pop();
    }
}
 
int main() {
    fastIo();
    solve();
}