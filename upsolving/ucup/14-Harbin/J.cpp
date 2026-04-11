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

const int inf = 1e9 + 100;
void solve(){
    int n, m; cin >> n >> m;
    vi power(n);
    vi pos(m), bat(m);

    rep(i, 0, n) cin >> power[i];
    rep(i, 0, m) cin >> pos[i] >> bat[i], bat[i]--;

    priority_queue<pii, vii, greater<pii>> q;
    
    // aparece
    vvi alive(n);
    rep(i, 0, m) alive[bat[i]].emplace_back(pos[i]);
    rep(i, 0, n) alive[i].emplace_back(inf);

    // primera
    rep(i, 0, n) q.emplace(alive[i][0], i);
    
    // siguiente
    vi nxt(n);
    vi energy = power;
    
    int now = 0;
    rep(i, 0, m){
        int target = pos[i];

        // usar
        while(now < target){
            if(!sz(q)){ cout << now << "\n"; return; }
            auto [p, id] = q.top(); q.pop();
            int e = energy[id];
            int add = min(target - now, e);
            now += add; energy[id] -= add;
            if(energy[id]) q.emplace(p, id);
        }

        // now == target
        int id = bat[i];
        if(energy[id]) q.pop();
        energy[id] = power[id];
        nxt[id]++;
        if(nxt[id] < sz(alive[id])) q.emplace(alive[id][nxt[id]], id);
    }
    ll ans = now + accumulate(all(energy), 0LL);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();  
}