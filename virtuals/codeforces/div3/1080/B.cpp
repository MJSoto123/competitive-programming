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
    
    vi vis(n);
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        int j = i + 1;
        vi b;
        while(j <= n){
            vis[j - 1] = 1;
            b.emplace_back(a[j - 1]);
            j *= 2;
        }
        sort(all(b));
        j = i + 1;
        int pos = 0;
        while(j <= n){
            a[j - 1] = b[pos];
            pos++;
            j *= 2;
        }
    }
    
    if(is_sorted(all(a))) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}