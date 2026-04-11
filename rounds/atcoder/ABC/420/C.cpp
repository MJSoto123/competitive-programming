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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll ans = 0;
    for(int i = 0; i < n; i++) ans += min(a[i], b[i]);

    for(int qq = 0; qq < q; qq++){
        char op; cin >> op;
        int pos, val; cin >> pos >> val;
        pos--;
        ans -= min(a[pos], b[pos]); 
        if(op == 'A') a[pos] = val;
        else b[pos] = val;
        ans += min(a[pos], b[pos]);
        cout << ans << "\n";
    }
}