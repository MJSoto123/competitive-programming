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
    
    vi d = a;
    sort(all(d));
    d.resize(unique(all(d)) - d.begin());
    rep(i, 0, n) a[i] = lower_bound(all(d), a[i]) - d.begin();
    vi cnt(sz(d) + 1);

    multiset<pii> ms;
    rep(i, 0, n){
        if(cnt[a[i]] != 0) ms.erase(ms.find({cnt[a[i]], -a[i]}));
        cnt[a[i]]++;
        ms.emplace(cnt[a[i]], -a[i]);

        if(i >= k){
            ms.erase(ms.find({cnt[a[i - k]], -a[i - k]}));
            cnt[a[i - k]]--;
            if(cnt[a[i - k]] != 0) ms.emplace(cnt[a[i - k]], -a[i - k]);
        }
        if(i >= k - 1) cout << d[-(ms.rbegin()->second)] << " ";
    }
    cout << "\n";
}