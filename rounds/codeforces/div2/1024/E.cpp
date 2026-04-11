#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> mx;
    vector<pair<int, int>> mn;

    for(int i = 0; i < n; i++) mn.emplace_back(a[i], i);
    for(int i = 0; i < n; i++) mx.emplace_back(a[i], i);

    sort(mx.rbegin(), mx.rend());
    sort(mx.rbegin(), mx.rend());
    // mas a la derecha mayor que k


    auto check = [&](int k){
        long long ans = 0;
        for(int i = k; i >= 1; i--){
            if(!mp.count(i) || mp[i].size() < 2) continue;
            ans += mp[i].back() - mp[i][0];
        }
        return ans;
    };

    int l = -1, r = n + 1;
    while(r - l > 1){
        int mid = l + r >> 1;
        if(check(mid) > check(mid + 1)) r = mid;
        else l = mid;
    }

    cout << check(l) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}