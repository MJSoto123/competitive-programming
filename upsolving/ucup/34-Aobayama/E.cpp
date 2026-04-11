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
    int n; cin >> n;
    string s; cin >> s;
    
    int extra = 0;
    vi a;
    rep(i, 0, n){
        if(s[i] == '0') a.emplace_back(0);
        else{
            if(sz(a) && a.back()){ extra++; continue; }
            a.emplace_back(1);
        }
    }
    
    int m = sz(a);
    vi b;
    int ones = count(all(a), 1);
    int zeros = count(all(a), 0);
    int cur = 0;
    rep(i, 0, m){
        if(a[i]){ 
            b.emplace_back(cur);
            cur = 0;
        }
        else cur++;
    }
    if(cur) b.emplace_back(cur);

    cout << "b ";
    for(auto x : b) cout << x << " "; cout << "\n";
    cout << "zeros, ones " << zeros << " " << ones << "\n";

    if(ones == 0){ cout << 0 << "\n"; return; }
    if(ones == 1){
        int ans = extra;
        if(sz(b) == 2){
            int sobra = abs(b[0] - b[1]);
            ans += (zeros - sobra) / 2;
        }
        cout << "ans " << ans << "\n";
        return; 
    }

    if(ones == 2){
        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}