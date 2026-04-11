#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    vi a(n + 1);
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r;
        l--; r--;
        a[l]++; a[r + 1]--;
    }

    for(int i = 1; i <= n; i++) a[i] += a[i - 1];
    for(int i = 0; i < n; i++){
        if(a[i] % 2) swap(s[i], t[i]);
    }
    cout << s << "\n";
}