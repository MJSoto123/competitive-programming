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
    ll n, k; cin >> n >> k;
    vl q(n), r(n);
    rep(i, 0, n) cin >> q[i];
    rep(i, 0, n) cin >> r[i];

    sort(all(q));
    reverse(all(q));
    
    sort(all(r));
    int ans = 0;
    int idx = 0;

    rep(i, 0, n){
        ll mn = q[i] * (r[idx] + 1) + r[idx];
        if(mn >= 1 && mn <= k){
            ans++;
            idx++;
            if(idx == n) break;
            continue;
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