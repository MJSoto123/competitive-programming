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

const int N = 1e5 + 5;
bitset<N> dp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    dp.reset();
    dp[0] = 1;

    for(auto w : a) dp |= (dp << w);
    vi pre(N + 1);
    for(int i = 1; i < N; i++) pre[i + 1] = pre[i] + (dp[i] ? 1 : 0);

    rep(qq, 0, q){
        int l, r; cin >> l >> r;
        cout << pre[r + 1] - pre[l] << "\n";
    }
}