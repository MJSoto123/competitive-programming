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

// U D L R
vi dr = {-1, +1, 0, 0};
vi dc = {0, 0, -1, +1};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> a(n);
    rep(i, 0, n) cin >> a[i];
    
    int sr, sc; cin >> sr >> sc; 
    sr--; sc--;

    int gr, gc; cin >> gr >> gc;;
    gr--; gc--;

    vvi vis(n, vi(m));
    function<bool(int, int)> dfs = [&](int r, int c){
        rep(i, 0, 4){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr == gr && nc == gc) return true;
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(vis[nr][nc] || a[nr][nc] == 'X') continue;
            vis[nr][nc] = 1;
            if(dfs(nr, nc)) return true;
        }
        return false;
    };
    
    vis[sr][sc] = 1;
    bool can = dfs(sr, sc);
    // cerr << can << " " << a[gr][gc] << "\n";

        
    bool alao = false;
    rep(i, 0, 4){
        int nr = sr + dr[i];
        int nc = sc + dc[i];
        if(nr == gr && nc == gc) alao = true;
    }

    if(!can){ cout << "NO\n"; return 0; }
    if(a[gr][gc] == 'X'){ cout << "YES\n"; return 0; }
    else{
        int cnt = 0;
        rep(i, 0, 4){
            int nr = gr + dr[i];
            int nc = gc + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(a[nr][nc] != 'X') cnt++;
        }
        if(cnt >= 2 || (alao && cnt >= 1)) cout << "YES\n";
        else cout << "NO\n";
    }
}