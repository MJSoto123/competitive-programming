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

    bool ok = true;
    if(n % 2) ok = false;
    rep(i, 0, n){
        int j = (i + n / 2) % n;
        if(a[i] == -1 && a[j] == -1){
            a[i] = a[j] = 1;
        }else if(a[i] == -1) a[i] = a[j];
        else if(a[j] == -1) a[j] = a[i];
        else{
            if(a[i] != a[j]) ok = false;
        }
    }
    if(!ok) cout << "NO\n";
    else{
        cout << "YES\n";
        for(auto x : a) cout << x << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();   
}