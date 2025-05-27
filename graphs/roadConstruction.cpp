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

class DisjointSet {

    private:
        int components;
        int largestSize = 1;
        vector<int> parents;
        vector<int> sizes;

    public:
        DisjointSet(int n) : parents(n + 1), sizes(n + 1, 1){
            // All elements are initially disjoint as "n" components
            for(int i = 1; i <= n; i++) parents[i] = i; 
            components = n;
        }

        int find(int x){
            return parents[x] == x ? x : parents[x] = find(parents[x]);
        }

        bool unite(int x, int y){
            int p1 = find(x);
            int p2 = find(y);

            if(p1 == p2) return false; // Same component

            components--; // Two components merge into one

            if(sizes[p1] < sizes[p2]) swap(p1,p2);

            sizes[p1] += sizes[p2];
            largestSize = max(largestSize, sizes[p1]);
            parents[p2] = p1;

            return true;
        }

        int getNumOfComponents(){
            return components;
        }

        int getLargestSize(){
            return largestSize;
        }
};

void solve() {

    int n, m;
    cin >> n >> m;

    DisjointSet dsu(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        dsu.unite(a,b);

        cout << dsu.getNumOfComponents() << " " << dsu.getLargestSize() << endl;
    }
    
}

int main() {
    fastIo();
    int t = 1;
    for(int i = 0; i < t; i++) solve();
}