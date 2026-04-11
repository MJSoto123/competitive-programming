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

const int INF = (1 << 25);
void trans(vvi &a){
    int n = sz(a), m = sz(a[0]);
    vvi b(m, vi(n));
    rep(i, 0, m) rep(j, 0, n) b[i][j] = a[j][i];
    a = b;
}

void solve(){
    int n, m; cin >> n >> m;
    vvi a(n, vi(m));
    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, m) a[i][j] = (s[j] == '1');
    }
    bool ori = true;
    if(n > m){ swap(n, m); trans(a); ori = false; }

    vector<vvi> dp(m, vvi(n, vi(n, INF)));
    rep(r1, 0, n) rep(r2, r1 + 1, n){
        int c1 = -1;
        rep(c2, 0, m){
            if(!a[r1][c2] || !a[r2][c2]) continue;
            if(c1 != -1){
                int area = (c2 - c1 + 1) * (r2 - r1 + 1);
                rep(c, c1, c2 + 1) dp[c][r1][r2] = min(dp[c][r1][r2], area);
            }
            c1 = c2;
        }
    }
    
    rep(c, 0, m) for(int len = n; len >= 2; len--) rep(r1, 0, n){
        int r2 = r1 + len - 1;
        if(r2 >= n) continue;
        int mid = (r1 + r2) / 2;
        dp[c][r1][mid] = min(dp[c][r1][mid], dp[c][r1][r2]);
        dp[c][mid + 1][r2] = min(dp[c][mid + 1][r2], dp[c][r1][r2]);
    }

    vvi ans(n, vi(m, INF));
    rep(i, 0, n) rep(j, 0, m) ans[i][j] = min(ans[i][j], dp[j][i][i]);
    if(!ori){ swap(n, m); trans(ans); }
    rep(i, 0, n) rep(j, 0, m) cout << (ans[i][j] == INF ? 0 : ans[i][j]) << " \n"[j == m - 1]; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}