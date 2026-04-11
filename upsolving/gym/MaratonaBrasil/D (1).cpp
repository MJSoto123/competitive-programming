#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll; 
typedef vector<ll> vl; 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pii> vii;



signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m; 
	int x, y; cin >> x >> y; x--, y--; 
	vector grid(n, vl(m)); rep(i,0,n) rep(j,0,m) cin >> grid[i][j] ; 
	
	vii d = {{0,1}, {0, -1}, {1, 0}, {-1, 0}} ; 
	auto ok = [&](int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; };
	
	auto go = [&](int si, int sj) { 
		ll ans = 0  ; 
		vvi g(n, vi(m)) ; 
		vector<vector<bool> > vis(n, vector<bool>(m, false)) ; 
		vector<vector<bool> > comp(n, vector<bool>(m, true)); 
		for(int bit = 32; bit >= 0; bit--) { 
			rep(i,0,n) rep(j,0,m) { 
				if((grid[i][j] >> bit) & 1) g[i][j] = 1; 
				else g[i][j] = 0 ; 
			}
			for(auto &i : vis) fill(all(i), false); 
			queue<pii> q; 
			q.emplace(si, sj) ; 
			vis[si][sj] = true; 
			while(sz(q)) { 
				auto [i, j] = q.front(); q.pop(); 
				for(auto [di, dj] : d) { 
					int ni = i + di; 
					int nj = j + dj; 
					if(!ok(ni, nj)) continue; 
					if(!vis[ni][nj] && comp[i][j] && g[i][j] == 0) { 
						vis[ni][nj] = true; 
						q.emplace(ni, nj); 
					}
				}
			}	
			if(vis[n - 1][m - 1]) { 
				rep(i,0,n) { 
					rep(j,0,m) { 
						if(comp[i][j] && g[i][j] == 0) comp[i][j] = 1; 
						else comp[i][j] = 0; 
					}
				}
			}else ans |= (1LL << bit); 
		}
		return ans; 
	};
	cout << go(0,0) << " " << go(x, y) << "\n"; 
}
