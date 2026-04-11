#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(long long a, long long b){
    return ((a + b) % MOD + MOD) % MOD;
}

struct SegmentTree{
	vector<int> tree; 
	int n;
	SegmentTree(int n) : n(n) , tree(2 * n + 5, 0) {}
	void upd(int p, int v){
		p += n; 
		for(tree[p] = v; p > 1; p>>=1) tree[p>>1] = add(tree[p],tree[p^1]);
	}

	int query(int l, int r){ // [l, r)
		int res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = add(res, tree[l++]);
			if(r & 1) res = add(res, tree[--r]);
		}
		return res;
	}
};

void solve(){
    int n, m, d; cin >> n >> m >> d;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];
    
    SegmentTree dp(m + 5);
    for(int i = 0; i < m; i++){
        if(grid[n - 1][i] == 'X') dp.upd(i, 1);
    }

    
    for(int row = n - 2; row >= 0; row--){
        SegmentTree fix(m + 5);
        for(int col = 0; col < m; col++){
            if(grid[row + 1][col] == 'X') {
                fix.upd(col, dp.query(max(0, col - d), min(col + d + 1, m)));
            }
        }
        dp = fix;

        SegmentTree go(m + 5);
        for(int col = 0; col < m; col++){
            if(grid[row][col] == 'X') {
                go.upd(col, dp.query(max(0, col - d + 1), min(col + d, m)));
            }
        }
        dp = go;
    }
    SegmentTree fix(m + 5);
    for(int col = 0; col < m; col++){
        if(grid[0][col] == 'X') {
            fix.upd(col, dp.query(max(0, col - d), min(col + d + 1, m)));
        }
    }
    dp = fix;
    cout << dp.query(0, m) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}