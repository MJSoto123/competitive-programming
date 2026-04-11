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

bool ok(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    auto pre = [&](vector<string> &x){
        map<char, int> mp;
        for(int i = 0; i < x.size(); i++){
            if(a[i].size() == 1 && ok(a[i][0])){
                int var = a[i][0];
                if(!mp.count(var)) mp[var] = i;
                a[i] = to_string(-(i - mp[var]) - 1);
            }
        }
    };
    vector<vector<string>> sufix(n);

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++) sufix[i].emplace_back(j);
        pre(sufix[i]);
    }
    sort(sufix.begin(), sufix.end());
    // cout << "a: ";
    // for(auto x : a) cout << x << " ";
    // cout << "\n";

    int qq; cin >> qq;
    while(qq--){
        int m; cin >> m;
        vector<string> b(m);
        for(int i = 0; i < m; i++) cin >> b[i];
        pre(b);

        int l = -1, r = m;
        while(r - l > 1) {
            int mid = (r + l) / 2;
            if(ok(mid)) r = mid;
            else l = mid;
        }

        if(ok(l)) cout << "yes\n";
        else cout << "no\n";
    }
}