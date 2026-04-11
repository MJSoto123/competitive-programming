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

const ll tot = 1000'000'000'000;
void solve(){
    ll it, d, k; cin >> it >> d >> k;

    auto get = [&](ll x){
        rep(i, 0, it){
            ll here = x / d;
            x -= here;
        }
        return max(0LL, x);
    };

    ll l = -1, r = tot + 1;
    ll ans = -1;
    while(r - l > 1){
        ll mid = (l + r) / 2;
        if(get(mid) >= k){
            r = mid;
            ans = mid;
        }
        else l = mid;
    }

    cout << ans << "\n";    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}