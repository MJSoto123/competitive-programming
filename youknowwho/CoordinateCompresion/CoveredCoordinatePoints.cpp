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
    vector<pair<ll, ll>> p(n);
    for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;

    vl a;
    for(auto [l, r] : p){
        a.emplace_back(l);
        a.emplace_back(r);
    }

    vl d = a;
    sort(all(d));
    d.resize(unique(all(d)) - d.begin());
    for(int i = 0; i < sz(a); i++){
        a[i] = lower_bound(all(d), a[i]) - d.begin();
    }

    
}