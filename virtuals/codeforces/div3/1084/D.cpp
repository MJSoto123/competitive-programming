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
    int n, l, r; cin >> n >> l >> r;
    vi a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    
    vi sides, mid;
    rep(i, 1, min(l + 1, n + 1)) sides.emplace_back(a[i]);
    rep(i, l + 1, min(r + 1, n + 1)) mid.emplace_back(a[i]);
    rep(i, r + 1, n + 1) sides.emplace_back(a[i]);

    if(sz(mid)){
        int mn = *min_element(all(mid));
        rep(i, 0, sz(mid)) if(mn == mid[i]){
            vi tmp;
            rep(j, i, sz(mid)) tmp.emplace_back(mid[j]);
            rep(j, 0, i) tmp.emplace_back(mid[j]);
            mid = tmp;
            break;
        }
    }

    if(mid.empty() || sides.empty()){
        for(auto x : mid) cout << x << " ";
        for(auto x : sides) cout << x << " ";
        cout << "\n";
        return;
    }

    int i = 0, j = 0;
    while(i < sz(sides) && j < sz(mid)){
        if(sides[i] < mid[j]){
            cout << sides[i] << ' ';
            i++;
        }else break;
    }
    rep(k, j, sz(mid)) cout << mid[k] << " ";
    rep(k, i, sz(sides)) cout << sides[k] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}