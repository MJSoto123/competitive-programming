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
const int MOD = 1e9 + 7;
void add(int &a, int b){ a += b; if(a >= MOD) a -= MOD; }
int mod;

int high[10005];
int dp[10005][105][2];

void init(){
    memset(dp, -1, sizeof(dp));
}

ll dfs(int pos, int sm, int smaller = 0){
    if(pos < 0) return ((sm % mod) == 0);
    auto &memo = dp[pos][sm][smaller];
    if(memo != -1) return memo;
    
    int mxd = smaller ? 9 : high[pos];
    int ret = 0;
    rep(d, 0, mxd + 1){
        int shere = smaller || d < high[pos];
        add(ret, dfs(pos - 1, (sm + d) % mod, shere));
    }
    return memo = ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    string s; cin >> s >> mod;
    int n = sz(s);
    
    rep(i, 0, n) high[i] = s[i] - '0';
    reverse(high, high + n);
    int ans = dfs(n - 1, 0, 0);

    add(ans, MOD - 1);
    cout << ans << "\n";
}