#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vii a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;


    sort(a.begin(), a.end());
    vi dp(31);
    for(auto [l , r] : a){
        l++, r++;
        int prev = 0;
        for(int i = 0; i <= l; i++) prev = max(prev, dp[i]);
        dp[r] = max(dp[r], prev + 1);
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}