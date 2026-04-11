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

vl pot(20);
void solve(){
    ll x; cin >> x;
    
    rep(i, 1, 10){
        ll y = pot[i] - 1 - x;
        string s = to_string(y);
        ll n = x * pot[sz(s)] + y;
        if(y <= 0) continue;
        if(n % (x + y) == 0){ cout << y << "\n"; return; }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll p = 1;
    rep(i, 0, 11) pot[i] = p, p *= 10;

    int tt; cin >> tt;
    while(tt--) solve();
}