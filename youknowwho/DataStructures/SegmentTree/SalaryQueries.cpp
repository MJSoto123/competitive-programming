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

vi d;
struct SegmentTree{
    int n;
    vi t;
    SegmentTree(int nn) : n(nn), t(4 * nn + 10, 0) {}
    void pointUpdate(int node, int l, int r, int target, int val){
        if(target < d[l] || target > d[r]) return;
        if(l == r){
            if(d[l] == target) t[node] += val;
            return;
        }
        int mid = l + r >> 1;
        pointUpdate(2 * node + 1, l, mid, target, val);
        pointUpdate(2 * node + 2, mid + 1, r, target, val);
        t[node] = t[2 * node + 1] + t[2 * node + 2];
    }
    void pointUpdate(int target, int val){ pointUpdate(0, 0, n - 1, target, val); }

    int treeDescend(int node, int l, int r, int val){
        if(d[r] <= val) return t[node];
        if(l == r) return 0;
        int mid = l + r >> 1;
        int ans = treeDescend(2 * node + 1, l, mid, val);
        if(val >= d[mid + 1]) ans += treeDescend(2 * node + 2, mid + 1, r, val);
        return ans;
    }
    int treeDescend(int val){ return treeDescend(0, 0, n - 1, val); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi b = a;
    vvi ops(q, vi(3));
    rep(i, 0, q){
        char op; cin >> op >> ops[i][1] >> ops[i][2];
        ops[i][0] = (op == '!');
        if(ops[i][0]) b.emplace_back(ops[i][2]);
    }

    d = b;
    sort(all(d));
    d.resize(unique(all(d)) - d.begin());
    
    SegmentTree st(sz(d));
    rep(i, 0, n) st.pointUpdate(a[i], 1);

    rep(i, 0, q){
        if(ops[i][0]){
            int id = ops[i][1] - 1;
            st.pointUpdate(a[id], -1);
            a[id] = ops[i][2];
            st.pointUpdate(a[id], 1);
        }else{
            cout << st.treeDescend(ops[i][2]) - st.treeDescend(ops[i][1] - 1) << "\n";
        }
    }
}