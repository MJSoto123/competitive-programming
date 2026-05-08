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
    cout << fixed << setprecision(7);

    int n, m, l, x, y; cin >> n >> m >> l >> x >> y;
    vii bus(n);
    rep(i, 0, n){
        int ini, fin; cin >> ini >> fin;
        bus[i] = {ini, fin};
    }
    sort(all(bus));

    vi a(m);
    rep(i, 0, m) cin >> a[i];

    vi ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&](int l, int r){
        return a[l] < a[r];
    });

    vector<double> ans(m);

    int id = 0;
    priority_queue<pair<double,int>, vector<pair<double, int>>, greater<>> pq;
    rep(i, 0, m){
        int cur = a[ord[i]];
        // pon
        while(id < n && bus[id].first <= cur){
            auto [ini, fin] = bus[id];
            double tm = 1.0 * (l - fin) / double(y) + 1.0 * (fin - ini) / double(x);
            pq.emplace(tm, fin);
            id++;
        }

        // quita
        while(pq.size() && pq.top().second < cur) pq.pop();
        
        double best = 1e12;
        if(pq.size()) best = pq.top().first;

        ans[ord[i]] = min(best, 1.0 * (l - cur) / double(y));
    }

    rep(i, 0, m) cout << ans[i] << "\n"; 
}