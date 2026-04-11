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

// query = max [l, r)
// update = asignar en punto 
// indexa desde 0 
struct MX{
	vi tree; 
	int n;
	MX(int n) : n(n) , tree(2 * n + 5, 0) {}
	void upd(int p, int v){
		p += n; 
		for(tree[p] = v; p > 1; p>>=1) tree[p>>1] = max(tree[p],tree[p^1]);
	}
	int query(int l, int r){ // [l, r)
		int res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = max(res, tree[l++]);
			if(r & 1) res = max(res, tree[--r]);
		}
		return res;
	}
};

struct MN{
	vi tree; 
	int n;
	MN(int n) : n(n) , tree(2 * n + 5, 2e5) {}
	void upd(int p, int v){
		p += n; 
		for(tree[p] = v; p > 1; p>>=1) tree[p>>1] = min(tree[p],tree[p^1]);
	}
	int query(int l, int r){ // [l, r)
		int res = 2e5;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = min(res, tree[l++]);
			if(r & 1) res = min(res, tree[--r]);
		}
		return res;
	}
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vi l(n), r(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];

    MX segmax(n + 1);
    MN segmin(n + 1);
    for(int i = 0; i < n; i++) segmax.upd(i, l[i]);
    for(int i = 0; i < n; i++) segmin.upd(i, r[i]);

    int low = 0, high = n + 1;
    while(high - low > 1){
        int mid = (high + low) >> 1;
        bool ok = false;
        for(int i = 0; i <= n - mid; i++){
            int nowl = segmax.query(i, i + mid);
            int nowr = segmin.query(i, i + mid);
            if(nowr - nowl + 1 >= mid) ok = true;
        }
        if(ok) low = mid;
        else high = mid;
    }

    cout << low << "\n";
}