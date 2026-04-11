#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n; 
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int target = abs(a[0]);
    int need = (n - 1) / 2;
    int cnt = 0;
    for(int i = 1; i < n; i++) if(abs(a[i]) > target) cnt++;

    if(cnt >= need) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}