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
    int n, x, y; cin >> n >> x >> y;
    string s; cin >> s;
    vi p(n);
    rep(i, 0, n) cin >> p[i];

    ll need = accumulate(all(p), 0LL);
    if(need > x + y){ cout << "NO\n"; return; }

    vi a(n), b(n);
    rep(i, 0, n){
        if(s[i] == '0') a[i] = p[i] / 2 + 1;
        else b[i] = p[i] / 2 + 1;
    }
    ll sma = accumulate(all(a), 0LL);
    ll smb = accumulate(all(b), 0LL);
    int ze = count(all(s), '0');
    int on = n - ze;

    // cout << "a: ";
    // for(auto i : a) cout << i << " "; cout << "\n";
    // cout << "b: ";
    // for(auto i : b) cout << i << " "; cout << "\n";

    if(ze == n && x < y + n){ cout << "NO\n"; return; }
    if(on == n && y < x + n){ cout << "NO\n"; return; }
    if(sma > x || smb > y){ cout << "NO\n"; return; }
    
    for(int i = 0; i < n; i++) if(s[i] == '0'){
        a[i] += (x - sma);
        break;
    }

    for(int i = 0; i < n; i++) if(s[i] == '1'){
        b[i] += (y - smb);
        break;
    }
    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}