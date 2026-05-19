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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vvi a(n, vi(m));
    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, m) a[i][j] = (s[j] == '1');
    }

    rep(i, 0, n){
        for(int j = m - 2; j >= 0; j--) if(a[i][j]) a[i][j] += a[i][j + 1];
    }

    int ans = 0;
    rep(i, 0, m){
        vi vec;
        rep(j, 0, n) vec.emplace_back(a[j][i]);

        sort(all(vec));
        reverse(all(vec));
        rep(j, 0, n) ans = max(ans, (j + 1) * (vec[j]));
    }

    cout << ans << "\n";
}