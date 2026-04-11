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

int get(int x){
    int ret = 0;
    for(int i = 0; i < 20; i++){
        if(x & (1 << i)) ret++;
        else return ret;
    }
    return ret;
}

void solve(){
    int n; cin >> n;
    n = (1 << n);
    vii a(n);
    rep(i, 0, n) a[i] = {get(i), i};

    sort(all(a), [&](pii i, pii j){
        auto [bits1, val1] = i;
        auto [bits2, val2] = j;
        if(bits1 == bits2) return val1 < val2;
        return bits1 > bits2;
    });

    for(auto [b, v] : a) cout << v << " "; cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}