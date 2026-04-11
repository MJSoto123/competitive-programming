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
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vii a(n);
    for(int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
    a.emplace_back(0, -1);
    sort(a.begin(), a.end());
    
    int target; cin >> target;
    if(a.back().first != target) a.emplace_back(target, 1e9);

    n = a.size();
    vi dp(n + 1, 1e9);
    vi last(n + 1, 1e9);
    dp[0] = 0;

    map<int, int> ids;
    for(auto [w, id] : a) ids[w] = id;

    vi b;
    for(auto x : a) b.emplace_back(x.first);

    for(int j = 1; j < n; j++){
        auto [w, id] = a[j];
        if(w == 0) continue;
        int pos = lower_bound(b.begin(), b.end(), max(0, w - 1600)) - b.begin();

        int lastid = -1;
        int best = 1e9;
        for(int i = j - 1; i >= pos; i--){
            if(best > dp[i]){
                best = dp[i];
                lastid = i;
            }
        }

        dp[j] = best + 1;
        last[j] = lastid;
    }

    vi ans;
    int now = n - 1;
    while(last[now] != 0){
        ans.emplace_back(ids[b[last[now]]]);
        now = last[now];
    }

    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i != ans.size() - 1) cout << " ";
    }
    cout << "\n";
}