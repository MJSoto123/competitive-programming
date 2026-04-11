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

const int N = 2000 + 5;
int m, d;
int high[N];
int dp[N][N][2][2][2];

const int MOD = 1e9 + 7;
int add(int a, int b, int mod){ return (a + b) % mod; }
int subs(int a, int b, int mod){ a %= mod; b %= mod; return (a - b + mod) % mod; }
int mul(ll a, ll b, int mod){ return (a * b) % mod; }

void init(){
    memset(dp, -1, sizeof(dp));
}

int dfs(int pos, int res = 0, int positive = 0, int smaller = 0, int parity = 0){
    if(pos < 0) return (positive && res == 0);
    auto &memo = dp[pos][res][positive][smaller][parity];
    if(memo != -1) return memo;

    int ret = 0;        
    if(positive && parity == 1){
        int mxd = smaller ? 9 : high[pos];
        if(d <= mxd) ret = add(ret, dfs(pos - 1, add(mul(res, 10, m), d, m), 1, smaller || d < high[pos], 0), MOD);
    }

    if(parity == 0){
        int mxd = smaller ? 9 : high[pos];
        for(int dig = 0; dig <= mxd; dig++){
            if(dig == d){
                if(d == 0 && !positive) {}
                else continue;
            }
            int npos = pos - 1;
            int nres = add(mul(res, 10, m), dig, m);
            int npositive = positive || dig != 0;
            int nsmaller = smaller || dig < high[pos];
            int nparity;
            
            if(positive) nparity = parity ^ 1;
            else nparity = (dig != 0);

            ret = add(ret, dfs(npos, nres, npositive, nsmaller, nparity), MOD);
        }
    }

    return memo = ret;
}

int solve(int cnt){
    init();
    return dfs(cnt); 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> d;
    string l, r; cin >> l >> r;
    reverse(all(l));
    reverse(all(r));
    int n = sz(l);

    rep(i, 0, n) high[i] = r[i] - '0';
    int ansR = solve(n - 1);
    
    
    rep(i, 0, n) high[i] = l[i] - '0';
    high[0]--;
    rep(i, 0, n){
        if(high[i] < 0){
            high[i] += 10;
            high[i + 1]--; 
        }
    }

    int ansL;
    if(high[n - 1] == 0) ansL = solve(n - 2);
    else ansL = solve(n - 1);

    // cerr << ansR << " " << ansL << "\n";
    cout << subs(ansR, ansL, MOD) << "\n";
}