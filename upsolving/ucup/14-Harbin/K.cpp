#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

// query = max [l, r)
// update = asignar en punto 
// indexa desde 0 
struct SegmentTree{
	vl tree; 
	int n;
	SegmentTree(int n) : n(n) , tree(2 * n + 5, 0) {}
	void upd(int p, ll v){
		p += n; 
		for(tree[p] = v; p > 1; p>>=1) tree[p>>1] = tree[p] + tree[p^1];
	}
	ll query(int l, int r){ // [l, r]
        r++;
		ll res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) res += tree[l++];
			if(r & 1) res += tree[--r];
		}
		return res;
	}
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    ll m; cin >> m;

    vvl a(n + 1, vl(3));
    rep(i, 1, n + 1) rep(j, 0, 3) cin >> a[i][j];
    sort(all(a));

    SegmentTree L(n + 10);
    SegmentTree R(n + 10);
    SegmentTree LSUM(n + 10);
    SegmentTree RSUM(n + 10);

    rep(i, 1, n + 1) L.upd(i, a[i][1]);
    rep(i, 1, n + 1) LSUM.upd(i, a[i][1] * a[i][0]);
    rep(i, 1, n + 1) R.upd(i, a[i][2]);
    rep(i, 1, n + 1) RSUM.upd(i, a[i][2] * a[i][0]);

    ll inf = 1e11 + 10;
    ll ans = 0;
    rep(i, 1, n + 1){
        // ban
        L.upd(i, 0);
        R.upd(i, inf);
        LSUM.upd(i, 0);
        RSUM.upd(i, 0);

        // chose r 
        int l = i, r = n + 1;
        while(r - l > 1){
            int mid = l + r >> 1;
            ll sm = L.query(0, mid - 1) + R.query(mid, n + 1);
            if(sm <= m) r = mid;
            else l = mid;
        }

        ll sobra = m - L.query(0, r - 1) - R.query(r, n + 1);
        ll anshere = LSUM.query(0, r - 1) + RSUM.query(r, n + 1);
        if(sobra > 0){
            if(r - 1 <= i) anshere += sobra * a[i][0];
            else anshere += min(sobra, a[r - 1][2] - a[r - 1][1]) * a[r - 1][0];
        }
        ans = max(ans, anshere);

        // unban
        L.upd(i, a[i][1]);
        LSUM.upd(i, a[i][1] * a[i][0]);
        R.upd(i, a[i][2]);
        RSUM.upd(i, a[i][2] * a[i][0]);
    }
    cout << ans << "\n";
}