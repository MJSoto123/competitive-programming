#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vector<multiset<int>> pos(3);
    vii ans;
    rep(i, 0, n) pos[a[i]].emplace(i);

    int l = 0, r = n - 1;
    while(l < r){
        while(l < r && a[l] == 0){ pos[0].erase(pos[0].find(l)); l++; continue; }
        while(r > l && a[r] == 2){ pos[2].erase(pos[2].find(r)); r--; continue; }
        // cerr << a[l] << " " << a[r] << " l r " <<  l << " " << r << "\n";
        
        if(pos[0].empty() && pos[2].empty()) break;
        if(a[l] == 1 && sz(pos[0])){
            auto it = prev(pos[0].end());
            ans.emplace_back(l, *it);
            swap(a[l], a[*it]);
            pos[1].erase(pos[1].find(l));
            pos[1].insert(*it);
            pos[0].erase(it);
            l++;
            continue;
        }

        if(a[r] == 1 && sz(pos[2])){
            auto it = pos[2].begin();
            ans.emplace_back(r, *it);
            swap(a[r], a[*it]);
            pos[1].erase(pos[1].find(r));
            pos[1].insert(*it);
            pos[2].erase(it);
            r--;
            continue;
        }

        auto it = pos[1].begin();
        int p = *it;

        ans.emplace_back(l, p);
        swap(a[l], a[p]);
        pos[1].erase(it);
        pos[1].insert(l);

        pos[2].erase(pos[2].find(l));
        pos[2].insert(p);
    }

    cout << sz(ans) << "\n";
    for(auto [u, v] : ans) cout << u + 1 << " " << v + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}