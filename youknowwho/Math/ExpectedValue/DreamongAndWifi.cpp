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
    cout << fixed << setprecision(10);

    string a, b; cin >> a >> b;
    int n = sz(a);
    
    int need = 0;
    rep(i, 0, n){
        if(a[i] == '+') need++;
        else need--;
    }

    int bits = count(all(b), '?');
    vi bads;
    int cur = 0;
    rep(i, 0, n){
        if(b[i] == '+') cur++;
        else if(b[i] == '-') cur--;
        else bads.emplace_back(i);
    }

    if(bits == 0){
        if(need == cur) cout << 1 << "\n";
        else cout << 0 << "\n";
        return 0;
    }

    int tot = (1 << bits);
    int ans = 0;
    rep(mask, 0, (1 << bits)){
        int add = bits;
        rep(i, 0, bits) if(mask & (1 << i)) add -= 2;
        if(cur + add == need) ans++;
    }

    cout << 1.0 * ans / (1.0 * tot) << "\n";
}