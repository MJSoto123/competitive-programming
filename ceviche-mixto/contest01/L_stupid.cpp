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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;
    
    vl info(n);
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'R') info[i] = 0;
        else info[i] = 1;
    }

    auto change = [&](ll ind, vl& ve) -> void {
        for (ll i = ind; i < ind+k; ++i) {
            ve[i] = ve[i] ^ 1;
        }
    };

    auto cnt = [&](vl& ve) -> ll {
        ll response = 1;
        for (ll i = 0; i+1 < n; ++i) {
            if (ve[i] != ve[i+1]) ++response;
        }
        return response;
    };

    ll valid = n - (k-1);

    ll response = 0;
    for (ll mask = 0; mask < (1ll<<valid); ++mask) {
        vl ga = info;
        ll limit = 0;
        for (ll b = 0; b < valid; ++b) {
            if ((mask>>b)&1) {
                change(b, ga);
                limit++;
            } 
        }

        if (limit <= m)
            response = max(response, cnt(ga));
    }

    cout << response << "\n";
}