#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

// UDLR
vi dr = {-1, 1, 0, 0};
vi dc = {0, 0, -1, 1};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<string> a(n);
    rep(i, 0, n) cin >> a[i];
    vvi grid(n, vi(n));

    // -1 pared
    // 0 salida
    // 1 llegada
    int node = 2;
    rep(row, 0, n){
        string s = a[row];
        int cnt = 0;
        int col = 0;
        for(auto x : s){
            if(x == 'G'){
                rep(i, 0, cnt) grid[row][col + i] = node;
                node++;
                col += cnt;
                cnt = 0;
            }else if(x == 'R'){
                rep(i, 0, cnt) grid[row][col + i] = -1;
                col += cnt;
                cnt = 0;
            }else if(x == 'S'){
                rep(i, 0, cnt) grid[row][col + i] = 0;
                col += cnt;
                cnt = 0;
            }else if(x == 'D'){
                rep(i, 0, cnt) grid[row][col + i] = 1;
                col += cnt;
                cnt = 0;
            }else{
                cnt *= 10; 
                cnt += char(x - '0');
            }
        }
    }

    vvi graph(node + 1);
    rep(r, 0, n){
        rep(c, 0, n){
            if(grid[r][c] == -1) continue;
            rep(i, 0, 4){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if(grid[nr][nc] == -1 || grid[nr][nc] == grid[r][c]) continue;
                graph[grid[r][c]].emplace_back(grid[nr][nc]);
            }
        }
    }

    queue<tuple<int, int>> q;
    vi vis(node + 1);
    q.emplace(0, 0); vis[0] = 1;

    while(sz(q)){
        auto [d, u] = q.front(); q.pop();
        if(u == 1){ cout << d - 1 << "\n"; return 0; }
        for(auto v : graph[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            q.emplace(d + 1, v);
        }
    }
}