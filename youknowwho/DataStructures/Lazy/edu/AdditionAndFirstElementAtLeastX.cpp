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

struct SegmentTree{
    int n;
    vl t, lz;
    SegmentTree(int nn) : n(nn), t(4 * nn + 10, 0), lz(4 * nn + 10, 0) {}
    void push(int node, int l, int r){
        if(lz[node] == 0) return;
        if(l != r){
            lz[2 * node + 1] += lz[node];
            lz[2 * node + 2] += lz[node];
        }
        t[node] += lz[node];
        lz[node] = 0;
    }

    void rangeUpdate(int node, int l, int r, int lq, int rq, ll val){
        push(node, l, r);
        if(lq > r || rq < l) return;
        if(lq <= l && r <= rq){
            lz[node] += val;
            push(node, l, r);
            return;
        }
        int mid = l + r >> 1;
        rangeUpdate(2 * node + 1, l, mid, lq, rq, val);
        rangeUpdate(2 * node + 2, mid + 1, r, lq, rq, val);
        t[node] = max(t[2 * node + 1], t[2 * node + 2]);
    }
    void rangeUpdate(int lq, int rq, ll val){ rangeUpdate(0, 0, n - 1, lq, rq, val); }
    
    int treeDescend(int node, int l, int r, int pos, int val){
        push(node, l, r);
        if(l == r){
            if(t[node] >= val) return l;
            return -1;
        }

        int mid = l + r >> 1;
        push(2 * node + 1, l, mid);
        push(2 * node + 2, mid + 1, r);

        int ans = -1;
        if(pos <= mid && t[2 * node + 1] >= val) ans = treeDescend(2 * node + 1, l, mid, pos, val);
        if(ans == -1 && t[2 * node + 2] >= val) ans = treeDescend(2 * node + 2, mid + 1, r, pos, val);
        return ans;
    }
    int treeDescend(int pos, int val){ return treeDescend(0, 0, n - 1, pos, val); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    SegmentTree st(n);

    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r, val; cin >> l >> r >> val;
            r--;
            st.rangeUpdate(l, r, val);
        }else{
            int val, pos; cin >> val >> pos;
            cout << st.treeDescend(pos, val) << "\n";
        }
    }
}