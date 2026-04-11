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
    int ans, open, close;
    Node(int ans, int open, int close) : ans(ans), open(open), close(close) {}
    Node operator+(const Node &other){
        Node ret(0, 0, 0);
        int match = min(open, other.close);
        ret.ans = ans + other.ans + match;
        ret.open = open + other.open - match;
        ret.close = close + other.close - match;
        return ret;
    }
};

Node NIL(0, 0, 0);
struct Seg{
    int n;
    vector<Node> t;
    void build(const string &s, int v, int l, int r){
        if(l == r){
            t[v] = Node(0, s[l] == '(', s[l] == ')');
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
        build(s, 0, 0, n - 1);
    }

    Node query(int v, int l, int r, int lq, int rq){
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

    string s; cin >> s;
    int n = sz(s);
    int q; cin >> q;   
    Seg st;
    st.init(s);

    rep(_, 0, q){
        int l, r; cin >> l >> r;
        l--; r--;
        cout << 2 * st.query(l, r).ans << "\n";
    }
}