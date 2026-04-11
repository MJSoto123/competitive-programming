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
int MOD = 998244352;
int add(int a, int b){ return (a + b >= MOD ? a + b - MOD : a + b); }
int mul(ll a, ll b){ return (a * b) % MOD; }
vvi matmul(vvi &a, vvi &b){
    int n = sz(a);
    vvi c(n, vi (n));
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            for(int j = 0; j < n; j++){
                c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return c;
}
vvi id;
vvi binpow(vvi a, ll exp){
    vvi res = id;
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

    int k; cin >> k;
    id.assign(k, vi(k));
    for(int i = 0; i < k; i++) id[i][i] = 1;

    vvi a(k, vi (k));
    for(int i = 0; i < k - 1; i++) a[i][i + 1] = 1;
    for(int i = 0; i < k; i++) cin >> a[k - 1][i];

    int exp, res; cin >> exp >> res;
    exp -= (k - 2);
    vvi b = binpow(a, exp);
    int pot = b[0][k - 1];
    cout << pot << "\n";

    // (x ^ pot) % MOD = m
    
}