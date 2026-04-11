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

void solve(){
    int mn, mx; cin >> mn >> mx;
    int dif = mx - mn;

    string l = to_string(mn);
    string r = to_string(mx);

    auto f = [&](string s, string s2){
        int cnt = 0;
        for(int i = 0; i < s.size(); i++) if(s[i] == s2[i]) cnt++;
        return cnt;
    };

    int ans = 0;
    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());

    while(l.size() && l.back() == r.back()){
        l.pop_back();
        r.pop_back();
        ans += 2;
    }
    if(l.size() == 0){ cout << ans << "\n"; return; }
    
    int ld = l.back() - '0';
    int rd = r.back() - '0';
    if(rd - ld == 1){
        l.pop_back();
        r.pop_back();
        ans += 1;
        while(l.size() && l.back() == '9' && r.back() == '0'){
            l.pop_back();
            r.pop_back();
            ans += 1;
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}