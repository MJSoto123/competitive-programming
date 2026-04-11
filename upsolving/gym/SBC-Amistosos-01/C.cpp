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
    vii a(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            int x; cin >> x;
            a[i].first += x;
            a[i].second = i;
        }
    }

    sort(a.begin(), a.end(), [&](pii i, pii j){
        if(i.first != j.first) return i.first > j.first;
        return i.second < j.second;
    });
    
    for(int i = 0; i < n; i++) if(a[i].second == 0) cout << i + 1 << "\n";

}