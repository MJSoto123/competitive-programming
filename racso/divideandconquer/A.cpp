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

const int N = 1e6 + 10;
int a[N];
ll getmax(int l, int r){
    if(l + 1 == r) return a[l];
    int mid = l + r >> 1;
    ll ret = 0;

    int n = mid - l, m = r - mid;
    vi suf(n), pre(m);
    suf[n - 1] = a[mid - 1]; pre[0] = a[mid]; 
    for(int i = n - 2; i >= 0; i--) suf[i] = max(suf[i + 1], a[l + i]);
    rep(i, 1, m) pre[i] = max(pre[i - 1], a[mid + i]);

    ll sm = 0;
    int idx = m - 1;
    rep(i, 0, n){
        while(idx >= 0 && suf[i] < pre[idx]){ sm += pre[idx]; idx--; }
        ret += (1LL * (idx + 1) * suf[i] + sm);
    }
    ret += getmax(l, mid) + getmax(mid, r);
    return ret;
}

ll getmin(int l, int r){
    if(l + 1 == r) return a[l];
    int mid = l + r >> 1;
    ll ret = 0;

    int n = mid - l, m = r - mid;
    vi suf(n), pre(m);
    suf[n - 1] = a[mid - 1]; pre[0] = a[mid]; 
    for(int i = n - 2; i >= 0; i--) suf[i] = min(suf[i + 1], a[l + i]);
    rep(i, 1, m) pre[i] = min(pre[i - 1], a[mid + i]);

    ll sm = 0;
    int idx = m - 1;
    rep(i, 0, n){
        while(idx >= 0 && suf[i] > pre[idx]){ sm += pre[idx]; idx--; }
        ret += (1LL * (idx + 1) * suf[i] + sm);
    }
    ret += getmin(l, mid) + getmin(mid, r);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    ll mx = getmax(0, n);
    ll mn = getmin(0, n);
    cout << mx - mn << "\n";
}