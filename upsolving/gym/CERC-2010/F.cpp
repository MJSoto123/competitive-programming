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

const int MOD = 1e9 + 7;
int add(int a, int b){ return a + b >= MOD ? a + b - MOD : a + b; }
int mul(ll a, ll b){ return (a * b) % MOD; }
int binpow(int a, ll res){
    int res = 1;
    while(exp){
        if(exp & 1) res = mul(res, a);
        a = mul(a, a);
        exp >>= 1;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    vii p(n);
    rep(i, 0, n) cin >> p[i].first >> p[i].second;

    int xmax = int(-1e9 - 100), ymax = int(-1e9 - 100), xmin = 1e9 + 100, ymin = 1e9 + 100;
    int smmax = int(-2e9 - 100), smmin = int(2e9 + 100), difmax = int(-2e9 - 100), difmin = int(2e9 + 100);

    for(auto [x, y] : p){
        xmax = max(xmax, x);
        xmin = min(xmin, x);
        ymax = max(ymax, y);
        ymin = min(ymin, y);

        smmax = max(smmax, x + y);
        smmin = min(smmin, x + y);
        difmax = max(difmax, x - y);
        difmin = min(difmin, x - y);
    }

    ll dx = xmax - xmin, dy = ymax - ymin;
    ll tot = dx * dy;

    int ans = 1;
    {
        // (xmin, smmin - ymin)
        // (smmin - ymin, ymin)
        int len = abs(xmin - smmin - ymin) + 1;
        tot -= (len - 1) * len / 2; 
        
    }


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}