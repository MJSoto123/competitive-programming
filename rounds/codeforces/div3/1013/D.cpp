#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    int l = 0, r = m + 1; 
    while(r - l > 1){
        int mid = l + r >> 1;
        int row = mid * (m / min(m, mid + 1)) + m % min(m, mid + 1);
        long long tot = 1LL * row * n;
        if(tot >= k) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}