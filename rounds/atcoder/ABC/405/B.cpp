#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> vis(m + 1);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) vis[a[i]]++;

    for(int i = 1; i <= m; i++) if(!vis[i]) return void(cout << "0\n");

    for(int i = 0; i < n; i++){
        int x = a.back();
        vis[x]--;
        if(vis[x] == 0) return void(cout << i + 1 << "\n");
        a.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}