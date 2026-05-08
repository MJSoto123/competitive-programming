#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k; 
    vvi adj(n), prod(k); 
    rep(i,0,n) { 
        int x; cin >> x; 
        x--; 
        prod[x].push_back(i); 
    } 
    rep(i,0,m) { 
        int u, v; cin >> u >> v; 
        u--, v--;
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }

    queue<int> q; 
    vi d(n, -1); 
    d[0] = 0; 
    q.push(0); 
    while(sz(q)) {
        int u = q.front(); q.pop(); 
        for(int v : adj[u]) {
            if(d[v] == -1) { 
                q.push(v); 
                d[v] = d[u] + 1; 
            }
        } 
    }

    // for(int i : d) cerr << i << " "; cerr << "\n"; 

    rep(i,0,k) { 
        int mx = -1; 
        for(int u : prod[i]) mx = max(mx, d[u]); 
        cout << mx << " "; 
    }
    cout << "\n";

}