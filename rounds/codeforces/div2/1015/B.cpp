#include<bits/stdc++.h>
using namespace std;

inline long long gcd(long long a, long long b) { while (b != 0) swap(b, a %= b); return a; }

void solve(){
    int n; cin >> n;
    
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    long long mn = a[0];
    
    if(a[0] == a[1]) {cout << "Yes\n"; return;}
    
    long long g = 0;
    for(int i = 1; i < n; i++) if(a[i] % a[0] == 0) g = gcd(a[i], g);

    if(g == a[0]) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}