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

ll inf = 1e18;
void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    
    ll ansa = -a.back(), ansb = b.back();
    for(int i = n - 2; i >= 0; i--){
        ll na = max(ansa - a[i], ansb - b[i]);
        ll nb = max(ansa + b[i], ansb + a[i]);
        ansa = na;
        ansb = nb;
    }
    cout << max(ansa, ansb) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}