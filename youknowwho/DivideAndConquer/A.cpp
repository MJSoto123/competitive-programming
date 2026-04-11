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

const int N = 2e5 + 10;
int a[N];

ll ans = 0;
void merge(int l, int r){
    if(r - l <= 1) return;
    int mid = l + r >> 1;
    merge(l, mid);
    merge(mid, r);

    vi tmp;
    int i = l, j = mid;
    while(i < mid && j < r){
        if(a[i] <= a[j]) tmp.emplace_back(a[i++]);
        else{
            ans += (mid - i);
            tmp.emplace_back(a[j++]);
        }
    }

    while(i < mid) tmp.emplace_back(a[i++]);
    while(j < r) tmp.emplace_back(a[j++]);
    rep(i, 0, sz(tmp)) a[l + i] = tmp[i];
}

void solve(){
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    ans = 0;
    merge(0, n);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();

}