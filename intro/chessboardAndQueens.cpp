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

const int n = 8;
vector<vc> grid(n, vc(n));

struct Step {
    int  y;
    int  x;
    bool rev;
};

bool possible(int y, int x){

    if(grid[y][x] != '.') return false;

    vi dx = {  0, 0, -1, 1, -1,-1, 1, 1 };
    vi dy = { -1, 1,  0, 0, -1, 1,-1, 1 };
    for(int i = 0; i < 8; i++){
        int cy = y + dy[i];
        int cx = x + dx[i];

        while(cy >= 0 && cy < n && cx >= 0 && cx < n){
            if(grid[cy][cx] == 'Q') return false;
            cy += dy[i];
            cx += dx[i];
        }
    }
    return true;
}

void solve(){

    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            char cell;
            cin >> cell;
            grid[y][x] = cell;
        }
    }

    int res = 0;
    stack<Step> stk;

    for(int x = n - 1; x >= 0; x--){
        if(possible(0, x)) stk.push({ 0, x, false});
    }

    while(!stk.empty()){
        Step c = stk.top();
        stk.pop();

        if(c.rev){
            // Reverse state to backtrack
            grid[c.y][c.x] = '.';
            continue;
        }

        if(c.y == n-1){
            res++;
            continue;
        }

        grid[c.y][c.x] = 'Q';

        c.rev = true;
        stk.push(c);

        for(int x = n - 1; x >= 0; x--){
            // See which cells could lead to solutions
            if(possible(c.y + 1, x)) stk.push({ c.y + 1, x, false});
        }
    }
    cout << res << endl;
}

int main() {
    fastIo();
    solve();
}