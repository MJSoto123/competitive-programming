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

inline int add(int a, int b, const int &mod) { return a+b >= mod ? a+b-mod : a+b; }
inline int sbt(int a, int b, const int &mod) { return a-b < 0 ? a-b+mod : a-b; }
inline int mul(int a, int b, const int &mod) { return 1ll*a*b % mod; }

const int X[] = {257, 359}; // 31 43
const int MOD[] = {(int)1e9+7, (int)1e9+9};
const int N = 2e6 + 10;
int pows[N][2], ipows[N][2];
int h[2];

int binpow(int a, int exp, const int &mod) {
    int res = 1; 
    while(exp > 0) {
        if(exp % 2) res = mul(res, a, mod);
        a = mul(a, a, mod);
        exp >>= 1; 
    }
    return res; 
}

struct Hashing {
    string s;
    int n; 
    vvi ph; 

    Hashing(){ }
    Hashing(string &s) : s(s) { 
        n = s.size(); 
        ph.assign(n, vi(2));    
    }

    void build() {     
        for(int j = 0; j < 2; j++) {
            ph[0][j] = s[0];
            for(int i = 1; i < n; i++) {
                ph[i][j] = add(ph[i - 1][j], mul(pows[i][j], s[i], MOD[j]), MOD[j]);
            }
        }
    }

    pii substr_hash(int l, int r) {
        r--;
        if(l == 0) return make_pair(ph[r][0], ph[r][1]);
        h[0] = mul(sbt(ph[r][0], ph[l - 1][0], MOD[0]), ipows[l][0], MOD[0]);
        h[1] = mul(sbt(ph[r][1], ph[l - 1][1], MOD[1]), ipows[l][1], MOD[1]);
        return make_pair(h[0], h[1]);
    }
};

void init() {
    for(int j = 0; j < 2; j++) {
        pows[0][j] = 1; 
        for(int i = 1; i < N; i++) pows[i][j] = mul(pows[i - 1][j], X[j], MOD[j]);
        ipows[N - 1][j] = binpow(pows[N - 1][j], MOD[j] - 2, MOD[j]);
        for(int i = N - 1; i > 0; i--) ipows[i - 1][j] = mul(ipows[i][j], X[j], MOD[j]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int n; cin >> n;
    vector<string> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<Hashing> hs(n);
    rep(i, 0, n){
        hs[i] = Hashing(a[i]); hs[i].build();
    }

    string s; cin >> s;
    Hashing ss(s); ss.build();
    int m = sz(s);
    pii need = ss.substr_hash(0, m);

    vi dp(m + 1);
    dp[0] = 1;

    // in
    rep(i, 0, n){
        rep(j, 0, sz(a[i]) - m + 1){
            pii now  = hs[i].substr_hash(j, j + m);
            if(need == now) dp[m] = 1;
        }
    }

    // pre
    rep(len, 1, m + 1){
        need = ss.substr_hash(0, len);
        rep(i, 0, n){
            pii now = hs[i].substr_hash(max(0, sz(a[i]) - len), sz(a[i]));
            if(need == now) dp[len] = 1;
        }
    }

    // have
    set<pii> have;
    rep(i, 0, n) have.insert(hs[i].substr_hash(0, sz(a[i])));
    rep(l, 0, m){
        if(!dp[l]) continue;
        for(int len = 1; len + l <= m; len++){
            need = ss.substr_hash(l, l + len);
            if(have.count(need)) dp[l + len] = 1;
        }
    }
    
    // suf
    rep(l, 0, m){
        if(!dp[l]) continue;
        need = ss.substr_hash(l, m);
        rep(i, 0, n){
            pii now = hs[i].substr_hash(0, min(sz(a[i]), m - l));
            if(need == now) dp[m] = 1;
        }
    }

    if(dp[m]) cout << "YES\n";
    else cout << "NO\n";
}