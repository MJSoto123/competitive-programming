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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vl a(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 1, n) a[i] = min(2 * a[i - 1], a[i]);

    ll best = 5e18;
    ll ans = 0;
    for(int bit = n - 1; bit >= 0; bit--){
        ll cnt = m / (1 << bit);
        best = min(best, ans + (cnt + 1) * a[bit]);
        ans += cnt * a[bit];
        m -= cnt * (1 << bit);
    }
    best = min(best, ans);
    cout << best << "\n";
}