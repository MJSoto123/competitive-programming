#include<bits/stdc++.h>
using namespace std;


const int inf = 1e9 + 100;
int main(){
    int n; cin >> n;
    int m = 1;
    for(int i = 0; i < n; i++) m *= 3;


    string s; cin >> s;
    vector<vector<int>> a(n + 1);
    for(auto x : s) a[0].emplace_back(x - '0');

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < a[i - 1].size(); j = j + 3){
            int val = (a[i - 1][j] + a[i - 1][j + 1] + a[i - 1][j + 2]) / 2;
            a[i].emplace_back(val);
        }
    }
    
    int res = a[n][0];

    vector<vector<int>> dp(n + 1);
    for(auto x : a[0]) {
        if(x == res) dp[0].emplace_back(1);
        else dp[0].emplace_back(inf);
    }


    for(int i = 1; i <= n; i++){
        for(int j = 0; j < a[i].size(); j++){
            if(a[i][j] == res) {
                int cnt = 0;
                vector<int> add;
                for(int k = j * 3; k < j * 3 + 3; k++) {
                    if(a[i - 1][k] == res){
                        cnt++;
                        add.emplace_back(dp[i - 1][k]);
                    }
                }
                sort(add.begin(), add.end());
                if(cnt == 2) dp[i].emplace_back(add[0]);
                else dp[i].emplace_back(add[0] + add[1]);
            }else {
                dp[i].emplace_back(inf);
            }
        }
    }

    cout << dp[n][0] << "\n";
}