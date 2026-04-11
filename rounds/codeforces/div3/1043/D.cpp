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

ll get(ll n){
    ll ans = 0;
    for(ll i = 1; i <= n; i *= 10) ans += (n - i + 1);
    return ans;
}

ll sm(ll n){
    if(n == 0) return 0;
    ll pot = 1;
    ll exp = 0;
    while(pot * 10 <= n){ 
        pot *= 10; exp++;
    }

    ll a = n / pot; 
    ll b = n % pot;
    return a * 45 * exp * (pot / 10) + a * (a - 1) / 2 * pot + a * (b + 1) + sm(b);
}

vi dig(ll n){
    vi d;
    while(n){
        d.emplace_back(n % 10);
        n /= 10;
    }
    reverse(all(d));
    return d;
}

void solve(){
    ll n; cin >> n; 
    n++;  
    ll l = 0, r = 1e15;
    while(r - l > 1){
        ll mid = l + r >> 1;
        if(get(mid) >= n) r = mid;
        else l = mid;
    }
    ll need = n - 1 - get(r - 1);
    ll ans = sm(r - 1);

    vi d = dig(r);
    for(int i = 0; i < need; i++) ans += d[i];

    cout << ans << "\n";
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}