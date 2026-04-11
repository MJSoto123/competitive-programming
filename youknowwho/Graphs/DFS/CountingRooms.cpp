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
vi dr = {-1, +1, 0 , 0};
vi dc = {0 , 0, -1, +1};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> a(n);
    rep(i, 0, n) cin >> a[i];
    vvi vis(n, vi(m));
    
    function<void(int, int)> go = [&](int r, int c){
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr >= n || nr < 0 || nc >= m || nc < 0) continue;
            if(vis[nr][nc] || a[nr][nc] == '#') continue;
            vis[nr][nc] = 1;
            go(nr, nc);
        }
    };

    int ans = 0;
    rep(i, 0, n){
        rep(j, 0, m){
            if(vis[i][j] || a[i][j] == '#') continue;
            go(i, j);
            ans++;
        }
    }

    cout << ans << '\n';
}