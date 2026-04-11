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
    vii a(n);
    rep(i, 0, n){
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(all(a), [&](pii l, pii r){
        auto [v1, p1] = l;
        auto [v2, p2] = r;
        if(v1 == v2) return p1 < p2;
        return v1 < v2;
    });

    reverse(all(a));
    int cnt = 0;
    int pos = n + 1;
    for(auto [v, p] : a){
        if(p < pos){
            cnt++;
            pos = p;
        }
    }
    cout << cnt << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}