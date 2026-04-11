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

    string a, b; cin >> a >> b;
    if((a.size() + b.size()) % 2 == 0) cout << "MATCH\n";
    else cout << "NO MATCH\n";
}