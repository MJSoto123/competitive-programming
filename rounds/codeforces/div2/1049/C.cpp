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
    int n; cin >> n;
    vl a(n);
    rep(i, 0, n) cin >> a[i];

    ll sm = 0;
    rep(i, 0, n){
        if(i % 2 == 0) sm += a[i];
        else sm -= a[i];
    }

    ll ans = sm;
    ll mx = -1000'000'000'000'000'000;
    // 1 0
    rep(i, 0, n){
        if(i % 2 == 0) ans = max(ans, sm + (-2 * a[i] + i) + mx);
        else mx = max(mx, 2 * a[i] - i);
    }

    mx = -1000'000'000'000'000'000;
    // 0 1
    rep(i, 0, n){
        if(i % 2 == 1) ans = max(ans, sm + (2 * a[i] + i) + mx);
        else mx = max(mx, -2 * a[i] - i);
    }

    // iguales par
    map<int, pii> mp1;
    rep(i, 0, n){
        if(i % 2 == 0) continue;
        if(!mp1.count(a[i])) mp1[a[i]] = {i, i};
        else mp1[a[i]].second = i;
    }

    for(auto [val, p] : mp1){
        auto [fs, ls] = p;
        ans = max(ans, sm + ls - fs);
    }

    // iguales impar
    map<int, pii> mp2;
    rep(i, 0, n){
        if(i % 2 == 1) continue;
        if(!mp2.count(a[i])) mp2[a[i]] = {i, i};
        else mp2[a[i]].second = i;
    }

    for(auto [val, p] : mp2){
        auto [fs, ls] = p;
        ans = max(ans, sm + ls - fs);
    }
    
    // misma clase
    if(n % 2 == 0) ans = max(ans, sm + n - 2);
    else ans = max(ans, sm + n - 1);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}