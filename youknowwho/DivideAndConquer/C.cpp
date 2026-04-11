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
const int INF = 1e9;

struct Node{ 
    int x, y, z, w, id;
};

struct MN{
    int NIL = 1e9;
    int comb(int a, int b){ return min(a, b); }
    int n;
    vi t;
    MN(int n) : n(n), t(2 * n + 5, NIL) {}
    void upd(int p, int v){
        p += n;
        for(t[p] = v; p > 1; p >>= 1) t[p >> 1] = comb(t[p], t[p ^ 1]);
    }

    int query(int l, int r){
        int ret = NIL;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l & 1) ret = comb(ret, t[l++]);
            if(r & 1) ret = comb(ret, t[--r]);
        }
        return ret;
    }
};

const int N = 2e5 + 10;
Node a[N];
int bad[N];
MN seg(N);

void merge(int l, int r){
    if(r - l <= 1) return;
    int mid = l + r >> 1;
    merge(l, mid);
    merge(mid, r);
    
    vector<Node> tmp;
    int i = l, j = mid;
    while(i < mid && j < r){
        if(a[i].y < a[j].y){
            seg.upd(a[i].z, a[i].w);
            tmp.emplace_back(a[i++]);
        }
        else{
            int mn = seg.query(0, a[j].z);
            if(mn < a[j].w) bad[a[j].id] = 1;
            tmp.emplace_back(a[j++]);
        }
    }

    while(i < mid){
        seg.upd(a[i].z, a[i].w);
        tmp.emplace_back(a[i++]);
    }

    while(j < r){
        int mn = seg.query(0, a[j].z);
        if(mn < a[j].w) bad[a[j].id] = 1;
        tmp.emplace_back(a[j++]);
    }

    rep(k, 0, sz(tmp)) a[l + k] = tmp[k];
    rep(k, 0, sz(tmp)) seg.upd(tmp[k].z, INF);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    rep(i, 0, n) cin >> a[i].x >> a[i].y >> a[i].z >> a[i].w, a[i].id = i;

    sort(a, a + n, [&](Node i, Node j){
        return (i.x < j.x);
    });

    merge(0, n);
    cout << count(bad, bad + n, 0) << "\n";
}