#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

const int N = 500 + 10;
int vis[N][N][2];

// UDLR
int dr[] = {-1, +1, 0, 0};
int dc[] = {0, 0, -1, +1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];
    memset(vis, 0, sizeof(vis));

    int rs, cs, rg, cg;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'S') rs = i, cs = j;
            if(grid[i][j] == 'G') rg = i, cg = j;
        }
    }

    vis[rs][cs][0] = 1;
    queue<tuple<int, int, int>> q; q.emplace(rs, cs, 0);
    while(sz(q)){
        auto [r, c, st] = q.front(); q.pop();
        if(r == rg && c == cg){ cout << vis[r][c][st] - 1 << "\n"; return 0; }
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(grid[nr][nc] == '#') continue;
            if(grid[r][c] == '?'){
                if(grid[nr][nc] == 'x' && st != 0) continue;
                if(grid[nr][nc] == 'o' && st != 1) continue;
                if(vis[nr][nc][st ^ 1]) continue;
                vis[nr][nc][st ^ 1] = vis[r][c][st] + 1;
                q.emplace(nr, nc, st ^ 1);
            }else{
                if(grid[nr][nc] == 'x' && st != 1) continue;
                if(grid[nr][nc] == 'o' && st != 0) continue;
                if(vis[nr][nc][st]) continue;
                vis[nr][nc][st] = vis[r][c][st] + 1;
                q.emplace(nr, nc, st);
            }

            
        }
    }
    cout << "-1\n";
}