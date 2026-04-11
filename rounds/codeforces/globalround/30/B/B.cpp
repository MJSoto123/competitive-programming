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
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    vi even;
    rep(i, 0, n) if(a[i] % 2 == 0) even.emplace_back(a[i]);

    if(sz(even) >= 2){ cout << even[0] << " " << even[1] << "\n"; return; }
    if(sz(even) == 1){
        int ch = even[0];
        rep(i, 0, n){
            if(ch == a[i]) continue;
            if(a[i] < ch){
                if((ch % a[i]) % 2 == 0){ cout << a[i] << " " << ch << "\n"; return; }
            }else{
                if((a[i] % ch) % 2 == 0){ cout << ch << " " << a[i] << "\n"; return; }
            }
        }
    }

    rep(i, 0, n - 1){
        if(a[i] % 2 && a[i + 1] % 2){
            if((a[i + 1] % a[i]) % 2 == 0){ cout << a[i] << " " << a[i + 1] << "\n"; return; }
        }
    }

    assert(n < 1000);
    rep(i, 0, n){
            rep(j, i + 1, n){
                if((a[j] % a[i]) % 2 == 0){ cout << a[i] << " " << a[j] << "\n"; return; }
            }
    } 
   cout << "-1\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}