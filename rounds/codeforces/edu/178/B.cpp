#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n); 
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> mx(n);
    mx[0] = a[0];
    for(int i = 1; i < n; i++) mx[i] = max(mx[i - 1], a[i]);

    long long sm = 0;
    for(int i = n - 1; i >= 0; i--){
        cout << sm + mx[i] << " ";
        sm += a[i];
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}