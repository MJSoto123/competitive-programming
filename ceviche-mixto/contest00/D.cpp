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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n; 
    vvi lens(n); 
    vii LR(n); 
    rep(i,0,n) { 
        int k; cin >> k; 
        cin >> LR[i].first >> LR[i].second; 
        lens[i].resize(k); 
        for(auto &l : lens[i]) cin >> l; 
    }

    vii L; 
    rep(i,0,n) { 
        int cur = LR[i].first; 
        for(auto l : lens[i]) { 
            cur += l; 
            L.emplace_back(cur, i); 
        }
    }

    sort(all(L)); 

    int first = 0; 
    rep(i,0,n) first = max(first, LR[i].first); 
    
    vvi R(n); 
    set<pii> s; 
    rep(i,0,n) { 
        int cur = LR[i].second; 
        s.emplace(cur, i);
        R[i].push_back(cur);  
        for(int j = sz(lens[i]) - 1; j >= 0; j--) { 
            cur -= lens[i][j]; 
            R[i].push_back(cur); 
            s.emplace(cur, i); 
        }
    }

    int ans = s.begin() -> first - first; 
    rep(i,0,sz(L)) { 
        auto [maxL, row] = L[i]; 
        int to_move = R[row].back(); 
        R[row].pop_back(); 
        s.erase({to_move, row}); 
        maxL = max(maxL, first); 
        ans = max(ans, s.begin() -> first - maxL); 
    }

    cout << max(ans, 0) << "\n"; 
}