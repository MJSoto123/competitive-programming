#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<vector<int>> nxt(n + 1, vector<int> (k));

    for(int i = 0; i < k; i++) nxt[n][i] = n + 10;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < k; j++) nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i] - 'a'] = i;
    }

    vector<int> dp(n + 1, 1);
    int now = 1;
    set<int> vis;
    for(int i = n - 1; i >= 0; i--){
        if(vis.size() == k) {
            now++;
            vis.clear();
        }
        
        dp[i] = now;
        vis.insert(s[i] - 'a');
        // cout << s[i] << " " << now << "\n";
    }


    int q; cin >> q;
    for(int qq = 0; qq < q; qq++){
        string t; cin >> t;
        
        int pos = 0;
        for(auto x : t){
            pos = nxt[pos][x - 'a'] + 1;
            if (pos > n) break;
        }

        // cout << "pos " << pos << " => ";
        if(pos > n) cout << "0\n";
        else cout << dp[pos - 1] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}