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
int add(int a, int b){ return (a + b) % MOD; }
int mul(ll a, ll b){ return (a * b) % MOD; }

const int N = 5e5;
int dp[N];

void init(){
    dp[0] = 1;
    dp[1] = 2;
    rep(i, 2, N) dp[i] = add(mul(2, dp[i - 1]), mul(i - 1, dp[i - 2]));
}

void solve(){
    int n; cin >> n; n++;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi vis(n, -1);
    int sobra = n;
    rep(i, 1, n){
        if(a[i] == -1 || vis[i] != -1) continue;
        sobra--;
        int other = a[i];
        if(other >= n){ cout << "0\n"; return; }
        if(other == 0 || other == i) continue;

        if(a[other] == -1){
            a[other] = i;
            vis[other] = 1;
            sobra--;
        }else if(a[other] != i){ cout << "0\n"; return; }
    }

    sobra--;
    int ans = dp[sobra];
    // 0
    if(a[n - 1] == -1) ans = add(ans, MOD - dp[sobra - 1]);
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int tt; cin >> tt;
    while(tt--) solve();
}