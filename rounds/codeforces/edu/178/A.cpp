#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c; cin >> a >> b >> c;
    int sm = a + b + c;

    if(sm % 3) { cout << "NO\n"; return;}
    sm /= 3;
    if(a > sm || b > sm) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}