#include<bits/stdc++.h>
using namespace std;

// U D L R
vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};
string mv = "v^><";
void solve(){
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(a[i][j] == 'E') q.emplace(i , j);
    }

    while(!q.empty()){
        auto [r, c] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] == '.') {
                a[nr][nc] = mv[i];
                q.emplace(nr, nc);
            }
        }
    }

    for(auto x : a) cout << x << "\n";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}