#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i , a, b) for(int i = a ; i < (b); i++)
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int ,int> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> mp;
    vi dp(n + 1);

    for(int i = 0; i < n; i++){
        if(!mp.count(a[i])) mp[a[i]] = dp[i] + 1;
        mp[a[i]] = min(dp[i] + 1, mp[a[i]]);
        dp[i + 1] = min(dp[i] + 1, mp[a[i]]);
    }

    cout << dp[n] << "\n";
}