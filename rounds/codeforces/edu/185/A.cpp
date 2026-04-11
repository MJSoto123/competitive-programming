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
vi dr = {-1, +1, 0, 0};
vi dc = {0, 0, -1, +1};
void solve(){
    int n; cin >> n;
    vvi a(n, vi(n));

    rep(i, 0, n){
        rep(j, 0, n) a[i][j] = i * n + j + 1;
    }

    auto f = [&](int r, int c){
        int ans = a[r][c];
        rep(i, 0, 4){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            ans += a[nr][nc];
        }
        return ans;
    };

    int ans = 0;
    rep(i, 0, n){
        rep(j, 0, n) ans = max(ans, f(i, j));
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}