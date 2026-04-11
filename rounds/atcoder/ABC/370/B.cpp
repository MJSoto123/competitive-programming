#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<vector<int>> a(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++) cin >> a[i][j];
    }

    int i = 1;
    for(int j = 1; j <= n; j++){
        if(i >= j) i = a[i][j];
        else i = a[j][i];
    }

    cout << i << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}