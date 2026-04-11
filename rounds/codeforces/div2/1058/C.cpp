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

vi get(ll a){
    vi d;
    while(a){
        d.emplace_back(a % 2);
        a >>= 1;
    }
    return d;
}

bool pal(const vi &a){
    int n = sz(a);
    if(n % 2 == 1 && a[n / 2] == 1) return false;
    rep(i, 0, n / 2) if(a[i] != a[n - 1 - i]) return false;
    return true;
}

void solve(){
    ll k; cin >> k;
    vi d = get(k);
    int n = sz(d);
    rep(i, 0, 32){
        if(pal(d)){ cout << "YES\n"; return; }
        d.emplace_back(0);
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}