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

int mod, tt;
int mul(ll a, ll b){ return (a * b) % mod; }
int binpow(ll a, int exp){
    ll res = 1;
    while(exp){
        if(exp & 1) res = mul(res, a);
        a = mul(a, a);
        exp >>= 1;
    }
    return res;
}

void solve(){
    vi fa;
    int p = mod - 1;
    for(int i = 2; i * i <= p; i++){
        int exp = 0;
        while(p % i == 0) p /= i, exp++;
        if(exp) fa.emplace_back(i);
    }
    if(p != 1) fa.emplace_back(p);

    for(int t = 0; t < tt; t++){
        int n; cin >> n;
        bool ok = true;
        for(auto d : fa){
            if(binpow(n, (mod - 1) / d) == 1){ ok = false; break; }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> mod >> tt){
        if(mod == 0 && tt == 0) return 0;
        solve();
    }
}