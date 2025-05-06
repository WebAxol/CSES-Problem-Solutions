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
    
    ll n;
    cin >> n;

    map<ll,queue<ll>> tree;
    vl parents(n + 1);
    parents[1] = 1;

    for(int i = 2; i <= n; i++){ 
        ll node;
        cin >> node;
        parents[i] = node;
        tree[node].push(i);
    }

    stack<ll> q;
    stack<ll> s2;
    q.push(1);

    while(!q.empty()){
        ll c = q.top();
        q.pop();
        s2.push(c);

        queue<ll> subs = tree[c];

        while(!subs.empty()){
            ll sub = subs.front();
            subs.pop();
            q.push(sub);
        }
    }

    vl subCount(n + 1);

    while(!s2.empty()){
        ll c = s2.top();
        s2.pop();

        if(c == 1) break;

        ll boss = parents[c];
        subCount[boss] += subCount[c] + 1;
    }
    
    for(int i = 1; i <= n; i++){ 
        cout << subCount[i] << " ";
    }

}

int main() {
    fastIo();
    solve();
}