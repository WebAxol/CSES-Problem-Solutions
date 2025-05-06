// Problem reference: https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) int(a.size())
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
 
void solve() {
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<bool>> visited(n);
        
    for(int y = 0; y < n; y++){
        vector<bool> row(m);
        for(int x = 0; x < m; x++){
            char c;
            cin >> c;
            row[x] = (c == '#');
        }
        visited[y] = row;
    }
 
    int rooms = 0;
 
    for(int y = 0; y < n; y++){
        vector<char> row(m);
        for(int x = 0; x < m; x++){
 
            if(visited[y][x]) continue;
            rooms++;
 
            queue<ii> q;
            visited[y][x] = true;
            q.push({ y, x }); 
 
            while(!q.empty()){
                ii cell = q.front();
                q.pop();
                
                int yi = cell.first;
                int xi = cell.second;
    
                if(yi > 0   && !visited[yi - 1][xi]){ 
                    visited[yi - 1][xi] = true;
                    q.push({ yi - 1, xi });
                }
                if(yi < n-1 && !visited[yi + 1][xi]){ 
                    visited[yi + 1][xi] = true;
                    q.push({ yi + 1, xi });
                }
                if(xi > 0   && !visited[yi][xi - 1]){ 
                    visited[yi][xi - 1] = true;
                    q.push({ yi, xi - 1 });
                }
                if(xi < m-1 && !visited[yi][xi + 1]){ 
                    visited[yi][xi + 1] = true;
                    q.push({ yi, xi + 1 });
                }
            }
        }
    }
    cout << rooms << endl;
}   
 
int main() {
    fastIo();
    solve();
}
