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

// query = max [l, r)
// update = asignar en punto 
// indexa desde 0 
struct SegmentTree{
	vi tree; 
	int n;
	SegmentTree(int n) : n(n) , tree(2 * n + 5, -1) {}
	void upd(int p, int v){
		p += n; 
		for(tree[p] = v; p > 1; p>>=1) tree[p>>1] = max(tree[p],tree[p^1]);
	}
	int query(int l, int r){ // [l, r)
		int res = -1; // ctmre 
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = max(res, tree[l++]);
			if(r & 1) res = max(res, tree[--r]);
		}
		return res;
	}
};

void solve(){
    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi pv(n, 0); // primro mayor <===
    stack<int> st;
    rep(i, 0, n){
        while(sz(st) && a[st.top()] <= a[i]) st.pop();
        if(sz(st)) pv[i] = st.top();
        else pv[i] = -1;
        st.push(i);
    }
    while(sz(st)) st.pop();
    
    vi nx(n, 0); // primero menor hacia --- > 
    for(int i = n - 1; i >= 0; i--){
        while(sz(st) && a[st.top()] >= a[i]) st.pop();
        if(sz(st)) nx[i] = st.top();
        else nx[i] = n;
        st.push(i);
    }

    // rep(i, 0, n) cout << a[pv[i]] << " \n"[i == n - 1];
    // rep(i, 0, n) cout << a[nx[i]] << " \n"[i == n - 1];

    vvi add(n);
    rep(i, 0, n){
        if(nx[i] == n) continue;
        add[nx[i]].emplace_back(i);
    }

    // rep(i, 0, n){
    //     rep(j, 0, sz(add[i])) cout << add[i][j] << " ";
    //     cout << "\n";
    // }

    vector<vii> qs(n + 1);
    rep(qq, 0, q){
        int l, r; cin >> l >> r;
        l--; r--;
        qs[r].emplace_back(l, qq);
    }

    SegmentTree seg(n + 10);
    vi ans(q);
    rep(i, 0, n){
        // avisar que el pv prende ahora
        rep(j, 0, sz(add[i])){
            int mid = add[i][j];
            if(pv[mid] == -1) continue;
            // cout << "on " << a[i] << " " << a[mid] << " " << a[pv[mid]] << "\n"; 
            seg.upd(pv[mid], pv[mid]);
        }

        rep(j, 0, sz(qs[i])){
            auto [l, id] = qs[i][j];
            int mx = seg.query(l, i + 1);
            // cout << "query " << l << " " << i << " => " << mx << "\n";
            if(mx == -1) ans[id] = 1;
        }
    }

    rep(i, 0, q) cout << (ans[i] ? "YES" : "NO") << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}