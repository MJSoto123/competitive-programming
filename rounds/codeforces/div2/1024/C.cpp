#include<bits/stdc++.h>
using namespace std;

int get(vector<vector<int>> &a){
    int n = a.size();
    int sm = 0;
    for(int l1 = 0; l1 < n; l1++){
        for(int r1 = 0; r1 < n; r1++){
            for(int l2 = l1; l2 < n; l2++){
                for(int r2 = r1; r2 < n; r2++){
                    vector<int> now;
                    for(int i = l1; i <= l2; i++) {
                        for(int j = r1; j <= r2; j++){
                            now.emplace_back(a[i][j]);
                        }
                    }
                    sort(now.begin(), now.end());
                    int ans = -1;
                    for(int i = 0; i < now.size(); i++){
                        if(now[i] != i) break;
                        ans = i;
                    }
                    sm += ans + 1;
                }
            }
        }
    }

    return sm;
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    vector<vector<int>> v;
    for(int i = 0; i < n; i++){
        vector<int> now;
        for(int j = i * i; j < (i + 1) * (i + 1); j++) now.emplace_back(j);
        v.emplace_back(now);
    }
    
    for(int i = 0; i < (n / 2); i++) {
        vector<int> now = v.back(); v.pop_back();
        a[i][i] = now.back();
        now.pop_back();
        int sz = now.size() / 2;
        for(int j = i + 1; j <= i + sz; j++) { a[i][j] = now.back(); now.pop_back(); }
        for(int j = i + 1; j <= i + sz; j++) { a[j][i] = now.back(); now.pop_back(); }

        now = v.back(); v.pop_back();
        a[n - i - 1][n - i - 1] = now.back();
        now.pop_back();
        sz = now.size() / 2;
        for(int j = n - i - 2; j >= n - i - 1 - sz; j--) { a[n - i - 1][j] = now.back(); now.pop_back(); }
        for(int j = n - i - 2; j >= n - i - 1 - sz; j--) { a[j][n - i - 1] = now.back(); now.pop_back(); }
    }

    for(auto x : a){
        for(auto y : x) cout << y << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}