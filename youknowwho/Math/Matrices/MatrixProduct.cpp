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

int n, m, p;
const int N  = 1100;
const int MOD = 998244353;
int A[N][N], B[N][N], C[N][N];
int add(int a, int b){ return (a + b >= MOD ? a + b - MOD : a + b); }
int mul(ll a, ll b){ return (a * b) % MOD; }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p;
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> A[i][j];
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++) cin >> B[i][j];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
                for(int k = 0; k < m; k++){
                C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));
            }
        }
    }

    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < p; j++) cout << C[i][j] << " "; cout << "\n";
    }
}