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

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<string> a;
    string now = "";
    rep(i, 0, n){
        now += s[i];
        if(i + 1 && (s[i] == '1' && s[i + 1] == '1') || (s[i] == '0' && s[i + 1] == '0')){
            a.emplace_back(now);
            now = "";
        }
    }
    if(sz(now)) a.emplace_back(now);
    rep(i, 0, sz(a)){
        int z = count(all(a[i]), '0');
        if(a[i][0] == '1' && a[i].back() == '1' && z % 2){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}