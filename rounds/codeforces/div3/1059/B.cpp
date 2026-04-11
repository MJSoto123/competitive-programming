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

bool ispal(string &s){
    int n = sz(s);
    rep(i, 0, n / 2) if(s[i] != s[n - 1 - i]) return false;
    return true;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;   

    rep(mask, 0, (1 << n)){
        string a = "";
        string b = "";
        rep(i, 0, n){
            if(mask & (1 << i)) a += s[i];
            else b += s[i];
        }
        if(ispal(b) && is_sorted(all(a))){
            cout << sz(a) << "\n";
            rep(i, 0, n){
                if(mask & (1 << i)) cout << i + 1 << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}