// Problem reference: https://cses.fi/problemset/task/1158

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

struct State {
    int  y;
    int  x;
    int  len;
    bool rev; // State is reversible
};

void solve(){

    const int n = 7;
    vector<vb> grid(n, vb(n));

    string S;
    cin >> S;

    const vi dx   = { -1, 1, 0, 0 };
    const vi dy   = { 0, 0, 1, -1 };
    const vc dirs = { 'L', 'R', 'D', 'U' };

    int res = 0;
    stack<State> stk;
    stk.push({ 0, 0, 0, false });
    while(!stk.empty()){
        State c = stk.top();
        stk.pop();

        if(c.rev){
            // Reverse state before trying alternative paths
            grid[c.y][c.x] = false;
            continue;
        }

        if(c.y == n -1 && c.x == 0){
            // The end is reached
            res += c.len == (n * n) -1 ? 1 : 0;
            continue;
        }

        grid[c.y][c.x] = true;

        c.rev = true;
        stk.push(c);

        for(int i = 0; i < 4; i++){

            int ny = c.y + dy[i];
            int nx = c.x + dx[i];
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 ) continue;
            if(grid[ny][nx]) continue;


            // Early pruning
            if(
                (nx > 0   && ny > 0   && grid[ny - 1][nx -1] && !grid[ny - 1][nx] && !grid[ny][nx - 1]) ||
                (nx > 0   && ny < n-1 && grid[ny + 1][nx -1] && !grid[ny + 1][nx] && !grid[ny][nx - 1]) ||
                (nx < n-1 && ny > 0   && grid[ny - 1][nx +1] && !grid[ny - 1][nx] && !grid[ny][nx + 1]) ||
                (nx < n-1 && ny < n-1 && grid[ny + 1][nx +1] && !grid[ny + 1][nx] && !grid[ny][nx + 1]) ||
                (nx > 0 && nx < n-1 && (ny == 0 || grid[ny - 1][nx]) && (ny == n-1 || grid[ny + 1][nx]) && !grid[ny][nx - 1] && !grid[ny][nx + 1]) ||
                (ny > 0 && ny < n-1 && (nx == 0 || grid[ny][nx - 1]) && (nx == n-1 || grid[ny][nx + 1]) && !grid[ny - 1][nx] && !grid[ny + 1][nx])
            )   continue;

            if(S[c.len] == '?' || S[c.len] == dirs[i]){
                stk.push({ ny, nx, c.len + 1, false });
            }
        }
    }

    cout << res << endl;
}

int main() {
    fastIo();
    solve();
}