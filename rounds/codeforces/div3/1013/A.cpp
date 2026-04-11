#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(10);
    int ans = 0;
    for(int i  = 0; i < n; i++){
        int x; cin >> x;
        a[x]++;
        if(a[0] >= 3 && a[1] >= 1 && a[2] >= 2 && a[3] >= 1 && a[5] >= 1 && ans == 0) ans = i + 1;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}