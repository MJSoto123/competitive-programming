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

void solve(){
    int n; cin >> n;
    vvi g(n, vi(3));
    rep(i, 0, n) rep(j, 0, 3) cin >> g[i][j];

    auto check = [&](int i, int j){
        ll a = g[i][0] - g[j][0];
        ll b = g[i][1] - g[j][1];
        ll c = g[i][2] - g[j][2];
        ll discri = b * b - 4 * a * c;
        if(a == 0 && b == 0 && c != 0) return false;
        return (discri >= 0);
    };

    vvi match(n, vi(n));
    rep(i, 0, n) rep(j, 0, n) if(i != j) match[i][j] = check(i, j);
    for(auto x : match){
        for(auto y : x) cout << y << " "; cout << "\n";
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}