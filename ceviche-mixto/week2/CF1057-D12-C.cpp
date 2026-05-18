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

const int MX = 2600 + 10;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, start, k; cin >> n >> start >> k;
    start--;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    string s; cin >> s;

    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int l, int r){ return a[l] < a[r]; });

    vvi dp(n, vi(MX, -1));
    for(int i = n - 1; i >= 0; i--){
        int from = ord[i];
        rep(j, i + 1, n){
            int to = ord[j];
            rep(tot, 0, MX){
                if(s[from] == s[to] || a[from] >= a[to]) continue;
                if(dp[to][tot] == -1) continue;
                auto &ndp = dp[from][tot + a[from]];
                int dist = abs(from - to);
                if(ndp == -1) ndp = dp[to][tot] + dist; 
                else ndp = min(ndp, dp[to][tot] + dist);
            }
        }
        dp[from][a[from]] = 0;
        // print
        // rep(w, 0, n){
        //     int from = ord[w];
        //     rep(sm, 0, MX) if(dp[from][sm] != -1){
        //         cerr << "using " << a[from] << " " << sm << " => " << dp[from][sm] << "\n"; 
        //     }
        // }
        // cerr << "\n";
    }

    int ans = (1 << 29);
    rep(i, 0, n){
        int from = ord[i];
        rep(tot, k, MX){
            if(dp[from][tot] == -1) continue;
            ans = min(ans, dp[from][tot] + abs(start - from));
        }
    }
    cout << (ans == (1 << 29) ? -1 : ans) << "\n";
}