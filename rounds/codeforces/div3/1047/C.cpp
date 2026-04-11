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
    ll ans = -1;
    if(b % 2 && a % 2) ans = max(ans, a * b + 1);
    if(b % 2 == 0){
        ll v1 = (a * b / 2) + 2;
        if(v1 % 2 == 0) ans = max(ans, v1);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}