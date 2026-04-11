#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <bitset>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <climits>
#include <numeric>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <unordered_map>
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
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vi b = a;
    sort(b.begin(), b.end());
    map<int, multiset<int>> mp;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) continue;
        mp[a[i]].insert(i);
    }
    int ans = 0;

    for(int i = 0; i < n; i++){
        int ok = b[i];
        int curr = a[i];
        if(curr == ok) continue;
        else{
            ans++;
            int posok = *(mp[ok].begin());
            mp[ok].erase(mp[ok].find(posok));
            
            mp[curr].erase(mp[curr].find(i));
            if(b[posok] != curr) mp[curr].insert(posok);
            swap(a[i], a[posok]);
        }
    }

    cout << ans << "\n";
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}