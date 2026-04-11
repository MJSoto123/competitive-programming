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
typedef array<array<int, 101>, 101> M;
const int MOD = 1e9 + 7;
int add(int a, int b){ return (a + b) % MOD; }
int mul(ll a, ll b){ return (a * b) % MOD; }
void reset(M &a){ rep(i, 0, 101) rep(j, 0, 101) a[i][j] = 0; }
M id;
M matmul(M &a, M &b){
    int n = a.size();
    M c; reset(c);
    rep(i, 0, n) rep(k, 0, n) rep(j, 0, n) c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
    return c;
}

M binpow(M a, int exp){
    M res = id;
    while(exp){
        if(exp & 1) res = matmul(res, a);
        a = matmul(a, a);
        exp >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    reset(id);
    rep(i, 0, 101) id[i][i] = 1;

    int n, m; cin >> n >> m;
    M ini; reset(ini);
    rep(i, 1, m + 1) rep(j, 1, m + 1) if(__gcd(i, j) == 1) ini[i][j] = 1;

    M res = binpow(ini, n - 1);
    ll ans = 0;
    rep(i, 1, m + 1) rep(j, 1, m + 1) ans = add(ans, res[i][j]);

    cout << ans << "\n";
}