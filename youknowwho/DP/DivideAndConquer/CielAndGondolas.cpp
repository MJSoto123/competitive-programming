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

const int N = 4000 + 5;
const int K = 800 + 5;
const ll inf = 1e18;
ll pre[N][N];
short a[N][N];
ll dp[K][N];

ll cost(int i, int j){
    return pre[j][j] - pre[i - 1][j] - pre[j][i - 1] + pre[i - 1][i - 1];
}

void go(int k, int l, int r, int optl, int optr){
    if(l > r) return;
    
    int mid = l + r >> 1;
    int opt = -1;
    ll best = inf;

    for(int i = optl; i <= min(mid, optr); i++){
        ll here = dp[k - 1][i - 1] + cost(i, mid) / 2;
        if(here < best){
            best = here;
            opt = i;
        }
    }
    dp[k][mid] = best;

    go(k, l, mid - 1, optl, opt);
    go(k, mid + 1, r, opt, optr);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    rep(i, 1, n + 1) rep(j, 1, n + 1) cin >> a[i][j];
    rep(i, 1, n + 1) rep(j, 1, n + 1){
        pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + a[i][j];
    }

    rep(i, 0, k + 1) rep(j, 1, n + 1) dp[i][j] = inf;
    rep(i, 1, n + 1) dp[1][i] = cost(1, i) / 2;
    
    rep(i, 2, k + 1) go(i, 1, n, 1, n);
    cout << dp[k][n] << "\n";
}