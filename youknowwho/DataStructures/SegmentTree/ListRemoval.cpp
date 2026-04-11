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

struct Seg{
    int n;
    vi t;
    void build(const vi &a, int v, int l, int r){
        if(l == r){
            t[v] = 1;
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void init(const vi &a){
        n = sz(a);
        t.assign(4 * n + 10, 0);
        build(a, 0, 0, n - 1);
    }

    void upd(int v, int l, int r, int pos){
        if(pos < l || pos > r) return;
        if(l == r){
            t[v] = 0;
            return;
        }

        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, pos);
        upd(2 * v + 2, mid + 1, r, pos);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void upd(int pos){ upd(0, 0, n - 1, pos); }

    int descend(int v, int l, int r, int val){
        if(l == r) return l;
        int mid = l + r >> 1;
        int ansl = t[2 * v + 1];
        if(ansl >= val) return descend(2 * v + 1, l, mid, val);
        else return descend(2 * v + 2, mid + 1, r, val - ansl);        
    }
    int descend(int val){ return descend(0, 0, n - 1, val); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    Seg st;
    st.init(a);

    rep(i, 0, n){
        int pos; cin >> pos;
        int id = st.descend(pos);
        cout << a[id] << " ";
        st.upd(id);
    }
    cout << "\n";
}