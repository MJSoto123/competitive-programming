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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int ze = count(all(s), '0');
    int on = count(all(s), '1');
    int tw = k - ze - on;
    
    vector<char> ans(n, '+');
    rep(i, 0, ze) ans[i] = '-';
    rep(i, 0, on) ans[n - i - 1] = '-';
    rep(i, 0, tw) ans[i + ze] = '?';
    rep(i, 0, tw) ans[n - i - 1 - on] = '?';
    
    if(tw + ze + on == n) ans = vector<char> (n, '-'); 
    rep(i, 0, n) cout << ans[i];
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}