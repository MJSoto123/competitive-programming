#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(31);
    for(int bit = 0; bit < 31; bit++) if(k & (1 << bit)) a[bit]++;

    int sm = accumulate(a.begin(), a.end(), 0);
    if(k == 0){
        if(n == 1) cout << "-1\n";
        else if(n % 2) cout << 6 + (n - 3) << "\n";
        else cout << n << "\n";
        return;
    }

    if(sm == 1 && (k & 1) && n % 2 == 0){ 
        cout << 5 + (n - 2) << "\n";
        return;
    }

    if(sm >= n) { cout << k << "\n"; return; }
    cout << k + (n - sm + 1) / 2 * 2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}