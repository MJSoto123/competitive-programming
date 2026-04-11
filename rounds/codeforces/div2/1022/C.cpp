#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n; 
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b;
    b.emplace_back(a[0]);
    for(int i = 1; i < n; i++){
        if(a[i] != a[i - 1]) b.emplace_back(a[i]);
    }

    a = b;
    n = a.size();
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) mp[a[i]].emplace_back(i);

    vector<int> order = a;
    sort(order.begin(), order.end());
    order.erase(unique(order.begin(), order.end()), order.end());
    reverse(order.begin(), order.end());

    vector<int> vis(n);
    int ans = 0;
    
    function<void(int)> dfs = [&](int pos){
        vis[pos] = 1;
        if(pos - 1 >= 0) {
            if(!vis[pos - 1] && a[pos - 1] == a[pos]){
                vis[pos - 1] = 1;
                dfs(pos - 1);
            }
        }
        if(pos + 1 < n){
            if(!vis[pos + 1] && a[pos - 1] == a[pos]){
                vis[pos + 1] = 1;   
                dfs(pos + 1);
            }
        }
    };

    for(auto x : order){
        for(auto pos : mp[x]){
            if(vis[pos] == 0){
                bool ok = false;
                // l
                if(pos - 1 >= 0 && a[pos - 1] >= x && vis[pos - 1]) ok = true;

                // r
                if(pos + 1 < n && a[pos + 1] >= x && vis[pos + 1]) ok = true;

                if(!ok) ans++;
                dfs(pos);
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}