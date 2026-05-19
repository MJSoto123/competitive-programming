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

vi col;
vi in;
vvi g;
vi ans;
vi mx;
int n;
vector<map<int, int>> sub;

void dfs(int u){
    sub[u][col[u]]++;

    mx[u] = 1;
    ans[u] = col[u];
    
    for(auto v : g[u]){
        dfs(v);

        if(sz(sub[v]) > sz(sub[u])){
            swap(sub[v], sub[u]); 
            ans[u] = ans[v];
            mx[u] = mx[v];
        }

        for(auto [c, cnt] : sub[v]){
            sub[u][c] += cnt;

            if(sub[u][c] == mx[u]) ans[u] = min(ans[u], c);
            else if(sub[u][c] > mx[u]){ 
                mx[u] = sub[u][c];
                ans[u] = c;
            }
        }
    }
    // cerr << "ver " << u + 1 << "\n";
    // for(auto [c, cnt] : sub) cerr << c << " " << cnt << "\n";
    // cerr << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    sub.resize(n);
    col.resize(n);
    in.resize(n);
    mx.resize(n);
    ans.resize(n, n + 1);
    rep(i, 0, n) cin >> col[i];

    g.resize(n);
    rep(i, 0, n - 1){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].emplace_back(v);
        in[v]++;
    }

    int root;
    rep(i, 0, n) if(in[i] == 0) root = i;
    
    dfs(root);

    rep(i, 0, n) cout << ans[i] << " "; cout << "\n";
}