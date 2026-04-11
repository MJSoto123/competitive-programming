#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a, b; cin >> a >> b;
    if(a ^ b == 0) cout << "Invalid\n";
    else if(a) cout << "Yes\n";
    else cout << "No\n"; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}