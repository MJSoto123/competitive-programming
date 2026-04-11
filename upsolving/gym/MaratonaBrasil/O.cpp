#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i , a, b) for(int i = a ; i < (b); i++)
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int ,int> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> g(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    int d; cin >> d;
    vi a(d);
    multiset<int> alive; 
    for(int i = 0; i < d; i++) cin >> a[i];
    for(int i = 0; i < d; i++){
        int x; cin >> x; 
        alive.insert(x);
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.emplace(0, 1, 1);

    vi mx(n + 1, 1e9 + 1000);
    while(!q.empty()){
        auto [w2, u, par] = q.top(); q.pop();
        if(mx[u] != 1e9 + 1000) continue;
        mx[u] = max(w2, (mx[par] != 1e9 + 1000) ? mx[par] : 0);

        for(auto [v, w] : g[u]){
            if(mx[v] != 1e9 + 1000) continue;
            q.emplace(w, v, u);
        }
    }


    vi need; 
    int ans = 0;
    for(auto x : a) {
        if(x == 1) ans++;
        else need.emplace_back(mx[x]);
    }
    sort(need.begin(), need.end());

    for(auto x : need){
        auto p = alive.upper_bound(x - 1);
        if(p != alive.end()){
            ans++;
            alive.erase(p);
        }
    }

    cout << ans << "\n";
}