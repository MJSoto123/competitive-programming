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
    vi ans;
    
    ll sm = 1LL * n * (n + 1) / 2;

    ll target = sm / 2;
    ll cur = 0;

    for(int i = n; i >= 1; i--){
        if(cur + i > target) break;
        cur += i;
        ans.emplace_back(i);
    }

    if(target != cur) ans.emplace_back(target - cur);

    cout << abs(sm - target * 2) << "\n";
    cout << sz(ans) << "\n";
    for(auto x : ans) cout << x << " "; cout << "\n";
}