#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, p, q; cin >> n >> m >> p >> q;
    if(n % p) cout << "YES\n";
    else {
        int dv = n / p;
        if(dv * q != m) cout << "NO\n";
        else cout << "YES\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}