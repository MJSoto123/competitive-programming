#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

ll lcm(ll a, ll b){
    return (a / __gcd(a, b)) * b;
}

void solve(){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll pa = d / a;
    ll pb = d / b;
    ll pc = d / c;
    ll pab = d / lcm(a, b);
    ll pac = d / lcm(a, c);
    ll pbc = d / lcm(b, c);
    ll pabc = d / lcm(a, lcm(b, c));

    pab -= pabc;
    pac -= pabc;
    pbc -= pabc;

    pa -= (pab + pabc + pac);
    pb -= (pab + pabc + pbc);
    pc -= (pbc + pabc + pac);

    ll ansa = 6 * pa + 3 * (pab + pac) + 2 * (pabc);
    ll ansb = 6 * pb + 3 * (pab + pbc) + 2 * (pabc);
    ll ansc = 6 * pc + 3 * (pbc + pac) + 2 * (pabc);

    cout << ansa << " " << ansb << " " << ansc << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}