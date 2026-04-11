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
    vi t, lz;
    SegmentTree(int nn) : n(nn), t(4 * nn +10, 0), lz(4 * nn + 10, 0) {}
    void push(int node, int l, int r){
        if(lz[node] == 0) return;
        if(l != r){
            lz[2 * node + 1] ^= lz[node];
            lz[2 * node + 2] ^= lz[node];
        }
        t[node] = (r - l + 1) - t[node];
        lz[node] = 0;
    }
    void rangeUpdate(int node, int l, int r, int lq, int rq){
        push(node, l, r);
        if(lq > r || rq < l) return;
        if(lq <= l && r <= rq){
            lz[node] ^= 1;
            push(node, l, r);
            return;
        }
        int mid = l + r >> 1;
        rangeUpdate(2 * node + 1, l, mid, lq, rq);
        rangeUpdate(2 * node + 2, mid + 1, r, lq, rq);
        t[node] = t[2 * node + 1] + t[2 * node + 2];
    }
    void rangeUpdate(int lq, int rq){ rangeUpdate(0, 0, n - 1, lq, rq); }

    int pointQuery(int node, int l, int r, int pos){
        push(node, l, r);
        if(pos < l || pos > r) return 0;
        if(l == r) return t[node];

        int mid = l + r >> 1;
        return (
            pointQuery(2 * node + 1, l, mid, pos) + 
            pointQuery(2 * node + 2, mid + 1, r, pos)
        );
    }
    int treeDescend(int node, int l, int r, int kth){
        push(node, l, r);
        if(l == r) return l;
        int mid = l + r >> 1;

        push(2 * node + 1, l, mid);
        push(2 * node + 2, mid + 1, r);
        if(t[2 * node + 1] >= kth) return treeDescend(2 * node + 1, l, mid, kth);
        return treeDescend(2 * node + 2, mid + 1, r, kth - t[2 * node + 1]);
    }
    int treeDescend(int kth){ return treeDescend(0, 0, n - 1, kth); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    SegmentTree st(n);

    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r; cin >> l >> r;
            r--;
            st.rangeUpdate(l, r);
        }else{
            int kth; cin >> kth;
            cout << st.treeDescend(kth + 1) << "\n";
        }
    }
}