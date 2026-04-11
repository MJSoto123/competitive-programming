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

    string s; cin >> s;
    int n = s.size();

    s += s;
    s.pop_back();
    int cnt = 1;
    int best = 0;
    for(int i = 1; i < s.size(); i++){
        if(s[i] != s[i - 1]) cnt++;
        else{
            best = max(best, cnt);
            cnt = 1;
        }
    }
    
    best = max(best, cnt);
    best = min(best, n);

    cout << best << "\n";
}