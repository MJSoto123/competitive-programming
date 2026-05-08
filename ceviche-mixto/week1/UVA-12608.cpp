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

void solve(){
    int tot, n; cin >> tot >> n;
    vi x(n), w(n);
    rep(i, 0, n) cin >> x[i] >> w[i];

    ll ans = 0;
    int sm = 0;
    rep(i, 0, n){
        sm += w[i];
        if(sm == tot){
            ans += x[i] * 2;
            sm = 0;
            continue;
        }else if(sm > tot){
            ans += x[i] * 2;
            sm = 0;
            i--;
            continue;
        }
        if(i == n - 1) ans += 2 * x[i];
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}