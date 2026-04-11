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

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int ones = count(s.begin(), s.end(), '1');
    if(ones <= k){ cout << "Alice\n"; return; }
    
    int d = 1e8;
    int mid = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') continue;
        if(abs(i - n / 2) < d){
            mid = i;
            d = abs(i - n / 2);
        }
    }

    if(mid < k && n - mid - 1 < k) cout << "Alice\n";
    else if(n / 2 < k && n - 1 - n / 2 < k) cout << "Alice\n";
    else cout << "Bob\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}