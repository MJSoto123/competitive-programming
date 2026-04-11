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
M id, f;
void init(M &a){
    for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) a[i][j] = 0;
}
int m;
int add(int a, int b){ return (a + b >= m ? a + b - m : a + b); }
int mul(ll a, ll b){ return (a * b) % m; }
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
    init(f); init(id);
    f[0][1] = 1;
    f[1][0] = 1;
    f[1][1] = 1;

    id[0][0] = id[1][1] = 1;

    int n, exp;
    while(cin >> n){
        cin >> exp;
        m = 1;
        for(int i = 0; i < exp; i++) m *= 2;
        cout << binpow(f, n)[0][1] << "\n";
    }
}   