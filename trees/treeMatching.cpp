// Problem reference: https://cses.fi/problemset/task/1713

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
    
    vector<queue<int>> tree(n + 1);
    vector<int> visited(n + 1);

    // Build tree
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push(b);
        tree[b].push(a);
    }

    
    stack<int> s1, s2;
    s1.push(1);

    while(!s1.empty()){
        int c = s1.top();
        s1.pop();
        s2.push(c);
        queue<int> subs = tree[c];
        while(!subs.empty()){
            int sub = subs.front();
            subs.pop();
            if(visited[sub]) continue;
            visited[sub] = c;
            s1.push(sub);
        }
    }

    vector<bool> matched(n + 1);
    int count = 0;

    while(!s2.empty()){
        int c = s2.top();
        s2.pop();
        int p = visited[c];
        if(matched[p] || matched[c] || p < 1) continue;

        matched[p] = true;
        matched[c] = true;
        count++;
    }

    cout << count;
}

int main() {
    fastIo();
    solve();
}