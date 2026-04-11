#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    int now = n;
    for(int i = 1; i <= n; i++) a[i] = now--;

    int mx = 0;
    for(int i = 1; i <= n; i++) mx += abs(i - a[i]);

    cout << mx / 2  + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}