#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;

    if(k == 1){
        if(1600 <= n && n <= 2999) cout << "Yes\n";
        else cout << "No\n";
    }else{
        if(1200 <= n && n <= 2399) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}