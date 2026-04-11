#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        a[i] = s.size();
    }

    int mx = *max_element(a.begin(), a.end());
    int mn = mx;
    int ans = 0;
    for(int w = mx; w <= 2500 * 80; w++){
        vector<vector<int>> b;
        int idx = 0;
        while(idx < n){
            vector<int> now;
            int sm = 0;
            while(idx < n && sm + a[idx] <= w){
                now.emplace_back(a[idx]);
                sm += a[idx]; sm++;
                idx++;
            }
            b.emplace_back(now);
        }
        int m = b.size();
        
        int add = INT_MAX;
        for(int i = 0; i < m - 1; i++){
            int sm = accumulate(b[i].begin(), b[i].end(), 0) + int(b[i].size()) - 1;
            int nxt = b[i + 1][0];
            int sobra = w - sm - 1;
            add = min(add, nxt - sobra);
        }
        
        if(ans >= m) continue;
        map<int, int> pre;
        for(int i = 0; i < m; i++){
            map<int, int> now;
            int sm = 0;
            for(int j = 0; j < b[i].size() - 1; j++){
                sm += b[i][j]; sm++;
                now[sm] = 1;
            }

            for(auto [pos, val] : now){
                if(pre.count(pos)) now[pos] = max(now[pos], pre[pos] + 1);
                if(pre.count(pos - 1)) now[pos] = max(now[pos], pre[pos - 1] + 1);
                if(pre.count(pos + 1)) now[pos] = max(now[pos], pre[pos + 1] + 1);
                if(now[pos] > ans){
                    mn = w;
                    ans = max(ans, now[pos]);
                }
            }
            pre = now;
        }
        cout << add << "\n";
        w += add - 1;
        if(ans >= n / 2) break;
    }
    cout << mn << ' ' << ans << '\n';
}