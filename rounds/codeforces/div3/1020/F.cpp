#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<vector<int>> dp(n + 1, vector<int> (2));
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == '0'){
            dp[i][0] += dp[i - 1][0] + i - 1;
            ans = max(ans, dp[i][0]);
            
            dp[i][1] += dp[i - 1][1] + n - (i);
            ans = max(ans, dp[i][1]);
        }else{
            dp[i][0] += dp[i - 1][1] + 1;
            ans = max(ans, dp[i][0]);
        }

    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}