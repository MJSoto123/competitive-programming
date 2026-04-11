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
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int mx = 0;
    rep(i, 0, n){
        mx = max(mx, a[i]);
        if(i % 2) a[i] = mx;
    }

    ll ans = 0;
    if(a[0] == a[1]) ans++;
    rep(i, 1, n){
        if(i % 2 == 0){
            if(a[i] < a[i - 1]) continue;
            ans += (a[i] - a[i - 1] + 1);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}