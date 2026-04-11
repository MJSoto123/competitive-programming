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
    int n, k; cin >> n >> k;
    string s,t; cin >> s >> t;

    vvi pos(26);
    rep(i, 0, n) pos[s[i] - 'a'].emplace_back(i);

    vi ch(n);
    int last = 1e9;
    for(int i = n - 1; i >= 0; i--){
        last = min(last, i);
        int need = t[i] - 'a';
        int l = -1, r = sz(pos[need]);

        while(r - l > 1){
            int mid = l + r >> 1;
            if(pos[need][mid] <= last) l = mid;
            else r = mid;
        }

        if(l == -1){ cout << "-1\n"; return; }
        last = min(last, pos[need][l]);
        ch[i] = pos[need][l];
    }

    // rep(i, 0, n) cerr << ch[i] << " "; cerr << "\n";
    rep(i, 0, n) if(i - ch[i] > k){ cout << "-1\n"; return; }
    
    vi a(n);
    rep(i, 0, n) a[ch[i]] = max(a[ch[i]], i - ch[i]);
    
    vector<string> ans;
    rep(i, 0, k){
        if(s == t) break;
        // rep(j, 0, n) cerr << a[j] << " "; cerr << "\n";
        string cur = s;
        for(int j = n - 1; j >= 0; j--){
            if(a[j]){
                cur[j + 1] = s[j];
                a[j + 1] = a[j] - 1;
                a[j] = 0;
            }
        }
        ans.emplace_back(cur);
        s = cur;
    }

    cout << sz(ans) << "\n";
    for(auto x : ans) cout << x << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}