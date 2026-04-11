#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
using namespace ::std;
using ll = long long;
typedef vector<int>  vi;
typedef vector<ll>   vl;
typedef pair<int,int> pii;
void solve(){
    string a,b; cin >> a >> b;
    if(sz(string(a + b)) % 2) cout << "NO MATCH\n";
    else                      cout << "MATCH\n";
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int tt; cin >> tt;
    // while(tt--)
        solve();
}

