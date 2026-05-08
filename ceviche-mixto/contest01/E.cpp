#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;

void solve() {
    ll n, j, k;
    cin >> n >> j >> k;

    vl a, b;
    vl c;
    while (n > 0) {
        c.push_back(n % 10);
        n /= 10;
    }
    sort(all(c));

    ll cur = 1;
    do {
        if (cur == j) a = c;
        if (cur == k) b = c;
        ++cur;
    } while (next_permutation(all(c)));

    ll cnt = ll(c.size());
    ll B = cnt;
    ll A = 0;
    for (ll i = 0; i < cnt; ++i) {
        if (a[i] == b[i]) {
            ++A;
            --B;
        }
    }

    cout << A << "A" << B << "B" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}