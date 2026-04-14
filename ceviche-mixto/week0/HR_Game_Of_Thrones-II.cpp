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


const int MOD = 1e9 + 7;
int add(int a, int b){ return (a + b >= MOD ? a + b - MOD: a + b); }
int mul(ll a, ll b){ return (a * b) % MOD; }

int binpow(int a, int exp){
    int res = 1;
    while(exp){
        if(exp & 1) res = mul(res, a);
        a = mul(a, a);
        exp >>= 1;
    }
    return res;
}

int inv(int a){ return binpow(a, MOD - 2); }

const int N = 2e5 + 10;
vi fact(N, 1);
void init(){
    rep(i, 1, N) fact[i] = mul(fact[i - 1], i);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();

    string s; cin >> s;
    int n = sz(s);

    map<char, int> mp;
    for(auto c : s) mp[c]++;

    int tot = 0;
    int deno = 1;
    for(auto [c, cnt] : mp){
        tot += (cnt / 2);
        deno = mul(deno, fact[cnt / 2]);
    }

    cout << mul(fact[tot], inv(deno)) << "\n";
}