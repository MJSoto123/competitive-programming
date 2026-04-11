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
    ll h, d; cin >> h >> d;

    auto f = [&](ll times){
        ll seg = d / (times + 1);
        ll need = (seg * (seg + 1) / 2) * (times + 1);
        ll extra = (seg + 1) * (d % (times + 1));
        return (need + extra < h + times);
    };

    int l = -1, r = d + 100;
    while(r - l > 1){
        int mid = l + (r - l) / 2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << d + r << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}