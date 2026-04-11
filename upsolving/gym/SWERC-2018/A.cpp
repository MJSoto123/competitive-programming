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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vi a(n + 1, 1);
    
    int k; cin >> k;
    vi b(k);
    for(int i = 0; i < k; i++) cin >> b[i];

    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < k; i++){
        for(int j = b[i]; j <= n; j += b[i]){
            if(a[j]) cnt++;
            else cnt--;
            a[j] ^= 1;
        }
        ans = max(ans, cnt);
    }

    cout << ans << "\n";
}