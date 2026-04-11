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

const int N = 200'000 + 10;

void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    unordered_map<int, pair<int, int>> r0, r1;
    auto insert = [&](int op, int val, int d){
        if(op == 0){
            if(!r0.count(d)) r0[d] = {val, 1e9};
            else {
                auto [mn, mn2] = r0[d];
                if(val <= mn) r0[d] = {val, mn};
                else if(val <= mn2) r0[d] = {mn, val};
            }
        }else{
            if(!r1.count(d)) r1[d] = {val, 1e9};
            else {
                auto [mn, mn2] = r1[d];
                if(val <= mn) r1[d] = {val, mn};
                else if(val <= mn2) r1[d] = {mn, val};
            }
        }
    }

    rep(i, 0, n){
        for(int d = 1; d * d <= a[i]; d++){
            if(a[i] % d == 0){
                int other = a[i] / d;
                if(d != 1) insert(0, d, b[i]);
                if(other != 1 && other != d) insert(0, other, b[i]);
            }
        }

        for(int d = 1; d * d <= a[i] + 1; d++){
            if((a[i] + 1) % d == 0){
                int other = (a[i] + 1) / d;
                if(d != 1) r1.emplace_back(d);
                if(other != 1 && other != d) r1.emplace_back(other);
            }
        }
    }


    int ans = 2;
    for(auto [x, cnt] : r0){
        if(cnt >= 2) ans = min(ans, 0);
        if(cnt == 1 && cnt1.count(x)) ans = min(ans, 1); 
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}