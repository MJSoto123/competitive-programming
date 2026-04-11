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
    int ans[2][2];
    Node(){
        rep(i, 0, 2) rep(j, 0, 2) ans[i][j] = 0;
    }
    Node(char c){
        rep(i, 0, 2) rep(j, 0, 2) ans[i][j] = 0;
        int ch = (c == '1');
        ans[ch][ch] = 1;
    }
    Node operator+(const Node &other) const {
        Node ret;
        auto &xd = ret.ans;
        rep(l, 0, 2) rep(r, 0, 2){
            xd[l][r] = max(xd[l][r], ans[l][0] + other.ans[1][r]);
            xd[l][r] = max(xd[l][r], ans[l][1] + other.ans[0][r]);
        }
        return ret;
    }

    Node flip(){
        Node ret;
        rep(i, 0, 2) rep(j, 0, 2) ret.ans[i][j] = ans[i ^ 1][j ^ 1];
        return ret;
    }
};
Node NIL;
struct Seg{
    int n;
    vector<Node> t;
    vi lz;
    void build(const string &a, int v, int l, int r){
        if(l ==  r){
            t[v] = Node(a[l]);
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2]; 
    }
    void init(const string &a){
        n = sz(a);
        t.assign(4 * n + 10, NIL);
        lz.assign(4 * n + 10, 0);
        build(a, 0, 0, n - 1);
    }

    void push(int v, int l, int r){
        if(lz[v] == 0) return;
        if(l != r){
            lz[2 * v + 1] ^= lz[v];
            lz[2 * v + 2] ^= lz[v];
        }
        t[v] = t[v].flip();
        lz[v] = 0;
    }

    void upd(int v, int l, int r, int lq, int rq){
        push(v, l, r);
        if(lq > r || l > rq) return;
        if(lq <= l && r <= rq){
            lz[v] ^= 1;
            push(v, l, r);
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, lq, rq);
        upd(2 * v + 2, mid + 1, r, lq, rq);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void upd(int lq, int rq){ upd(0, 0, n - 1, lq, rq); }

    Node query(int v, int l, int r, int lq, int rq){
        push(v, l, r);
        if(lq > r || l > rq) return NIL;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return (
            query(2 * v + 1, l, mid, lq, rq) + 
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    Node query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    string s; cin >> s;
    
    Seg st; st.init(s);
    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r; cin >> l >> r;
            l--; r--;
            st.upd(l, r);
        }else{
            int l, r; cin >> l >> r;
            l--; r--;
            auto ret = st.query(l, r);
            int ans = 0;
            rep(i, 0, 2) rep(j, 0, 2) ans = max(ans, ret.ans[i][j]);
            if(ans == r - l + 1) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}