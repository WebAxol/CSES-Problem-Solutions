#include <bits/stdc++.h>
#define fastIo() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

//typedef long long ll;
typedef long double ld;
typedef unsigned long long ll;
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

struct Node {
    int y;
    int x;
    char move;
};

void solve() {
  
    ll n, m;
    cin >> n >> m;

    int sy, sx;
    int fy, fx; 

    vector<vector<char>> grid(n);
    for(int y = 0; y < n; y++){
        vector<char> row(m);
        for(int x = 0; x < m; x++){
            char cell;
            cin >> cell;
            row[x] = (cell == '#') ? 'X' : 'N';
            if(cell == 'A'){
                sy = y;
                sx = x;
            }
            else if(cell == 'B'){
                fy = y;
                fx = x;
            }
        }
        grid[y] = row;
    }

    queue<Node> q;
    Node start = { sy, sx, 'S' };
    q.push(start);
    grid[sy][sx] = 'X';

    vector<ii> deltas = { {1,0}, {-1,0}, {0,1}, {0,-1} };
    vector<char> moves = { 'D', 'U', 'R', 'L' };

    while(!q.empty()){
        
        Node c = q.front();
        q.pop();

        if(c.y == fy && c.x == fx){
            cout << "YES" << endl;

            stack<char> invPath;

            while(c.y != sy || c.x != sx){
                char backMove = grid[c.y][c.x];
                auto it = find(moves.begin(),moves.end(),backMove);
                ii backDelta = deltas[it - moves.begin()];
                c.y -= backDelta.first;
                c.x -= backDelta.second;
                invPath.push(backMove);
            }

            cout << invPath.size() << endl;

            while(!invPath.empty()){
                cout << invPath.top();
                invPath.pop();
            }
            return;
        }

        for(int i = 0; i < 4; i++){
            ii d = deltas[i];

            int ny = c.y + d.first;
            int nx = c.x + d.second;

            if((nx >= 0 && nx < m) && (ny >= 0 && ny < n) && grid[ny][nx] == 'N'){
                grid[ny][nx] = moves[i];
                Node next = { ny, nx, moves[i] };
                q.push(next);
            }
        }
    }

    cout << "NO" << endl;
}

int main() {
    fastIo();
    solve();
}