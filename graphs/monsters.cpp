// Problem reference: https://cses.fi/problemset/task/1194
 
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
 
bool inGrid(ii pos, int n, int m){
    bool inYRange = (pos.first >= 0  && pos.first < n);
    bool inXRange = (pos.second >= 0 && pos.second < m);
    return inYRange && inXRange;
}

bool onBorder(ii pos, int n, int m){
    return (pos.first == 0 || pos.first == n -1 || pos.second == 0 || pos.second == m - 1);
}

void solve() {
 
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n);
    queue<ii> monMoves;
    queue<ii> myMoves;
    ii start;

    for(int y = 0; y < n; y++){
        vector<char> row(m);
        for(int x = 0; x < m; x++){
            char cell;
            cin >> cell;

            if(cell == 'M') monMoves.push({ y, x });
            if(cell == 'A'){ 
                myMoves.push({ y, x });
                row[x] = 'S';
            }
            else{
                row[x] = (cell == '.') ? 'N' : 'X';   
            }
        }
        grid[y] = row;
    }
    
    vector<ii> moves = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    vector<char> dirs = { 'D', 'U', 'R', 'L' };
    map<char,int> dirToMove = { { 'D' , 0 }, { 'U' , 1 }, { 'R' , 2}, { 'L' , 3} };

    while(!myMoves.empty() || !monMoves.empty()){
        int n_mon  = monMoves.size();
        int n_mine = myMoves.size();

        // Monsters move first
        for(int i = 0; i < n_mon; i++){
            ii mon = monMoves.front();
            monMoves.pop();
            for(ii move : moves){
                ii newPos = { mon.first+move.first, mon.second+move.second };

                if(!inGrid(newPos,n,m)) continue;
                
                char cell = grid[newPos.first][newPos.second];
                if(cell == 'N'){ 
                    grid[newPos.first][newPos.second] = 'X';
                    monMoves.push(newPos);
                }
            }
        }

        // I move after
        for(int i = 0; i < n_mine; i++){
            ii me = myMoves.front();
            myMoves.pop();

            // Reached border?
            if(onBorder(me,n,m)){
                cout << "YES" << endl;

                // Backtrack the path taken
                stack<char> backPath;
                while(grid[me.first][me.second] != 'S'){
                    char dir = grid[me.first][me.second];
                    ii move = moves[dirToMove[dir]];
                    me.first -= move.first;
                    me.second -= move.second;
                    backPath.push(dir);
                }
                cout << backPath.size() << endl;
                
                // Print the path in order
                while(!backPath.empty()){
                    cout << backPath.top();
                    backPath.pop();
                }
                return;
            }

            for(int j = 0; j < 4; j++){
                ii move = moves[j];
                ii newPos = { me.first+move.first, me.second+move.second };

                if(!inGrid(newPos,n,m)) continue;
                
                char cell = grid[newPos.first][newPos.second];
                if(cell == 'N'){ 
                    grid[newPos.first][newPos.second] = dirs[j];
                    myMoves.push(newPos);
                }
            }
        }
    }

    cout << "NO" << endl;
}
 
int main() {
    fastIo();
    solve();
}