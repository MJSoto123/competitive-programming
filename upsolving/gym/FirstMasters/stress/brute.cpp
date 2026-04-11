#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;

    map<string, int> mp;
    rep(len, 1, n + 1){
        rep(l, 0, n){
            int r = l + len - 1;
            if(r >= n) continue;
            string cur = "";
            rep(i, l, r + 1) cur += s[i];
            mp[cur]++;
        }
    }

    int mx = 0;
    string ans;
    for(auto [t, cnt] : mp){
        if(cnt > mx){
            mx = cnt;
            ans = t;
        }
        else if(cnt == mx && t.size() > ans.size()) ans = t;
    }

    cout << ans << "\n";
}