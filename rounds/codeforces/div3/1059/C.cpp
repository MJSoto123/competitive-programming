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
    ll a, b; cin >> a >> b;
    ll need = a ^ b;

    vl ans;
    rep(i, 0, 32){
        if(need & (1LL << i)) ans.emplace_back(1LL << i);
    }

    if(a == b || sz(ans) == 0){ cout << "0\n"; return; }
    ll mx = *max_element(all(ans));
    if(mx > a){ cout << "-1\n"; return; }
    cout << sz(ans) << "\n";
    rep(i, 0, sz(ans)) cout << ans[i] << " "; cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}