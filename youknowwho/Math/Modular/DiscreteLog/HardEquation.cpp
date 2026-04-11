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

int mod;
int add(int a, int b){ return (a + b >= mod ? a + b - mod : a + b); }
int mul(ll a, ll b){ return (a * b) % mod; }
int binpow(ll a, ll exp){
    ll res = 1;
    while(exp){
        if(exp & 1) res = mul(res, a);
        a = mul(a, a);
        exp >>= 1;
    }
    return res;
}

void solve(){
    int a, b; cin >> a >> b >> mod;
    a %= mod, b %= mod;

    int remain = 1, exp = 0;
    int g = gcd(a, mod);
    while(g != 1){
        if(b == remain){ cout << exp << "\n"; return; }
        if(b % g){ cout << "-1\n"; return; }
        b /= g, mod /= g;
        remain = mul(remain, (a / g));
        g = gcd(a, mod);
        exp++;
    }
        
    int n = sqrt(mod) + 1;
    vii baby;
    int pot = b;
    for(int i = 0; i < n; i++){
        baby.emplace_back(pot, i);
        pot = mul(pot, a);
    }
    sort(all(baby));
    
    pot = binpow(a, n);
    int giant = remain;
    for(int i = 1; i <= n; i++){
        giant = mul(giant, pot);
        int l = -1, r = sz(baby);
        while(r - l > 1){
            int mid = l + r >> 1;
            if(baby[mid].first <= giant) l = mid;
            else r = mid;
        }
        if(l == -1 || baby[l].first != giant) continue;
        cout << 1LL * i * n - baby[l].second + exp << "\n";
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}