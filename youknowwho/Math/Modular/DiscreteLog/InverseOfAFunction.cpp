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
const int MOD = 998244353;
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
    int y;
    string s; cin >> s >> y >> mod;
    int x = 1;
    for(int i = 0; i < sz(s); i++){
        x = binpow(x, 10);
        x = mul(x, binpow(2, s[i] - '0'));
    }
    x = add(mod - 1, x);
    y %= mod;

    // x ^ bits = y % mod
    int remain = 1, exp = 0;
    int g = __gcd(x, mod);
    int bits = -1;
    while(g != 1){
        if(y == remain){ bits = exp; break; }
        if(y % g){ cout << "-1\n"; return; }
        y /= g; mod /= g;
        remain = mul(remain, x / g);
        exp++;
        g = __gcd(x, mod);
    }

    if(bits == -1){
        int nn = sqrt(mod) + 1;
        vii baby;
        int pot = y;
        for(int i = 0; i < nn; i++){
            baby.emplace_back(pot, i);
            pot = mul(pot, x);
        }
        sort(all(baby));
        pot = binpow(x, nn);
        int giant = remain;
        for(int i = 1; i <= nn; i++){
            giant = mul(giant, pot);
            int l = -1, r = sz(baby);
            while(r - l > 1){
                int mid = l + r >> 1;
                if(baby[mid].first <= giant) l = mid;
                else r = mid;
            }
            if(l == -1 || baby[l].first != giant) continue;
            bits = 1LL * nn * i - baby[l].second + exp;
            break;
        }
    }
    if(bits == -1){ cout << "-1\n"; return; }
    mod = MOD;
    int ret = binpow(2, bits);
    ret = add(ret, MOD - 1);
    
    x = 1;
    for(int i = 0; i < sz(s); i++){
        x = binpow(x, 10);
        x = mul(x, binpow(2, s[i] - '0'));
    }
    x = mul(x, binpow(2, MOD - 2));

    ret = mul(ret, x);
    cout << ret << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}