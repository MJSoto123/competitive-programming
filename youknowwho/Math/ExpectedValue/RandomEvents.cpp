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
    int n, m; cin >> n >> m;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vector<pair<int, double>> ev(m);
    rep(i, 0, m) cin >> ev[i].first >> ev[i].second;
    sort(all(ev));

    int lst = n - 1;
    while(lst >= 0 && a[lst] == lst + 1) lst--;
    if(lst == -1){ cout << 1 << "\n"; return; }
    lst++;

    vector<double> goods;
    for(auto [r, p] : ev) if(r >= lst) goods.emplace_back(p);

    if(goods.empty()){ cout << "0\n"; return; }
    double ans = 1;
    for(auto p : goods) ans *= (1.0 - p);
    
    cout << 1.0 - ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(7);

    int tt; cin >> tt; 
    while(tt--) solve();   
}