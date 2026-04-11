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

vl cost(21);
vl get(int n){
    vl dig;
    while(n){
        dig.emplace_back(n % 3);
        n /= 3;
    }
    return dig;
}


void solve(){
    ll n, k; cin >> n >> k;
    vl d = get(n);
    
    int ones = accumulate(all(d), 0LL);
    if(ones > k){ cout << "-1\n"; return; }

    for(int i = sz(d) - 1; i >= 1; i--){
        ll sobra = (k - ones) / 2;
        ll to = min(sobra, d[i]);
        ones += to * 2;
        d[i - 1] += to * 3;
        d[i] -= to;
    }

    ll best = 0;
    for(int i = 0; i < sz(d); i++) best += d[i] * cost[i];
    cout << best << "\n";
}

void init(){
    ll pot1 = 3;
    cost[0] = 3;
    for(int i = 1; i < 20; i++){
        cost[i] = pot1 * 3 + i * (pot1 / 3);
        pot1 *= 3;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    int tt; cin >> tt;
    while(tt--) solve();
}