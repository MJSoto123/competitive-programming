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

const int N = 1e5 + 5;
int a[N];
int need;
void build(int l, int r){
    if(need == 0 || r - l <= 1) return;
    int mid = (l + r) / 2;

    vi tmp;
    rep(i, r - (mid - l), r) tmp.emplace_back(a[i]);
    rep(i, l, r - (mid - l)) tmp.emplace_back(a[i]);
    rep(i, 0, sz(tmp)) a[l + i] = tmp[i];
    need -= 2;
    if(need) build(l, mid);
    if(need) build(mid, r);
}

ll ops = 1;
void merge(int l, int r){
    if(r - l <= 1) return;
    bool ok = true;
    int mx = a[l];
    rep(i, l, r){
        if(a[i] < mx) ok = false;
        mx = max(mx, a[i]);
    }

    if(ok) return;
    int mid = l + r >> 1;
    ops += 2;
    merge(l, mid);
    merge(mid, r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    rep(i, 0, n) a[i] = i + 1;
    
    if(k % 2 == 0){ cout << "-1\n"; return 0; }

    need = k - 1;
    build(0, n);
    merge(0, n);

    if(ops != k){ cout << "-1\n"; return 0; }
    rep(i, 0, n) cout << a[i] << " \n"[i == n - 1];
}