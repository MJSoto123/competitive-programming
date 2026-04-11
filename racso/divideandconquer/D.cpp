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

int c1, c2;
ll get(vi &a, int l, int r){
    int n = sz(a);
    if(n == 0) return c1;
    if(l + 1 == r) return 1LL * c2 * n;
    int mid = l + r >> 1;

    vi al, ar;
    rep(i, 0, n){
        if(a[i] < mid) al.emplace_back(a[i]);
        else ar.emplace_back(a[i]);
    }

    ll ret = 1LL * n * (r - l) * c2;
    ret = min(ret, get(al, l, mid) + get(ar, mid, r));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k >> c1 >> c2;
    vi a(k);
    rep(i, 0, k) cin >> a[i];
    sort(all(a));

    cout << get(a, 1, (1 << n) + 1) << "\n";
}