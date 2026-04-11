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

struct st{
    int NIL = 0;
    int comb(int a, int b){ return max(a, b); }
    vi t;
    int n;
    st(int n) : n(n), t(2 * n + 5, NIL) {}

    void upd(int p, int v){
        p += n;
        for(t[p] = v; p > 1; p >>= 1) t[p >> 1] = comb(t[p], t[p ^ 1]);
    }

    int query(int l , int r){
        int res = NIL;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l & 1) res=  comb(res, t[l++]);
            if(r & 1) res = comb(res, t[--r]);
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

}