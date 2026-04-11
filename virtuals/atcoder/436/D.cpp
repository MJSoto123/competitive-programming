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

//  U D L R
vi dr = {-1, +1, 0, 0};
vi dc = {0, 0, -1, +1};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vii> tele(30);
    rep(r, 0, n) rep(c, 0, m) tele[a[r][c] - 'a'].emplace_back(r, c);

    queue<tuple<int, int, int>> q;
    vi vis(n * m);
    q.emplace(0, 0, 0);
    vis[0][0] = 1;

    while(sz(q)){
        auto [r, c, dis] = q.top(); q.pop();
        if(r == n - 1 && c == m - 1){ cout << dis << "\n"; return; }
        if(a[nr])
        rep(i, 0, 4){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if(a[nr][nc] == '#') continue;
            
            q.emplace_back(nr, nc, dis + 1);
            vis[nr][nc] = 1;

            if(a[nr][nc] == '.') continue;
            int ch = a[nr][nc] - 'a';
            for(auto [ri, ci] : tele[ch]){
                if(ri == nr && ci == nc) continue;
                q.emplace_back(ri, ci, dis + 2);
                vis[ri][ci] 
            }
        }
    }
    cout << "-1\n";
}