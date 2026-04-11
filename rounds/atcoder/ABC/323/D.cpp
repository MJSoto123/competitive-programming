#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<pair<long long, int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    map<long long, long long> mp;
    for(int i = 0; i < n; i++) mp[a[i].first] = a[i].second;

    priority_queue<long long, vector<long long>, greater<long long>> p;
    for(auto [val, cnt] : a) p.emplace(val);

    long long ans = 0;
    while(!p.empty()){
        long long x = p.top(); p.pop();
        long long cnt = mp[x];
        if(cnt == 0) continue;
        if(cnt & 1) ans++;
        mp[x * 2] += cnt / 2;
        mp.erase(mp.find(x));
        p.emplace(x * 2);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}