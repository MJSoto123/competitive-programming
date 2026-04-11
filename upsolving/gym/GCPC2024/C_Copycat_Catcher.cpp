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

const int N = 1e6 + 100;
pair<int, int> trie[N][26];
int ct = 0;

void insert(const vl& s) {
    int node = 0;
    for (ll c : s) {
        int idx = (c < 0 ? -c - 1 : c % 26);
        if (!trie[node][idx].first)
            trie[node][idx].first = ++ct;
        trie[node][idx].second++;
        node = trie[node][idx].first;
    }
}

bool walk(const vl& p) {
    int node = 0;
    for (ll c : p) {
        int idx = (c < 0 ? -c - 1 : c % 26);
        if (!trie[node][idx].first)
            return false;
        node = trie[node][idx].first;
    }
    return true;
}

vl pre(const vl& s) {
    vl res(s.size());
    unordered_map<ll, ll> last;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] < 0) {
            auto [it, succ] = last.emplace(s[i], i);
            if (!succ)
                res[i] = i - it->second;
            it->second = i;
        } else
            res[i] = -s[i] - 1;
    }
    return res;
}

signed main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    unordered_map<string, ll> tokens;
    auto lookup = [&](const string& s) {
        auto [it, succ] = tokens.emplace(s, tokens.size());
        return s.size() == 1 && isalpha(s[0]) ? -it->second - 1 : it->second;
    };

    int n; cin >> n;
    vl pat(n);
    string aux;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        pat[i] = lookup(aux);
    }

    for (ll i = 0; i < pat.size(); i++){
        vl simple(pat.begin() + i, pat.begin() + pat.size());
        insert(pre(simple));
    }

    ll q;
    for (cin >> q; q-- > 0;) {
        int m; cin >> m;
        vl query(m);
        string tmp;
        for (int i = 0; i < m; i++) {
            cin >> tmp;
            query[i] = lookup(tmp);
        }
        vl simple(query.begin() + 0, query.begin() + query.size());
        cout << (walk(pre(simple)) ? "yes\n" : "no\n");
    }

    return 0;
}
