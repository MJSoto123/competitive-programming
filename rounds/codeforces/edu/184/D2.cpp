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
        // cerr << "\ntry " << x << "\n";
        ll it2 = it;

        int t = 0;
        while(it2 > 0){
            ll here = x / d;
            if(here == 0) return x; // xd
            
            ll times = (x - here * d) / here + 1;
            times = max(times, 1LL);
            // cerr << "it2, here, times " << x << " "<<  it2 << " " << here << " " << times << "\n";

            if(times <= it2){
                x -= times * here;
                it2 -= times;
            }else{
                // no puedo todo
                x -= it2 * here;
                it2 = 0;
            }
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