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
const int N = 21;
int dp[1 << 21][7];
int sos[1 << 21];

vii domi;
void init(){
    rep(i, 1, 7) rep(j, i, 7) domi.emplace_back(i, j);
    rep(i, 1, 7) dp[0][i] = 1;

    rep(mask, 0, (1 << 21)) rep(lst, 1, 7) if(dp[mask][lst]){
        rep(i, 0, 21){
            if(mask & (1 << i)) continue;
            auto [l, r] = domi[i];
            int nmask = mask | (1 << i);
            if(l == lst) dp[nmask][r] = 1;
            if(r == lst) dp[nmask][l] = 1;
        }
    }

    rep(mask, 0, (1 << 21)) rep(i, 1, 7) sos[mask] |= dp[mask][i];
    rep(i, 0, 21) rep(mask, 0, (1 << 21)) if(mask & (1 << i)) sos[mask] += sos[mask ^ (1 << i)];
}

void solve(){
    int n; cin >> n;
    set<pii> st;
    rep(i, 0, n){
        int a, b; cin >> a >> b;
        st.insert({min(a, b), max(a, b)});
    }

    int mask = 0;
    rep(i, 0, 21) if(st.count(domi[i])) mask |= (1 << i);

    cout << sos[mask] - 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    int tt; cin >> tt;
    while(tt--) solve();
}