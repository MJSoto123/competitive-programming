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

const ll inf = 1LL << 62; 
ll test(vl &d, vl &v, ll val) { 
    int n = sz(v); 
    d[0] = val; 
    rep(i,1,n) d[i] = v[i] - d[i - 1];  
    // cerr << "d: "; 
    // for(auto i : d) cerr << i << " "; cerr << "\n"; 
    ll mx = *max_element(all(d)), mn = *min_element(all(d)); 
    if(mn == 0) return mx; 
    vl mins(2, inf), maxs(2, -inf); 
    rep(i,0,n) { 
        if(mins[0] > mins.back()) swap(mins[0], mins[1]); 
        if(maxs[0] > maxs.back()) swap(maxs[0], maxs[1]); 
        if(d[i] < mins[1]) mins[1] = d[i]; 
        if(d[i] > maxs[0]) maxs[0] = d[i]; 
    }
    if(mins[0] > mins.back()) swap(mins[0], mins[1]); 
    if(maxs[0] > maxs.back()) swap(maxs[0], maxs[1]); 
    if(maxs[1] - mins[0] <= mins[1]) return maxs[1] + 1; 
    return maxs[1]; 
}

void solve() { 
    int n; cin >> n; 
    vl v(n); rep(i,0,n) cin >> v[i]; 
    if(n % 2) { 
        vl d(n); 
        d[0] = 0; 
        rep(i,1,n) d[i] = v[i] - d[i - 1]; 
        ll x = (v[0] - d.back()) / 2;
        cout << test(d, v, x) << "\n";  
    }else{ 
        vl d(n); 
        d[0] = 0; 
        rep(i,1,n) d[i] = v[i] - d[i - 1]; 
        ll L = 0, R = inf; 
        rep(i,0,n) { 
            if(i % 2) R = min(R, d[i]); 
            else L = max(L, -d[i]); 
        }
        // rep(i,L,R+1) { 
            // cerr << "i=" << i << " -> " << test(d, v, i) << "\n"; 
        // }
        while(R - L >= 5) { 
            ll mid = (L + R) / 2; 
            if(test(d, v, mid) > test(d, v, mid + 1)) L = mid; 
            else R = mid + 1; 
        }

        rep(i,L+1,R+1) if(test(d,v,L) > test(d,v,i)) L = i;
        cout << test(d,v,L) << "\n"; 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve(); 

}