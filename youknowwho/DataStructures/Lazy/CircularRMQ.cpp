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

ll inf = 2e18;
struct Seg{
    int n;
    vl t, lz;
    void build(const vi &a, int v, int l, int r){
        if(l == r){
            t[v] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }
    void init(const vi &a){
        n = sz(a);
        t.assign(4 * n + 10, inf);
        lz.assign(4 * n + 10, 0);
        build(a, 0, 0, n - 1);
    }

    void push(int v, int l, int r){
        if(lz[v] == 0) return;
        if(l != r){
            lz[2 * v + 1] += lz[v];
            lz[2 * v + 2] += lz[v];
        }
        t[v] += lz[v];
        lz[v] = 0;
    }

    void upd(int v, int l, int r, int lq, int rq, ll val){
        push(v, l, r);
        if(lq > r || l > rq) return;
        if(lq <= l && r <= rq){
            lz[v] += val;
            push(v, l , r);
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, lq, rq, val);
        upd(2 * v + 2, mid + 1, r, lq, rq, val);
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }
    void upd(int lq, int rq, ll val){ upd(0, 0, n - 1, lq, rq, val); }

    ll query(int v, int l, int r, int lq, int rq){
        push(v, l, r);
        if(lq > r || l > rq) return inf;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return min(
            query(2 * v + 1, l, mid, lq, rq),
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }

    ll query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    int q; cin >> q;
    cin.ignore();

    Seg st; st.init(a);
    rep(_, 0, q){
        string xd; getline(cin, xd);
        stringstream ss(xd);
        
        vl nums;
        ll aux;
        while(ss >> aux) nums.emplace_back(aux);
        int l = nums[0], r = nums[1];
        if(sz(nums) == 3){
            int val = nums[2];
            if(r < l){
                st.upd(0, r, val);
                st.upd(l, n - 1, val);
            }else st.upd(l, r, val);
        }else{
            if(r < l) cout << min(st.query(0, r), st.query(l, n - 1)) << "\n";
            else cout << st.query(l, r) << "\n";
        }   
    }
}