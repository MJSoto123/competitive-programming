#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;

const int N = 3000 + 5;
int a[N];
ll pre[N];
ll dp[N][N];
const ll inf = 1e18;

ll cost(int l, int r) {
    ll sm = pre[r + 1] - pre[l];
    return sm * sm;
}

void conquer(int k, int l, int r, int optl, int optr) {
    if (l > r) return;

    int mid = (l + r) >> 1;
    int opt = -1;
    ll best = inf;

    rep(i, optl, min(mid + 1, optr + 1)){
        if(i == 0) continue;
        ll here = dp[k - 1][i - 1] + cost(i, mid);
        if(here < best){
            best = here;
            opt = i;
        }
    }
    dp[k][mid] = best;

    conquer(k, l, mid - 1, optl, opt);
    conquer(k, mid + 1, r, opt, optr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) pre[i + 1] = pre[i] + a[i];


    rep(i, 0, k + 1) rep(j, 0, n + 1) dp[i][j] = inf;
    rep(i, 0, n) dp[1][i] = cost(0, i);

    rep(i, 2, k + 1) conquer(i, 0, n - 1, 0, n - 1);
    cout << dp[k][n - 1] << "\n";
}
