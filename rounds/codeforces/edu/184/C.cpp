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

void solve(){
    int n; cin >> n;
    vl a(n);
    rep(i, 0, n) cin >> a[i];

    vl pre = a;
    rep(i, 1, n) pre[i] = pre[i - 1] + a[i];

    ll ans = pre[n - 1];
    ll best = 0;
    ll tot = pre[n - 1];

    rep(i, 0, n){
        ll l = i + 1;
        ll here = -l * l + l + pre[i] - a[i];
        best = max(best, here);

        ll r = i + 1;
        ll now = r * r + r - pre[i];
        ans = max(ans, tot + best + now);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}