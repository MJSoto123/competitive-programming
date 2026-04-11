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
const int MOD = 998244353;
int add(int a, int b){ return (a + b >= MOD ? a + b - MOD : a + b); }
int mul(ll a, ll b){ return (a * b) % MOD; }
vvi id;
vvi mulmat(vvi a, vvi b){
    int n = sz(a);
    vvi c(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            for(int j = 0; j < n; j++){
                c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return c;
}

vvi binpow(vvi a, ll exp){
    vvi res = id;
    while(exp){
        if(exp & 1) res = mulmat(res, a);
        a = mulmat(a, a);
        exp >>= 1;
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    ll k; cin >> k;

    id.assign(n, vi(n, 0));
    for(int i = 0; i < n; i++) id[i][i] = 1;

    vvi a(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }

    vvi b = binpow(a, k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << b[i][j] << " "; cout << "\n";
    }
}