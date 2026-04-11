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

    int n, k; cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    map<int, int> mp;
    auto add = [&](int x){
        mp[x]++;
    };

    auto del = [&](int x){
        mp[x]--;
        if(mp[x] == 0) mp.erase(mp.find(x));
    };

    rep(i, 0, n){
        add(a[i]);
        if(i >= k) del(a[i - k]);
        if(i >= k - 1) cout << sz(mp) << " ";
    }
    cout << "\n";
}