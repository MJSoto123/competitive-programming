#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;

struct Node{
    int l, r, cnt;
    Node() : l(-1), r(-1), cnt(0) {}
    Node(char c){
        l = r = (c == '1');
        cnt = 0;
    }
    Node operator+(const Node &other) const {
        if(l == -1) return other;
        if(other.l == -1) return *this;
        Node ret;
        ret.l = l;
        ret.r = other.r;
        ret.cnt = cnt + other.cnt + (r == other.l);
        return ret;
    }
    void flip(){
        if(l == -1) return;
        l ^= 1;
        r ^= 1;
    }
};

Node NIL;

struct Seg{
    int n;
    vector<Node> t;
    void build(const string &s, int v, int l, int r){
        if(l == r){
            t[v] = Node(s[l]);
            return;
        }
        int mid = (l + r) >> 1;

        build(s, 2 * v + 1, l, mid);
        build(s, 2 * v + 2, mid + 1, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    void init(const string &s){
        n = sz(s);
        t.assign(4 * n + 10, NIL);
        build(s, 0, 0, n - 1);
    }

    void upd(int v, int l, int r, int lq, int rq){
        if(r < lq || rq < l) return;
        if(lq <= l && r <= rq){
            t[v].flip();
            return;
        }
        int mid = (l + r) >> 1;

        upd(2 * v + 1, l, mid, lq, rq);
        upd(2 * v + 2, mid + 1, r, lq, rq);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    void upd(int lq, int rq){ upd(0, 0, n - 1, lq, rq); }

    Node query(int v, int l, int r, int lq, int rq){
        if(r < lq || rq < l) return NIL;
        if(lq <= l && r <= rq) return t[v];
        int mid = (l + r) >> 1;
        
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

    Seg st;
    st.init(s);

    rep(i, 0, q){
        int op, l, r;
        cin >> op >> l >> r;
        l--, r--;

        if(op == 1) st.upd(l, r);
        else cout << (st.query(l, r).cnt == 0 ? "Yes\n" : "No\n");
    }
}