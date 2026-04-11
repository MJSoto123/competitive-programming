#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
typedef vector<pll> vll;
typedef vector<pii> vii;

void solve(){
    int n, m; cin >> n >> m;
    map<int, ll> mp;
    rep(i, 0, n){
        int cnt, exp; cin >> cnt >> exp;
        mp[exp] += cnt; 
    }

    int n = sz(mp);
    vl a, b;
    for(auto [cnt, exp] : mp){
        a.emplace_back(cnt);
        b.emplace_back(exp);
    }
    
    ll need = 0, last = 0, ans = 0;
    rep(i, 0, n){
        if(need){
            ll d = last - exp;
            if(__builtin_)
        }else{

        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}