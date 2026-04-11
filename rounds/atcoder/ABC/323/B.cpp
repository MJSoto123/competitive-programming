#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<string> a(n);
    vector<pair<int, int>> b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) if(a[i][j] == 'o') b[i].first++;
        b[i].second = i + 1;
    }

    sort(b.begin(), b.end(), [&](pair<int, int> i, pair<int, int> j){
        if(i.first == j.first) return i.second < j.second;
        return i.first > j.first;
    });

    for(auto [x, y] : b) cout << y << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}