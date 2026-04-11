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
    int cnt, front, back;
    Node() : cnt(0), front(-1), back(-1) {}
    Node(char c) : cnt(0), front(c == '1'), back(c == '1') {}
    Node operator+(const Node &other) const {
        if(front == -1) return other;
        if(other.front == -1) return *this;
        Node ret;
        ret.cnt = cnt + other.cnt + (back == other.front);
        ret.front = front;
        ret.back = other.back;
        return ret;
    }
    void flip(){
        if(front == -1) return;
        front ^= 1;
        back  ^= 1;
    }
};

Node NIL;
struct Seg{
    int n;
    vector<Node> t;
    vi lz;
    void build(const string &s, int v, int l, int r){
        if(l == r){
            t[v] = Node(s[l]);
            return;
        }
        int mid = l + r >> 1;
        build(s, 2 * v + 1, l, mid);
        build(s, 2 * v + 2, mid + 1, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void init(const string &s){
        n = sz(s);
        t.assign(4 * n + 10, NIL);
        lz.assign(4 * n + 10, 0);
        build(s, 0, 0, n - 1);
    }

    void push(int v, int l, int r){
        if(lz[v] == 0) return;
        if(l != r){
            lz[2 * v + 1] ^= lz[v];
            lz[2 * v + 2] ^= lz[v];
        }
        t[v].flip();
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
    
    rep(i, 0, q){
        int op, l, r; cin >> op >> l >> r;
        l--; r--;
        if(op == 1) st.upd(l, r);
        else {
            if(st.query(l, r).cnt) cout << "No\n";
            else cout << "Yes\n";
        }
    }
}