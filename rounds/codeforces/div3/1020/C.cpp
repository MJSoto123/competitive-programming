#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int ones = count(b.begin(), b.end(), -1);
    int sm = -1;
    for(int i = 0; i < n; i++) if(b[i] != -1) {sm = a[i] + b[i]; break;}

    if(ones != n){
        for(int i = 0; i < n; i++){
            if(b[i] != -1 && a[i] + b[i] != sm || a[i] > sm || a[i] + k < sm) {cout << "0\n"; return;}
        }

        cout << 1 << "\n";
        return;
    }

    int mn = *min_element(a.begin(), a.end()) + k;
    int mx = *max_element(a.begin(), a.end());
    cout << max(mn - mx + 1, 0) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}