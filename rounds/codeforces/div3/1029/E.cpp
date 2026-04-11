#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

void print(vi a, string s){
    cout << s << ": ";
    for(auto x : a) cout << x << " ";
    cout << "\n";
    cout << "\n";
}

void solve(){
    int n; cin >> n;
    vi a(n), b(n);

    for(int i = 0; i < n; i++){
        if(i % 2 == 0) cin >> a[i];
        else cin >> b[i];
    }

    for(int i = 0; i < n; i++){
        if(i % 2 == 0) cin >> b[i];
        else cin >> a[i];
    }

    // print(a, "A");
    // print(b, "B");
    
    int ans = 0;
    function<void()> go = [&](){
        map<int, int> la, lb;
        for(int i = 0; i < n; i++) la[a[i]] = i;
        for(int i = 0; i < n; i++) lb[b[i]] = i;
    
        for(int i = 0; i < n; i++){
            int lasta = (la.count(b[i]) ? la[b[i]] : -1);
            int lastb = (lb.count(b[i]) ? lb[b[i]] : -1);
            // cout << "\n" << lasta << " " << lastb << "\n";
            int now = 0;
            if(lasta >= i) now = i + 1;
            if(lasta < i) now = lasta + 1;
            if(lastb > i + 1) now = max(now, i + 1);
            ans = max(ans, now);
        }
    };
    go();
    swap(a, b);
    go();

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}