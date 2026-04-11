#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

void solve(){
    int n; cin >> n;
    vvi a(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    
    vi row(n), col(n);
    for(int i = 0; i < n; i++) cin >> row[i];
    for(int i = 0; i < n; i++) cin >> col[i];
    
    auto check = [&](int c, int prev, int now){
        bool ok = true;
        for(int r = 0; r < n; r++){
            if(a[r][c - 1] + prev == a[r][c] + now) return false;
        }
        return true;
    };

    function<ll()> go = [&](){
        ll ndp = 0, dp = col[0];
        for(int c = 1; c < n; c++){
            ll nbest = 1e15 + 100, best = 1e15 + 100;
            // asdasd
            if(check(c, 0, 0)) nbest = min(nbest, ndp);
            if(check(c, 1, 0)) nbest = min(nbest, dp);
            if(check(c, 0, 1)) best = min(best, ndp + col[c]);
            if(check(c, 1, 1)) best = min(best, dp + col[c]);
            ndp = nbest;
            dp = best;
        }
        return min(ndp, dp);
    };
    
    ll ans = go();
    vvi b = a;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) b[j][i] = a[i][j];
    }
    a = b;
    col = row;

    ans += go();
    if(ans >= 1e15 + 100) cout << "-1\n";
    else cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}