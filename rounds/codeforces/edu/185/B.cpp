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

void solve(){
    ll n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    sort(all(a));
    ll id = 0;
    while(id < n && a[id] == 0) id++;
    ll sm = 0;
    rep(i, id, n) sm += (a[i] - 1);
    cout << n - id - max(n - 1 - sm, 0LL) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}