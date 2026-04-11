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

struct ST{
    int n;
    vi t;
    void build(const vi &a, int v, int l, int r){
        if(l == r){
            t[v] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = t[2 * v + 1] ^ t[2 * v + 2];
    }

    void init(const vi&a){
        n = sz(a);
        t.assign(4 * n + 5, 0);
        build(a, 0, 0, n - 1);
    }

    void update(int v, int l, int r, int pos, int val){
        if(pos < l || pos > r) return;
        if(l == r){
            t[v] = val;
            return;
        }
        int mid = l + r >> 1;
        update(2 * v + 1, l, mid, pos, val);
        update(2 * v + 2, mid + 1, r, pos, val);
        t[v] = t[2 * v + 1] ^ t[2 * v + 2];
    }
    void update(int pos, int val){ update(0, 0, n - 1, pos, val); }

    int query(int v, int l, int r, int pos){
        if(l == r) return 0;
        if(r < pos || l > pos) return 0;
        int mid = l + r >> 1;
        int winL = (t[2 * v + 1] >= t[2 * v + 2]);
        int len = mid - l + 1;
        int add = 0;
        if(!winL && l <= pos && pos <= mid) add += len;
        if(winL && mid + 1 <= pos && pos <= r) add += len;

        return 
        add + 
        query(2 * v + 1, l, mid, pos) + 
        query(2 * v + 2, mid + 1, r, pos);
    }
    int query(int pos){ return query(0, 0, n - 1, pos); }
};

void solve(){
    int n, q; cin >> n >> q;
    n = (1 << n);
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    ST seg; seg.init(a);
    rep(i, 0, q){
        int pos, val; cin >> pos >> val;
        pos--;
        seg.update(pos, val);
        cout << seg.query(pos) << "\n";
        seg.update(pos, a[pos]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}