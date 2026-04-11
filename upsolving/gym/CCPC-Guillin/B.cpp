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

void solve(){
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];   
    sort(all(a));
    sort(all(b));

    int dif = n - m;
    multiset<int> ms;
    rep(i, 0, dif) ms.insert(a[i]);

    vi need(m);
    rep(i, 0, m) need[i] = b[i] - a[dif + i];
    rep(i, 0, m) if(need[i] < 0){ cout << "-1\n"; return; }
    ll ops = accumulate(all(need), 0LL);
    if(ops > dif){ cout << "-1\n"; return; }

    vi ans;
    int idx = 0;
    rep(_, 0, dif){
        int l = *(ms.begin());
        int r = a[dif];
        if(ops == sz(ms)){
            while(idx < m && need[idx] == 0) idx++;

            ans.emplace_back(a[dif + idx]);
            a[dif + idx]++;
            need[idx]--;
            ops--;
            ms.erase(ms.begin());
        }else if(l == r){
            if(ops == 0){ cout << "-1\n"; return; }
            while(idx < m && need[idx] == 0) idx++;

            
            
            ans.emplace_back(a[dif + idx]);
            a[dif + idx]++;
            need[idx]--;
            ops--;
        }else{
            ans.emplace_back(l);
            ms.erase(ms.find(l));
            ms.insert(l + 1);
            ms.erase(ms.begin());
        }
    }

    cout << sz(ans) << "\n";
    rep(i, 0, sz(ans)) cout << ans[i] << " "; cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}