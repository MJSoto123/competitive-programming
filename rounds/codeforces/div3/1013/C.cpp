#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    if(n % 2 == 0){
        cout << "-1\n";
        return;
    }
    vector<int> a(n);
    int now = 0;
    for(int i = 0; i < n; i++){
        a[now] = i + 1;
        now += 2;
        now %= n;
    }

    for(auto x : a) cout << x << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}