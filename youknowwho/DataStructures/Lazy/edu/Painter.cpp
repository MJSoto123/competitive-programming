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

struct Node{
    int cnt, sm, front, back;
    Node(int cnt = 0, int sm = 0, int front = 0, int back = 0) : cnt(cnt), sm(sm), front(front), back(back) {}
    Node operator+(const Node &other) const {
        return Node(
            cnt + other.cnt - (back && other.front),
            sm + other.sm,
            front,
            other.back
        );
    }
};

Node NIL;
struct SegmentTree{
    int n;
    vector<Node> t;
    vi lz;
    SegmentTree(int nn) : n(nn), t(4 * nn + 10, NIL), lz(4 * nn + 10, -1) {}
    void push(int node, int l, int r){
        if(lz[node] == -1) return;
        if(l != r){
            lz[2 * node + 1] = lz[node];
            lz[2 * node + 2] = lz[node];
        }   
        if(lz[node] == 1) t[node] = Node(1, r - l + 1, 1, 1);
        if(lz[node] == 0) t[node] = Node(0, 0, 0, 0);
        lz[node] = -1;
    }

    void rangeUpdate(int node, int l, int r, int lq, int rq, int color){
        push(node, l, r);
        if(lq > r || rq < l) return;
        if(lq <= l && r <= rq){
            lz[node] = color;
            push(node, l, r);
            return;
        }
        int mid = l + r >> 1;
        rangeUpdate(2 * node + 1, l, mid, lq, rq, color);
        rangeUpdate(2 * node + 2, mid + 1, r, lq, rq, color);
        t[node] = t[2 * node + 1] + t[2 * node + 2];
    }
    void rangeUpdate(int lq, int rq, int color){ rangeUpdate(0, 0, n - 1, lq, rq, color); }

    Node rangeQuery(int node, int l, int r, int lq, int rq){
        push(node, l, r);
        if(lq > r || rq < l) return NIL;
        if(lq <= l && r <= rq) return t[node];

        int mid = l + r >> 1;
        return (
            rangeQuery(2 * node + 1, l, mid, lq, rq) + 
            rangeQuery(2 * node + 2, mid + 1, r, lq, rq)
        );
    }
    Node rangeQuery(int lq, int rq){ return rangeQuery(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int off = 1e6 + 10;
    int N = 2e6 + 10;
    SegmentTree st(N);
    int n; cin >> n;
    rep(_, 0, n){
        char op; cin >> op;
        int l, len; cin >> l >> len;
        if(op == 'W') st.rangeUpdate(off + l, off + l + len - 1, 0);
        else st.rangeUpdate(off + l, off + l + len - 1, 1);

        auto ans = st.rangeQuery(0, N - 1);
        cout << ans.cnt << " " << ans.sm << "\n";
    }
}