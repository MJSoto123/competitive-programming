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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vi a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    int i = 0, j = 0;
    int cnti = 0, cntj = 0;
    ll ans = 0;
    int last = 1e9 + 100;
    while(i < n && j < m){
        if(a[i] == b[j]){
            last = a[i];
            cnti = cntj = 0;
            while(a[i] == last && i < n) cnti++, i++;
            while(b[j] == last && j < m) cntj++, j++;
            ans += 1LL * cnti * cntj;
        }else if(a[i] > b[j]) j++;
        else i++;
    }
    
    cout << ans << "\n";
}