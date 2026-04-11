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

    int n, m, k; cin >> n >> m >> k;
    vector<string> a(n);
    rep(i, 0, n) cin >> a[i];

    auto check = [&](int r, int c){
        return (r >= 0 && r < n && c >= 0 && c < m);
    };

    int rs = -1, cs = -1;
    rep(i, 0, n) rep(j, 0, m) if(a[i][j] == '.'){ rs = i, cs = j; }

    int cnt = 0;
    vvi vis(n, vi(m));
    vis[rs][cs] = 1;
    queue<pii> q; q.emplace(rs, cs);

    while(sz(q) && cnt < k){
        auto [r, c] = q.front(); q.pop();
        a[r][c] = 'X';
        cnt++;
        rep(i, 0, 4){
            int nr = r + dr[i], nc = c + dc[i];
            if(check(nr, nc) && a[nr][nc] == '.' && !vis[nr][nc]){
                vis[nr][nc] = 1;
                q.emplace(nr, nc);
            }
        }
    }

    rep(i, 0, n) cout << a[i] << "\n";
}