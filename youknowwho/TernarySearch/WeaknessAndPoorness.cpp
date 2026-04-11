#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
using ld = double;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<ld> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ld> b = a;
    for(auto &x : b) x = (-x);
    
    auto kadane = [&](vector<ld> &v, ld x){
        ld ans = 0;
        ld sm = 0;
        for(int i = 0; i < n; i++){
            sm += (v[i] - x);
            ans = max(sm, ans);
            if(sm < 0) sm = 0;
        }
        return ans;
    };

    auto f = [&](ld x){
        return max(kadane(a, x), kadane(b, -x));
    };

    ld l = -1e5, r = 1e5;
    for(int i = 0; i < 100; i++){
        ld m1 = l + (r - l) / 3.0;
        ld m2 = r - (r - l) / 3.0;
        if(f(m1) < f(m2)) r = m2;
        else l = m1;
    }

    cout << fixed << setprecision(6);
    cout << f((l + r) / 2.0) << "\n";
}