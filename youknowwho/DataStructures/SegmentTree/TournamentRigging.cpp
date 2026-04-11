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

void solve(){
    int n, w; cin >> n >> w;
    n = (1 << n);
    vi a;
    rep(i, w, n + 1) a.emplace_back(i);
    rep(i, 1, w) a.emplace_back(i);
     
    vi ans = a;
    while(sz(a) != 1){
        vi nxt;
        for(int i = 0; i < sz(a); i += 2){
            if(a[i] == w || a[i + 1] == w) nxt.emplace_back(w);
            else nxt.emplace_back(min(a[i], a[i + 1]));
        }
        a = nxt;
        for(auto x : a) ans.emplace_back(x);
    }
    reverse(all(ans));
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}