#include<bits/stdc++.h>
using namespace std;

// L R U D
vector<int> dc = {-1, 1, 0, 0};
vector<int> dr = {0, 0, -1, 1};
void solve(){
    int n, m; cin >> n >> m;
    int q; cin >> q;

    vector<set<int>> row(n + 1), col(m + 1);

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++) row[r].insert(c);
    }

    for(int c = 1; c <= m; c++){
        for(int r = 1; r <= n; r++) col[c].insert(r);
    }

    for(int qq = 0; qq < q; qq++){
        int r, c; cin >> r >> c;
        if(row[r].count(c)){
            col[c].erase(r);
            row[r].erase(c);
            // cout << "fir " << r << " " << c << "\n";
            continue;
        }

        // L
        auto it = row[r].lower_bound(c);
        if(it != row[r].begin()){
            int now = *prev(it);
            row[r].erase(now);
            col[now].erase(r);
            // cout << "L " << r << " " << now << "\n";
        }
        
        // R
        it = row[r].upper_bound(c);
        if(it != row[r].end()){
            int now = *(it);
            row[r].erase(now);
            col[now].erase(r);
            // cout << "R " << r << " " << now << "\n";
        }

        // U
        it = col[c].lower_bound(r);
        if(it != col[c].begin()){
            int now = *prev(it);
            col[c].erase(now);
            row[now].erase(c);
            // cout << "U " << now << " " << c << "\n";
        }
        
        // D
        it = col[c].upper_bound(r);
        if(it != col[c].end()){
            int now = *(it);
            col[c].erase(now);
            row[now].erase(c);
            // cout << "D " << now << " " << c << "\n";
        }
        // cout << "\n";
    }

    int ans = 0;
    for(auto x : row) ans += x.size();
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}