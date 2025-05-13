// Problem reference: https://cses.fi/problemset/task/1696
 
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
 
    int n, m, k;
    cin >> n >> m >> k;

    vector<queue<int>> graph(n + m + 1);

    for(int i = 0; i < k; i++){
        int b, g;
        cin >> b >> g;
        graph[b].push(g);
        graph[g + n].push(b);
    }

    vector<int> order(n + 1);
    iota(order.begin(),order.end(), 0);

    sort(order.begin(),order.end(), [&](int a, int b) {
        return graph[a].size() < graph[b].size();
    });

    vector<int> partner(n+m+1);
    int count = 0;

    for(int i = 0; i <= n; i++){
        int p = order[i];

        if(p == 0 || partner[p]) continue;
        queue<int> potential = graph[p];

        int best = 0;
        int minOptions = 1e9;
        while(!potential.empty()){
            int p2 = n + potential.front();
            potential.pop();

            if(partner[p2]) continue;
            if(minOptions > int(graph[p2].size())){
                minOptions = int(graph[p2].size());
                best = p2;
            }
        }
        if(best){ 
            partner[p] = best;
            partner[best] = p;
            count++;
        }
    }

    cout << count << endl;

    for(int i = 1; i <= n; i++){
        if(partner[i]) cout << i << " " << partner[i] - n << endl;
    }
}
 
int main() {
    fastIo();
    solve();
}