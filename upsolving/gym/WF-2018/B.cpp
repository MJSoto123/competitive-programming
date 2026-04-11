#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();

    vector<string> a;
    string s; 
    while (cin >> s){
        char x = s.back();
        if(x == '.' || x == ',') {
            s.pop_back();
            a.emplace_back(s);
            a.emplace_back(string(1, x));
        } else a.emplace_back(s);
    }

    // for(auto x : a) cout << x << " ";
    // cout << "\n";
    // cout << "\n";
    
    vector<string> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int n = b.size();
    
    map<string, int> mp;
    for(int i = 0; i < n; i++) mp[b[i]] = i;

    vector<vector<int>> g(2 * n + 10);
    // A, (0 , n)
    // ,B (n + 1, 2n)

    int m = a.size();
    for(int i = 0; i < m - 1; i++){
        if(a[i] == "." || a[i] == ",") continue;
        if(a[i + 1] == "." || a[i + 1] == ",") continue;
        g[mp[a[i]]].emplace_back(mp[a[i + 1]] + n);
        g[mp[a[i + 1]] + n].emplace_back(mp[a[i]]);
    }
    for(int u = 0; u < 2 * n; u++) {
        sort(g[u].begin(), g[u].end());
        g[u].erase(unique(g[u].begin(), g[u].end()), g[u].end());
    }

    vector<int> vis(2 * n + 10);
    // A , B
    for(int i = 0; i < m - 1; i++){
        if(a[i + 1] == ","){
            vis[mp[a[i]]] = 1;
            vis[mp[a[i + 2]] + n] = 1; // borrar?
        }
    }

    function<void(int)> dfs = [&](int u) {
        for(auto v : g[u]){
            if(vis[v] == 2) continue;
            vis[v] = 2;
            dfs(v);
        }
    };

    for(int u = 0; u < 2 * n; u++){
        if(vis[u] == 0) continue;
        if(vis[u] == 2) continue;
        vis[u] = 2;
        dfs(u);
    }

    // for(int i = 0; i < n; i++) cout << b[i] << ", " << vis[i] << "\n";
    // for(int i = n; i < 2 * n; i++) cout << ", " << b[i] << vis[i] << "\n";
    

    for(int i = 0; i < m - 1; i++){
        cout << a[i];
        if(a[i] == "." || a[i] == ",") { cout << " "; continue; }
        if(a[i + 1] == "." || a[i + 1] == ",") continue;
        if(vis[mp[a[i]]] == 2) cout << ",";
        cout << " ";
    }

    cout << ".\n";
}