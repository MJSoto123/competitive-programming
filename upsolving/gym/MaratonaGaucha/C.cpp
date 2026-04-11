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

void print(vi a){
    for(auto x : a) cout << x << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vi pr(n);
    for(int i = 1; i < n; i++) pr[i] = i - 1;
    pr[0] = n - 1;
    
    vi nx(n);
    for(int i = 0; i < n - 1; i++) nx[i] = i + 1;
    nx[n - 1] = 0;
    
    vi b = a;
    int posmn = min_element(a.begin(), a.end()) - a.begin();
    int pos = posmn;
    for(int i = 0; i < n; i++){
        b[pos] = min(b[pr[pos]] + 1, b[pos]);
        pos = nx[pos];
    }
    // print(b);

    pos = posmn;
    for(int i = 0; i < n; i++){
        b[pos] = min(b[nx[pos]] + 1, b[pos]);
        pos = pr[pos];
    }
    // print(b);

    cout << *max_element(b.begin(), b.end()) << "\n";
}