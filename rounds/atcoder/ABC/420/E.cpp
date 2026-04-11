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

const int N = 2e5 + 6;
vi g[N];
int col[N];
int Par[N];
int Sz[N];
int Black[N];

int get(int u){
    return (u == Par[u] ? u : Par[u] = get(Par[u]));
}

void unite(int u, int v){
    u = get(u), v = get(v);
    if(u == v) return;
    if(Sz[u] < Sz[v]) swap(u, v);
    Par[v] = u;
    Sz[u] += Sz[v];
    Black[u] += Black[v];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        col[i] = 0;
        Par[i] = i;
        Sz[i] = 1;
        Black[i] = 0;
    }
    for(int i = 0; i < q; i++){
        int op; cin >> op; 
        if(op == 1){
            int u, v; cin >> u >> v;
            unite(u, v);
        } else if(op == 2){
            int u; cin >> u;
            int pu = get(u);
            if(col[u]) Black[pu]--;
            else Black[pu]++;
            col[u] ^= 1;
        }else{
            int u; cin >> u;
            if(Black[get(u)] > 0) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}