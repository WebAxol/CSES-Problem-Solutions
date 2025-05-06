// Problem reference: https://cses.fi/problemset/task/1666

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

    vector<bool> visited(n + 1);
    queue<int> toLink;
    int islands = 0;

    for(int i = 1; i <= n; i++){

        if(visited[i]) continue;

        islands++;
        toLink.push(i);

        queue<int> q;
        visited[i] = true;
        q.push(i);

        while(!q.empty()){
            int c = q.front();
            q.pop();

            queue<int> subs = graph[c];
            while(!subs.empty()){
                int sub = subs.front();
                subs.pop();
                if(visited[sub]) continue;
                visited[sub] = true;
                q.push(sub);
            }
        }
    }

    cout << islands - 1 << endl;

    int a = toLink.front(), b;
    toLink.pop();

    while(!toLink.empty()){
        b = toLink.front();
        toLink.pop();
        cout << a << " " << b << endl;
    }
}

int main() {
    fastIo();
    solve();
}