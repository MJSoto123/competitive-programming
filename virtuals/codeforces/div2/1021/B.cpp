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
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    sort(all(a));

    int L = a[n / 2], R = a[n / 2];
    if(n % 2 == 0) L = a[n / 2 - 1];

    rep(i, 0, k + 1){
        int len = (n - i);
        if(len % 2 == 0){
            int midl = (0 + len) / 2;
            L = min(L, a[midl - 1]);

            int midr = (n + (n - len)) / 2;
            R = max(R, a[midr]);
        }else{
            int midl = (0 + len) / 2;
            L = min(L, a[midl]);

            int midr = (n + (n - len)) / 2;
            R = max(R, a[midr]);
        }
    }

    cout << R - L + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}