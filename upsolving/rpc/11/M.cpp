#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
using ld = long double;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

const int N = 105;
ld dp[N][N][N];
vl c(3), f(3);
ll l, r;

ld go(vl a){
    if(dp[a[0]][a[1]][a[2]] != -1) return dp[a[0]][a[1]][a[2]];
    int tot = accumulate(all(a), 0);
    if(tot == 0) return 0;

    ll sm = 0;
    rep(i, 0, 3) sm += (f[i] - a[i]) * c[i];
    if(sm > r) return 0;

    ld ret = 0;
    rep(i, 0, 3){
        if(a[i] == 0) continue;
        ld p = (ld) a[i] / (ld) tot;
        if(sm + c[i] >= l){
            if(sm + c[i] <= r) ret += p;
        }else{
            vl b = a; b[i]--;
            ret += p * go(b);
        }
    }
    return dp[a[0]][a[1]][a[2]] = ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(7);

    // memset(dp, -1, sizeof(dp)); xd
    rep(i, 0, N) rep(j, 0, N) rep(k, 0, N) dp[i][j][k] = -1;

    cin >> l >> r;
    rep(i, 0, 3) cin >> c[i];
    rep(i, 0, 3) cin >> f[i];
    cout << go(f) << "\n";
}