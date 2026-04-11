#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());

    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cnt++;
        if(a[i] * cnt >= k){
            cnt = 0;
            ans++;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}