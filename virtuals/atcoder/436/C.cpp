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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    set<pii> ban;
    int ans = 0;
    rep(i, 0, m){
        int r, c; cin >> r >> c;
        if(ban.count({r, c})) continue;
        ans++;
        ban.emplace(r - 1, c - 1);
        ban.emplace(r - 1, c);
        ban.emplace(r - 1, c + 1);
        ban.emplace(r, c - 1);
        ban.emplace(r, c);
        ban.emplace(r, c + 1);
        ban.emplace(r + 1, c - 1);
        ban.emplace(r + 1, c);
        ban.emplace(r + 1, c + 1);
    }

    cout << ans << "\n";
}