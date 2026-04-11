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
    vl t, lz1, lz2;
    SegmentTree(int nn) : n(nn), t(4 * nn + 10, 0), lz1(4 * nn + 10, -1), lz2(4 * nn + 10, 0) {}
    void push(int node, int l, int r){
        if(lz1[node] != -1){
            if(l != r){
                lz1[2 * node + 1] = lz1[node];
                lz2[2 * node + 1] = 0;
                
                lz1[2 * node + 2] = lz1[node];
                lz2[2 * node + 2] = 0;
            }
            t[node] = lz1[node] * (r - l + 1);
            lz1[node] = -1;
        }

        if(lz2[node] != 0){
            if(l != r){
                lz2[2 * node + 1] += lz2[node];
                lz2[2 * node + 2] += lz2[node];
            }
            t[node] += lz2[node] * (r - l + 1);
            lz2[node] = 0;
        }
    }
    
    void rangeAssign(int node, int l, int r, int lq, int rq, ll val){
        push(node, l, r);
        if(lq > r || rq < l) return;
        if(lq <= l && r <= rq){
            lz1[node] = val;
            lz2[node] = 0;
            push(node, l, r);
            return;
        }
        int mid = l + r >> 1;
        rangeAssign(2 * node + 1, l, mid, lq, rq, val);
        rangeAssign(2 * node + 2, mid + 1, r, lq, rq, val);
        t[node] = t[2 * node + 1] + t[2 * node + 2];
    }
    void rangeAssign(int lq, int rq, ll val){ rangeAssign(0, 0, n - 1, lq, rq, val); }

    void rangeAdd(int node, int l, int r, int lq, int rq, ll val){
        push(node, l, r);
        if(lq > r || rq < l) return;
        if(lq <= l && r <= rq){
            lz2[node] += val;
            push(node, l, r);
            return;
        }
        int mid = l + r >> 1;
        rangeAdd(2 * node + 1, l, mid, lq, rq, val);
        rangeAdd(2 * node + 2, mid + 1, r, lq, rq, val);
        t[node] = t[2 * node + 1] + t[2 * node + 2];
    }
    void rangeAdd(int lq, int rq, ll val){ rangeAdd(0, 0, n - 1, lq, rq, val); }

    ll rangeQuery(int node, int l, int r, int lq, int rq){
        push(node, l, r);
        if(lq > r || rq < l) return 0;
        if(lq <= l && r <= rq) return t[node];
        int mid = l + r >> 1;
        return (
            rangeQuery(2 * node + 1, l, mid, lq, rq) +
            rangeQuery(2 * node + 2, mid + 1, r, lq, rq)
        );
    }
    ll rangeQuery(int lq, int rq){ return rangeQuery(0, 0, n - 1, lq, rq); }
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
            st.rangeAssign(l, r, val);
        }else if(op == 2){
            int l, r, val; cin >> l >> r >> val;
            r--;
            st.rangeAdd(l, r, val);
        }else{
            int l, r; cin >> l >> r;
            r--;
            cout << st.rangeQuery(l, r) << "\n";
        }
    }
}