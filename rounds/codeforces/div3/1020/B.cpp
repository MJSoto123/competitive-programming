#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < k; i++) cout << i << " ";
    for(int i = k + 1; i < n; i++) cout << i << " ";
    if(k != n) cout << k;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}