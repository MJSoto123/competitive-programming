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
    int ori = k;
    if(k == 1 && n == 1){ cout << "YES\n"; cout << "1\n"; return; }
    if(k == 1){ cout << "NO\n"; return; }
    
    vvi ans;
    vi a(n);
    rep(i, 0, n) a[i] = i + 1;

    vvi ini;
    if(k % 2){
        ll tot = 1LL * k * n * (n + 1) / 2;
        if(tot % n){ cout << "NO\n"; return; }
        tot /= n;

        ll k2 = ((k - 3) / 2) * (n + 1);
        ll need = tot - k2;
        
        int fs = need - n - 1;
        vi b(n), c(n);
        rep(i, 0, n){
            if(fs + i <= n) b[i] = fs + i;
            else b[i] = fs + i - n;

            c[i] = need - a[i] - b[i];
        }
        if(a == b || b == c || c == a){ cout << "NO\n"; return; }

        ans.emplace_back(a);
        ans.emplace_back(b);
        ans.emplace_back(c);

        ini.emplace_back(a);
        ini.emplace_back(b);
        ini.emplace_back(c);

        k -= 3;
    }

    do{
        vi b(n);
        rep(i, 0, n) b[i] = n + 1 - a[i];

        
        bool ok = (a != b);
        for(auto p : ini) if(p == a || p == b) ok = false;
        if(ok){
            k -= 2;
            ans.emplace_back(a);
            ans.emplace_back(b);
        } 

        if(k == 0) break;
    }while(next_permutation(all(a)));

    vl sm(n);
    for(auto p : ans){
        rep(i, 0, n){
            if(p[i] < 1 || p[i] > n){ cout << "NO\n"; return; }
            sm[i] += p[i];
        }
    }

    if(count(all(sm), sm[0]) != n){ cout << "NO\n"; return; }
    
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    
    if(sz(ans) != ori){ cout << "NO\n"; return; }
    cout << "YES\n";
    for(auto p : ans){
        for(auto x : p) cout << x << " ";
        cout << "\n";
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}