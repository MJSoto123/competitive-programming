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

const int N = 16;
int n;
int a[N];
int dp[(1 << N)];
vi valid;

void print(int mask){
    vi used, others;
    rep(i, 0, n){
        if(mask & (1 << i)) used.emplace_back(a[i]);
        else others.emplace_back(a[i]);
    }
    cerr << "used ";
    for(auto x : used) cerr << x << " "; cerr << "\n";

    cerr << "others ";
    for(auto x : others) cerr << x << " "; cerr << "\n\n";
}

void go(int mask){
    if(dp[mask] != -1) return;
    dp[mask] = 0;
    for(auto team : valid){
        if(mask & team) continue;
        go(mask | team);
        dp[mask] = max(dp[mask], 1 + dp[mask | team]);
    }
}

void solve(){
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, (1 << n)) dp[i] = -1;
    valid.clear();

    rep(i, 0, n) rep(j, i + 1, n) rep(k, j + 1, n) if(a[i] + a[j] + a[k] >= 20){
        valid.emplace_back((1 << i) + (1 << j) + (1 << k));
    }

    go(0);
    cout << dp[0] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while(cin >> n){
        if(n == 0) return 0;
        cout << "Case " << t++ << ": ";
        solve();
    } 
}