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

const int N = 31;
int dp[N][N * N];
void solve(){
    int n, k; cin >> n >> k;
    rep(j, 0, N) rep(k, 0, N * N) dp[j][k] = -1;

    dp[0][0] = 0;
    rep(w, 2, n + 1){
        int add = w * (w - 1) / 2;
        rep(i, 0, n + 1){
            if(w + i > n) continue;
            rep(j, 0, n * n + 1){
                if(dp[i][j] == -1) continue;
                if(add + j > n * n) continue;
                dp[i + w][j + add] = w;
            }
        }
    }

    int need = n * (n - 1) / 2 - k;
    int sm = -1;
    rep(i, 0, n + 1) if(dp[i][need] != -1) sm = i;
    if(sm == -1){ cout << "0\n"; return; }
    
    vi ans;
    while(sm != 0){
        int used = dp[sm][need];
        ans.emplace_back(used);
        need -= (used * (used - 1) / 2);
        sm -= used;
    }

    sm = accumulate(all(ans), 0);
    int sobra = n - sm;
    int curr = n;

    vi p(n);
    rep(i, 0, sobra) p[i] = curr--;
    int pos = sobra;
    for(auto x : ans){
        for(int i = pos + x - 1; i >= pos; i--) p[i] = curr--;
        pos += x;
    }
    
    rep(i, 0, n) cout << p[i] << " \n"[i == n - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}