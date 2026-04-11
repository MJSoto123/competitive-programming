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
    ll n; cin >> n;
    ll pot = 10;
    vl ans;
    for(int i = 0; i < 18; i++){
        if(n % (pot + 1) == 0) ans.emplace_back(n / (pot + 1));
        pot *= 10;
    }

    sort(all(ans));
    cout << sz(ans) << "\n";
    if(sz(ans) == 0) return;
    for(auto x : ans) cout << x << " "; cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}