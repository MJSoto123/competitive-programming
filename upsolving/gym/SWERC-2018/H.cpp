#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

int n;
const int N = 100000 + 10;
ll D[N];
vii G[N];
 
void Dijkstra(int src) {
	for(int i = 0; i < n; i++) D[i] = -1;
	D[src] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.emplace(0, src);
	while(!Q.empty()) {
		int dis, u;
		tie(dis, u) = Q.top(); Q.pop();
		if(dis != D[u]) continue;
		for(auto e : G[u]) {
			int v, w;
			tie(v, w) = e;
			if(D[v] == -1 or D[v] > D[u] + w) {
				D[v] = D[u] + w;
				Q.emplace(D[v], v);
			}
		}
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    
    vvi a(n, vi(3));
    for(int i = 0; i < 3; i++){
        Dijkstra(i);
        for(int u = 0; u < n; u++) a[u][i] = D[u];
    }

    map<tuple<int, int, int>, int> b;
    for(int i = 0; i < n; i++) b[make_tuple(a[i][0], a[i][1], a[i][2])]++;

    map<int, int> mp;
    int ans = 0;
    for(auto [tup, cnt] : b){
        auto [z, x, y] = tup;

        auto it = mp.upper_bound(x);
        if(it != mp.begin()){
            auto [px, py] = *prev(it);
            if(py <= y) continue;
        }
        ans += cnt;

        for(auto ii = mp.lower_bound(x); ii != mp.end();){
            auto [oldx, oldy] = *ii;
            if(oldy >= y) ii = mp.erase(ii);
            else break;
        }
        mp[x] = y;
    }

    cout << ans << "\n";
}