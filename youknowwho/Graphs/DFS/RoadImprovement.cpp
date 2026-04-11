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

    int n; cin >> n;
    vvi g(n);
    map<pii, int> mp;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--; v--;
        if(u < v) swap(u, v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        mp[{u, v}] = i;
    }

    vi vis(n);
    map<pii, int> ans;
    queue<int> q;
    vis[0] = 1;
    q.emplace(0);
    while(sz(q)){
        int u = q.front(); q.pop();
        vii ed;
        set<int> st;
        for(auto v : g[u]){
            pii e(max(u, v), min(u, v));
            if(vis[v]){
                st.insert(ans[e]);
                continue;
            }
            ed.emplace_back(e);
            vis[v] = 1;
            q.emplace(v);
        }
        
        int mex = 0;
        for(auto e : ed){
            while(st.count(mex)) mex++;
            ans[e] = mex; 
            // cout << "ed " << e.first + 1 << " " << e.second + 1 << " " << mex << "\n";
            st.insert(mex);
        }
    }

    int mx = 0;
    for(auto [e, i] : ans) mx = max(mx, i);

    vvi go(mx + 1);
    for(auto [e, i] : ans) go[i].emplace_back(mp[e]);

    cout << sz(go) << "\n";
    for(auto x : go){
        cout << sz(x) << " ";
        for(auto y : x) cout << y + 1 << " "; cout << "\n";
    }
}