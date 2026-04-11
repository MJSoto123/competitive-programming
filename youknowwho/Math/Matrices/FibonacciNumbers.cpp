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
typedef array<array<int, 2>, 2> M;
M id;
M f;
void init(M &a){ a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0; }
const int MOD = 1e9 + 7;
int add(int a, int b){ return (a + b >= MOD ? a + b - MOD : a + b); }
int mul(ll a, ll b){ return (a * b) % MOD; }
M matmul(M &a, M &b){
    M c; init(c);
    for(int i = 0; i < 2; i++){
        for(int k = 0; k < 2; k++){
            for(int j = 0; j < 2; j++){
                c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return c;
}

M binpow(M a, ll exp){
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
     
    ll n; cin >> n;
    f[0][1] = 1;
    f[1][0] = 1;
    f[1][1] = 1;

    id[0][0] = 1;
    id[1][1] = 1;
    cout << binpow(f, n)[0][1] << "\n";
}