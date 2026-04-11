#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];

    vector<string> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> p(n);
    vector<vector<int>> rem(n);
    iota(p.begin(), p.end(), 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(b[i][j] == 'o') p[i] += a[j];
            else rem[i].emplace_back(a[j]);
        }
    }

    int mx = *max_element(p.begin(), p.end());
    int one = count(p.begin(), p.end(), mx);
    for(int i = 0; i < n; i++){
        if(mx == p[i] && one == 1) {cout << "0\n"; continue;}
        int need = mx + 1 - p[i];
        sort(rem[i].rbegin(), rem[i].rend());
        int ans = 0;
        for(int j = 0; j < int(rem.size()); j++) {
            if(need > 0) {
                need -= rem[i][j];
                ans++;
            }

            if(need <= 0) break;
        }
        cout << ans << "\n";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}