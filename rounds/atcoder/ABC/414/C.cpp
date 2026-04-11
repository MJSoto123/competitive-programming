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

ll get(string x){
    ll ret = 0;
    for(auto c : x){
        ret *= 10;
        ret += (c - '0');
    }
    return ret;
}

bool base(ll val, int b){
    vi dig;
    while(val){
        dig.emplace_back(val % b);
        val /= b;
    }

    for(int i = 0; i < dig.size() / 2; i++) if(dig[i] != dig[dig.size() - 1 - i]) return false;
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int b; ll n; cin >> b >> n;
    vl a;
    for(int i = 0; i < 1000000; i++){
        string s = to_string(i);
        string s1 = s;
        string s2 = s;
        s2.pop_back();
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        string t1 = s + s1;
        string t2 = s + s2;
        ll g1 = get(t1);
        ll g2 = get(t2);
        if(g1 <= n) a.emplace_back(g1);
        if(g2 <= n) a.emplace_back(g2);
    }

    long long ans = 0;
    for(auto x : a){
        if(base(x, b)) ans += x;
    }

    cout << ans << "\n";
}